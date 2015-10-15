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
    _ranks(),
    _max_row(13),
    _max_col(6),
    _orb_stamina(_max_col),
    _orb_probability(_max_row)
{
    ui->setupUi(this) ;
    _abilities = new ability_selector() ;
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
    _initialized = true ;
}

/**
 * Destructor
 */
ffrk_abilities::~ffrk_abilities()
{
    for(int i=0; i<13; ++i) {
        delete _orbs[i] ;
    }
    delete _orbs ;
    if( _abilities ) {
        delete _abilities ;
        _abilities = 0 ;
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
    e->accept() ;
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
                if( 0 < r ) {
                    value -= _ranks.num_orbs(s,r) ;
                }
                _orbs[row][column] += (multiplier * value) ;
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
 * Adds another ability row to the table
 */
void ffrk_abilities::on_addRow_button_clicked()
{
    ui->ability_table->insertRow( ui->ability_table->rowCount() ) ;
    std::cout << ui->ability_table << std::endl ;
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
                    std::cout << typeid(curr).name() << std::endl ;
                    curr->setAbility( a ) ;
                    curr->setText( a->_name.c_str() ) ;
                }
            }
            break ;
        default:
            break ;
    }
}
