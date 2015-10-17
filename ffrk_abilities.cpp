#include "ffrk_abilities.h"
#include "ui_ffrk_abilities.h"

/**
 * Constructor
 */
ffrk_abilities::ffrk_abilities(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ffrk_abilities),
    _settings("Tibonium Inc.", "FFRK Ability Orb Calculator"),
    _abilities(0),
    _filepath(),
    _initialized(false),
    _stash_table(0),
    _ranks(),
    _max_row(13),
    _max_col(6),
    _orb_stamina(_max_col),
    _orb_probability(_max_row)
{
    ui->setupUi(this) ;
    _abilities = new ability_selector() ;
    _stash_table = new orb_stash_table() ;
    _stash_table->add_listener(this) ;
    std::fstream file("ffrk_ability_config") ;
    std::getline(file, _filepath) ;
    on_ability_button_pressed() ;
    _orbs = new int*[_max_row] ;
    for(int i=0; i<_max_row; ++i) {
        _orbs[i] = new int[_max_col] ;
    }
    setup_orb_table() ;
    ui->orb_table->verticalHeader()->setHidden(false) ;
    on_prob_button_clicked() ;
    read_settings() ;
    load_table() ;
    update_orb_table() ;
    _initialized = true ;
}

/**
 * Destructor
 */
ffrk_abilities::~ffrk_abilities()
{
    for(int i=0; i<_max_row; ++i) {
        delete _orbs[i] ;
    }
    delete _orbs ;
    if( _abilities ) {
        delete _abilities ;
        _abilities = 0 ;
    }
    if( _stash_table ) {
        delete _stash_table ;
        _stash_table = 0 ;
    }
    delete ui ;
}

/**
 * Adds persistence to application sessions on position and size
 */
void ffrk_abilities::closeEvent(QCloseEvent *e)
{
    _settings.setValue("position", pos()) ;
    _settings.setValue("size", size()) ;
    save_table() ;
    e->accept() ;
}

/**
 * Saves the current table for persistence.
 */
void ffrk_abilities::save_table()
{
    std::fstream of("ability_table", std::fstream::out) ;
    if( !of.good() ) {
        QMessageBox msg ;
        msg.setWindowTitle("Error saving table data") ;
        msg.setText( std::strerror(errno) ) ;
        msg.exec() ;
    }
    int count( ui->ability_table->rowCount() ) ;
    for(int i=0; i<count; ++i) {
        std::string line = ui->ability_table->item(i, ability_table_item::NAME)->text().toLatin1().data() ;
        line += "," ;
        line += ui->ability_table->item(i, ability_table_item::RANK)->text().toLatin1().data() ;
        line += "," ;
        line += ui->ability_table->item(i, ability_table_item::HONE)->text().toLatin1().data() ;
        line += "," ;
        line += ui->ability_table->item(i, ability_table_item::COUNT)->text().toLatin1().data() ;
        line += "\n" ;
        of << line ;
    }
    of.close() ;
}

/**
 * Loads existing table data, if it exists
 */
void ffrk_abilities::load_table()
{
    std::fstream fi("ability_table", std::fstream::in) ;
    if( !fi.good() ) {
//        QMessageBox msg ;
//        msg.setWindowTitle("Error loading table data") ;
//        msg.setText( std::strerror(errno) ) ;
//        msg.exec() ;
        return ;
    }
    while( true ) {
        std::string line ;
        std::getline(fi, line) ;
        if( fi.eof() ) break ;
        std::stringstream iss ;
        iss << line ;
        std::string name, rank, hone, count ;
        std::getline(iss, name, ',') ;
        std::getline(iss, rank, ',') ;
        std::getline(iss, hone, ',') ;
        std::getline(iss, count, ',') ;
        ability_base* a = _abilities->find_ability(name) ;
        if( a ) {
            on_addRow_button_clicked() ;
            int row = ui->ability_table->rowCount() - 1 ;
            reinterpret_cast<ability_table_item*>(ui->ability_table->item(row, ability_table_item::NAME))->setAbility(a) ;
            ui->ability_table->item(row, ability_table_item::NAME)->setText( name.c_str() ) ;
            ui->ability_table->item(row, ability_table_item::RANK)->setText( rank.c_str() ) ;
            ui->ability_table->item(row, ability_table_item::HONE)->setText( hone.c_str() ) ;
            ui->ability_table->item(row, ability_table_item::COUNT)->setText( count.c_str() ) ;
        }
    }
    fi.close() ;
}

/**
 * Restores Position and Size of application from previous session
 */
void ffrk_abilities::read_settings()
{
    if( _settings.contains("position") )
        move( _settings.value("position").toPoint() ) ;
    if( _settings.contains("size") )
        resize( _settings.value("size").toSize() ) ;
}

/**
 * Initializes all of the table cells for the orbs
 */
void ffrk_abilities::setup_orb_table()
{
    for(int i=0; i<_max_row; ++i) {
        for(int j=0; j<_max_col; ++j) {
            ui->orb_table->setItem(i, j, new QTableWidgetItem()) ;
            _orbs[i][j] = 0 ;
        }
    }
}

/**
 * Updates the estimated amount of stamina needed to obtain all orbs
 * computed from the provided <orb_statistics> file
 */
void ffrk_abilities::update_stamina_cost()
{
    if( _initialized ) {
        double stam = 0 ;
        for(int i=0; i<_max_row; ++i) {
            if( _orb_probability[i] <= 0 ) continue ;
            for(int j=0; j<_max_col; ++j) {
                double tmp = _orbs[i][j] ;
                tmp *= _orb_stamina[j] ;
                tmp /= _orb_probability[i] ;
                stam += tmp ;
            }
        }
        std::string tmp("Stamina needed (est.): ") ;
        std::stringstream oss ;
        oss << stam ;
        tmp += oss.str() ;
        ui->stamina_cost->setText( tmp.c_str() ) ;
    }
}

/**
 * Callback when the Ability Table Items have been changed.
 */
void ffrk_abilities::on_ability_table_cellChanged(int row, int column)
{
    QTableWidgetItem* curr = ui->ability_table->item(row, column) ;
    switch(column) {
        case ability_table_item::RANK:
            {
                int r = curr->text().toInt() ;
                if( r < 0 ) {
                    curr->setText( QString::number(0) ) ;
                } else
                if( 5 < r ) {
                    curr->setText( QString::number(5) ) ;
                }
            }
            break ;
        case ability_table_item::HONE:
            {
                int h = curr->text().toInt() ;
                if( h < 0 ) {
                    curr->setText( QString::number(0) ) ;
                } else
                if( 5 < h ) {
                    curr->setText( QString::number(5) ) ;
                }
            }
            break ;
        case ability_table_item::COUNT:
            {
                int c = curr->text().toInt() ;
                if( c < 0 ) {
                    curr->setText( QString::number(0) ) ;
                }
            }
            break ;
        default:
            break ;
    }

    if( _initialized ) {
        update_orb_table() ;
    }
}

/**
 * Updates the number of each type of orb that is need cumulatively for
 * the abilities with non-zero rank and count.
 */
void ffrk_abilities::update_orb_table()
{
    typedef std::list<orb_rarity>       rarity_list ;
    typedef std::list<orb_type>         orb_list ;
    typedef std::list<rank_type>        rank_list ;
    for(int i=0; i<_max_row; ++i) {
        for(int j=0; j<_max_col; ++j) {
            _orbs[i][j] = 0 ;
        }
    }
    int size( ui->ability_table->rowCount() ) ;
    for(int i=0; i<size; ++i) {
        int multiplier = ui->ability_table->item(i, ability_table_item::COUNT)->text().toInt() ;
        if( 0 < multiplier ) {
            ability_base* _curr = reinterpret_cast<ability_table_item*>(ui->ability_table->item(i, ability_table_item::NAME))->getAbility() ;
            rarity_list::iterator rare = _curr->_rare.begin() ;
            rarity_list::iterator rare_end = _curr->_rare.end() ;
            orb_list::iterator types = _curr->_types.begin() ;
            orb_list::iterator types_end = _curr->_types.end() ;
            rank_list::iterator count = _curr->_counts.begin() ;
            rank_list::iterator count_end = _curr->_counts.end() ;
            while( (rare != rare_end) && (types != types_end) && (count != count_end) ) {
                int row = orb_type(*types) ;
                int column = *rare ;
                int s = int(*count) ;
                int r = ui->ability_table->item(i, ability_table_item::RANK)->text().toInt() - 1 ;
                int rh = ui->ability_table->item(i, ability_table_item::HONE)->text().toInt() - 1 ;
                int value = _ranks.num_orbs(s,rh) ;
                if( -1 < r ) {
                    value -= _ranks.num_orbs(s,r) ;
                }
                value *= multiplier ;
                value -= _stash_table->stash_count(row, column) ;
                if( value < 0 ) {
                    value = 0 ;
                }
                _orbs[row][column] += value ;
                rare++ ;
                types++ ;
                count++ ;
            }
        }
    }
    for(int i=0; i<_max_row; ++i) {
        for(int j=0; j<_max_col; ++j) {
            int value = _orbs[i][j] ;
            if( value == 0 ) {
                ui->orb_table->item(i, j)->setText( QString() ) ;
            } else {
                ui->orb_table->item(i, j)->setText( QString::number(value) ) ;
            }
        }
    }
    update_stamina_cost() ;
}

/**
 * Used during the callback fromt he stash, to reduce amount of effort
 * in updating the table values when data is updated.
 */
void ffrk_abilities::update_orb_cell(int type, int rank)
{
    typedef std::list<orb_rarity>       rarity_list ;
    typedef std::list<orb_type>         orb_list ;
    typedef std::list<rank_type>        rank_list ;

    // Reset only the one cell that were interested in
    _orbs[type][rank] = 0 ;

    int size( ui->ability_table->rowCount() ) ;
    for(int i=0; i<size; ++i) {
        int multiplier = ui->ability_table->item(i, ability_table_item::COUNT)->text().toInt() ;
        if( 0 < multiplier ) {
            ability_base* _curr = reinterpret_cast<ability_table_item*>(ui->ability_table->item(i, ability_table_item::NAME))->getAbility() ;
            rarity_list::iterator rare = _curr->_rare.begin() ;
            rarity_list::iterator rare_end = _curr->_rare.end() ;
            orb_list::iterator types = _curr->_types.begin() ;
            orb_list::iterator types_end = _curr->_types.end() ;
            rank_list::iterator count = _curr->_counts.begin() ;
            rank_list::iterator count_end = _curr->_counts.end() ;
            while( (rare != rare_end) && (types != types_end) && (count != count_end) ) {
                int row = orb_type(*types) ;
                if( row == type ) {
                    int column = *rare ;
                    if( column == rank ) {
                        int s = int(*count) ;
                        int r = ui->ability_table->item(i, ability_table_item::RANK)->text().toInt() - 1 ;
                        int rh = ui->ability_table->item(i, ability_table_item::HONE)->text().toInt() - 1 ;
                        int value = _ranks.num_orbs(s,rh) ;
                        if( -1 < r ) {
                            value -= _ranks.num_orbs(s,r) ;
                        }
                        value *= multiplier ;
                        value -= _stash_table->stash_count(row, column) ;
                        if( value < 0 ) {
                            value = 0 ;
                        }
                        _orbs[row][column] += value ;
                    }
                }
                rare++ ;
                types++ ;
                count++ ;
            }
        }
    }
    int value = _orbs[type][rank] ;
    if( value == 0 ) {
        ui->orb_table->item(type, rank)->setText( QString() ) ;
    } else {
        ui->orb_table->item(type, rank)->setText( QString::number(value) ) ;
    }
    update_stamina_cost() ;
}

/**
 * Adds another ability row to the table
 */
void ffrk_abilities::on_addRow_button_clicked()
{
    ui->ability_table->insertRow( ui->ability_table->rowCount() ) ;
    int curr_row = ui->ability_table->rowCount() - 1 ;
    ui->ability_table->setItem(curr_row, ability_table_item::COUNT, new QTableWidgetItem(QString("0")) ) ;
    ui->ability_table->setItem(curr_row, ability_table_item::HONE, new QTableWidgetItem(QString("0")) ) ;
    ui->ability_table->setItem(curr_row, ability_table_item::RANK, new QTableWidgetItem(QString("0")) ) ;
    ability_table_item *name = new ability_table_item() ;
    ui->ability_table->setItem(curr_row, ability_table_item::NAME, name ) ;
}

/**
 * Removes a row from the table
 */
void ffrk_abilities::on_removeRow_button_clicked()
{
    int row = ui->ability_table->currentRow() ;
    ui->ability_table->removeRow( row ) ;
}

/**
 * Loads the probability and stamina tables
 */
void ffrk_abilities::on_prob_button_clicked()
{
    orb_statistics_parser os ;
    std::string t = _filepath ;
    t += "orb_statistics" ;
    os.parse_file( t.c_str() ) ;
    _orb_stamina = os.stamina() ;
    _orb_probability = os.probability() ;
    QColor color ;
    for(int i=0; i<_max_row; ++i) {
        if( _orb_probability[i] > 0 ) {
            color = Qt::green ;
        } else {
            color = Qt::white ;
        }
        for(int j=0; j<_max_col; ++j) {
            ui->orb_table->item(i,j)->setBackgroundColor(color) ;
        }
    }
    update_stamina_cost() ;
}

/**
 * Reloads the abilities into the table
 */
void ffrk_abilities::on_ability_button_pressed()
{
    if( _abilities ) {
        delete _abilities ;
    }
    _abilities = new ability_selector() ;
}

/**
 * Opens the ability_selector
 */
void ffrk_abilities::on_ability_table_doubleClicked(const QModelIndex &index)
{
    int row = index.row() ;
    int col = index.column() ;
    switch( col ) {
        case ability_table_item::NAME:
            {
                _abilities->choose_ability() ;
                while( _abilities->isVisible() ) {
                    QApplication::processEvents() ;
                }
                ability_base *a = _abilities->result() ;
                if( a != 0 ) {
                    ability_table_item *curr = reinterpret_cast<ability_table_item*>(ui->ability_table->item(row, col)) ;
                    curr->setAbility( a ) ;
                    curr->setText( a->_name.c_str() ) ;
                }
            }
            break ;
        default:
            break ;
    }
}

/**
 * Displays the Orb stash table
 */
void ffrk_abilities::on_show_stash_clicked()
{
    _stash_table->unhide() ;
}
