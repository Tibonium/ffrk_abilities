#include "ffrk_abilities.h"
#include "ui_ffrk_abilities.h"

/**
 * Constructor
 */
ffrk_abilities::ffrk_abilities(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ffrk_abilities),
    _settings("Tibonium Inc.", "FFRK Ability Orb Calculator"),
    _initialized(false),
    _ability_count(0),
    _ranks(),
    _class_filter(0),
    _rarity_filter(0),
    _orb_filter(0),
    _max_row(13),
    _max_col(6),
    _orb_stamina(_max_col),
    _orb_probability(_max_row)
{
    ui->setupUi(this) ;
    on_ability_button_pressed() ;
    _orbs = new int*[_max_row] ;
    for(int i=0; i<_max_row; ++i) {
        _orbs[i] = new int[_max_col] ;
    }
    setup_orb_table() ;
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
    delete ui;
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
 * Reloads the abilities into the table
 */
void ffrk_abilities::on_ability_button_pressed()
{
    // Clear the table first
    ui->ability_table->setRowCount( 0 ) ;

    // Setup the parser
    spell_parser p ;

    p.parse_file("../../ffrk_abilities/spells/black_magic") ;
    _black = p.abilities() ;
    _ability_count = _black.size() ;
    _ability_list.push_back( _black ) ;

    p.parse_file("../../ffrk_abilities/spells/white_magic") ;
    _white = p.abilities() ;
    _ability_count += _white.size() ;
    _ability_list.push_back( _white ) ;

    p.parse_file("../../ffrk_abilities/spells/summon_magic") ;
    _summon = p.abilities() ;
    _ability_count += _summon.size() ;
    _ability_list.push_back( _summon ) ;

    p.parse_file("../../ffrk_abilities/spells/knight_magic") ;
    _knight = p.abilities() ;
    _ability_count += _knight.size() ;
    _ability_list.push_back( _knight ) ;

    p.parse_file("../../ffrk_abilities/spells/ninja_magic") ;
    _ninja = p.abilities() ;
    _ability_count += _ninja.size() ;
    _ability_list.push_back( _ninja ) ;

    p.parse_file("../../ffrk_abilities/spells/thief_magic") ;
    _thief = p.abilities() ;
    _ability_count += _thief.size() ;
    _ability_list.push_back( _thief ) ;

    p.parse_file("../../ffrk_abilities/spells/samurai_magic") ;
    _samurai = p.abilities() ;
    _ability_count += _samurai.size() ;
    _ability_list.push_back( _samurai ) ;

    p.parse_file("../../ffrk_abilities/spells/dancer_magic") ;
    _dancer = p.abilities() ;
    _ability_count += _dancer.size() ;
    _ability_list.push_back( _dancer ) ;

    p.parse_file("../../ffrk_abilities/spells/bard_magic") ;
    _bard = p.abilities() ;
    _ability_count += _thief.size() ;
    _ability_list.push_back( _thief ) ;

    p.parse_file("../../ffrk_abilities/spells/spellblade_magic") ;
    _spellblade = p.abilities() ;
    _ability_count += _thief.size() ;
    _ability_list.push_back( _thief ) ;

    p.parse_file("../../ffrk_abilities/spells/celerity_magic") ;
    _celerity = p.abilities() ;
    _ability_count += _celerity.size() ;
    _ability_list.push_back( _celerity ) ;

    p.parse_file("../../ffrk_abilities/spells/support_magic") ;
    _support = p.abilities() ;
    _ability_count += _support.size() ;
    _ability_list.push_back( _support ) ;

    p.parse_file("../../ffrk_abilities/spells/dragoon_magic") ;
    _dragoon = p.abilities() ;
    _ability_count += _dragoon.size() ;
    _ability_list.push_back( _dragoon ) ;

    p.parse_file("../../ffrk_abilities/spells/combat_magic") ;
    _combat = p.abilities() ;
    _ability_count += _combat.size() ;
    _ability_list.push_back( _combat ) ;

    p.parse_file("../../ffrk_abilities/spells/monk_magic") ;
    _monk = p.abilities() ;
    _ability_count += _monk.size() ;
    _ability_list.push_back( _monk ) ;

    p.parse_file("../../ffrk_abilities/spells/bard_magic") ;
    _bard = p.abilities() ;
    _ability_count += _bard.size() ;
    _ability_list.push_back( _bard ) ;

    p.parse_file("../../ffrk_abilities/spells/spellblade_magic") ;
    _spellblade = p.abilities() ;
    _ability_count += _spellblade.size() ;
    _ability_list.push_back( _spellblade ) ;

//    p.parse_file("../../ffrk_abilities/spells/blue_magic") ;
//    _blue = p.abilities() ;
//    _ability_count += _blue.size() ;
//    _ability_list.push_back( _blue ) ;

//    p.parse_file("../../ffrk_abilities/spells/engineer_magic") ;
//    _engineer = p.abilities() ;
//    _ability_count += _engineer.size() ;
//    _ability_list.push_back( _engineer ) ;

    populate_ability_table() ;
}

/**
 * Loads the probability and stamina tables
 */
void ffrk_abilities::on_prob_button_clicked()
{
    orb_statistics_parser os ;
    os.parse_file("../../ffrk_abilities/spells/orb_statistics") ;
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
 * Populates the ability table with all of the abilities
 * from the files
 */
void ffrk_abilities::populate_ability_table()
{
    // Set the Maximum number of rows to the number of abilities that
    // have been added
    ui->ability_table->setRowCount( _ability_count ) ;
    std::list<spell_map>::iterator listIt = _ability_list.begin() ;
    std::list<spell_map>::iterator listIt_end = _ability_list.end() ;
    int count = 0 ;
    while( listIt != listIt_end ) {
        spell_map::iterator It = listIt->begin() ;
        spell_map::iterator It_end = listIt->end() ;
        while( It != It_end ) {
            ability_table_item *name = new ability_table_item(It->second._name, &It->second) ;
            name->setFlags( name->flags() ^ Qt::ItemIsEditable ) ;
            ui->ability_table->setItem(count, ability_table_item::NAME, name) ;
            ui->ability_table->setItem(count, ability_table_item::COUNT, new QTableWidgetItem() ) ;
            ui->ability_table->setItem(count, ability_table_item::HONE, new QTableWidgetItem() ) ;
            ui->ability_table->setItem(count, ability_table_item::RANK, new QTableWidgetItem() ) ;
            It++ ;
            count++ ;
        }
        listIt++ ;
    }
    ui->ability_table->resizeColumnsToContents() ;
    ui->ability_table->horizontalHeader()->stretchLastSection() ;
    update_ability_table() ;
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
 * Updates the current table view used for searching
 */
void ffrk_abilities::update_ability_table()
{
    int size = ui->ability_table->rowCount() ;
    for(int i=0; i<size; ++i) {
        ability_base* _curr = reinterpret_cast<ability_table_item*>(ui->ability_table->item(i, ability_table_item::NAME))->ability() ;
        if( (_curr->_class & _class_filter) && ((_curr->_rarity & _rarity_filter) || _rarity_filter == 0)
             && (check_types::has_orb_type(_curr, _orb_filter) || _orb_filter == 0) )
        {
            ui->ability_table->setRowHidden(i, false) ;
        } else {
            ui->ability_table->setRowHidden(i, true) ;
        }
    }
}

/**
 * Toggles view of Bard abilities
 */
void ffrk_abilities::on_bard_cb_clicked()
{
    _class_filter = _class_filter ^ BRD ;
    update_ability_table() ;
}

/**
 * Toggles view of Black Magic abilities
 */
void ffrk_abilities::on_black_cb_clicked()
{
    _class_filter = _class_filter ^ BLM ;
    update_ability_table() ;
}

/**
 * Toggles view of Blue Magic abilities
 */
void ffrk_abilities::on_blue_cb_clicked()
{
    _class_filter = _class_filter ^ BLU ;
    update_ability_table() ;
}

/**
 * Toggles view of Celerity abilities
 */
void ffrk_abilities::on_celerity_cb_clicked()
{
    _class_filter = _class_filter ^ CEL ;
    update_ability_table() ;
}

/**
 * Toggles view of Combat abilities
 */
void ffrk_abilities::on_combat_cb_clicked()
{
    _class_filter = _class_filter ^ CBT ;
    update_ability_table() ;
}

/**
 * Toggles view of Dancer abilities
 */
void ffrk_abilities::on_dance_cb_clicked()
{
    _class_filter = _class_filter ^ DNC ;
    update_ability_table() ;
}

/**
 * Toggles view of Dragoon abilities
 */
void ffrk_abilities::on_dragoon_cb_clicked()
{
    _class_filter = _class_filter ^ DRG ;
    update_ability_table() ;
}

/**
 * Toggles view of Engineer abilities
 */
void ffrk_abilities::on_engineer_cb_clicked()
{
    _class_filter = _class_filter ^ ENG ;
    update_ability_table() ;
}

/**
 * Toggles view of Knight abilities
 */
void ffrk_abilities::on_knight_cb_clicked()
{
    _class_filter = _class_filter ^ KNT ;
    update_ability_table() ;
}

/**
 * Toggles view of Monk abilities
 */
void ffrk_abilities::on_monk_cb_clicked()
{
    _class_filter = _class_filter ^ MNK ;
    update_ability_table() ;
}

/**
 * Toggles view of Ninja abilities
 */
void ffrk_abilities::on_ninja_cb_clicked()
{
    _class_filter = _class_filter ^ NIN ;
    update_ability_table() ;
}

/**
 * Toggles view of Samurai abilities
 */
void ffrk_abilities::on_samurai_cb_clicked()
{
    _class_filter = _class_filter ^ SAM ;
    update_ability_table() ;
}

/**
 * Toggles view of Spellblade abilities
 */
void ffrk_abilities::on_spellblade_cb_clicked()
{
    _class_filter = _class_filter ^ SPB ;
    update_ability_table() ;
}

/**
 * Toggles view of Summoning abilities
 */
void ffrk_abilities::on_summon_cb_clicked()
{
    _class_filter = _class_filter ^ SMN ;
    update_ability_table() ;
}

/**
 * Toggles view of Support abilities
 */
void ffrk_abilities::on_support_cb_clicked()
{
    _class_filter = _class_filter ^ SPT ;
    update_ability_table() ;
}

/**
 * Toggles view of Thief abilities
 */
void ffrk_abilities::on_theif_cb_clicked()
{
    _class_filter = _class_filter ^ THF ;
    update_ability_table() ;
}

/**
 * Toggles view of White Magic abilities
 */
void ffrk_abilities::on_white_cb_clicked()
{
    _class_filter = _class_filter ^ WHM ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Power orbs
 */
void ffrk_abilities::on_power_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CPOWER ;
    update_ability_table() ;
}
/**
 * Toggles view of abilities with White orbs
 */
void ffrk_abilities::on_white_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CWHITE ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Black orbs
 */
void ffrk_abilities::on_black_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CBLACK ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Summon orbs
 */
void ffrk_abilities::on_summon_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CSUMMON ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Non-Elemental orbs
 */
void ffrk_abilities::on_non_elem_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CNON_ELEM ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Fire orbs
 */
void ffrk_abilities::on_fire_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CFIRE ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Ice orbs
 */
void ffrk_abilities::on_ice_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CICE ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Lightning orbs
 */
void ffrk_abilities::on_lightning_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CLIGHTNING ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Earth orbs
 */
void ffrk_abilities::on_earth_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CEARTH ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Wind orbs
 */
void ffrk_abilities::on_wind_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CWIND ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Holy orbs
 */
void ffrk_abilities::on_holy_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CHOLY ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Dark orbs
 */
void ffrk_abilities::on_dark_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CDARK ;
    update_ability_table() ;
}

/**
 * Toggles view of abilities with Blue orbs
 */
void ffrk_abilities::on_blue_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CBLUE ;
    update_ability_table() ;
}

/**
 * Filters by ability rarity
 */
void ffrk_abilities::on_rarity_filter_currentIndexChanged(int index)
{
    switch(index) {
        case 1:
            _rarity_filter = STAR_1 ;
            break ;
        case 2:
            _rarity_filter = STAR_2 ;
            break ;
        case 3:
            _rarity_filter = STAR_3 ;
            break ;
        case 4:
            _rarity_filter = STAR_4 ;
            break ;
        case 5:
            _rarity_filter = STAR_5 ;
            break ;
        case 6:
            _rarity_filter = STAR_6 ;
            break ;
        default:
            _rarity_filter = 0 ;
            break ;
    }
    update_ability_table() ;
}

/**
 * Callback when the Ability Table Items have been changed.
 */
void ffrk_abilities::on_ability_table_cellChanged(int row, int column)
{
    ability_table_item* _curr = reinterpret_cast<ability_table_item*>(ui->ability_table->item(row, ability_table_item::NAME)) ;
    QString data = ui->ability_table->item(row,column)->text() ;
    ability_map::iterator FindIt = _cumulative_orbs.find( _curr->ability()->_name ) ;
    ability_map::iterator It_end = _cumulative_orbs.end() ;
    if( FindIt != It_end ) {
        if( (data.toInt() == 0 || data.isEmpty()) && column != ability_table_item::RANK ) {
            _cumulative_orbs.erase( FindIt ) ;
            ui->ability_table->item(row, column)->setText( QString() ) ;
        } else {
            if( column == ability_table_item::COUNT ) {
                FindIt->second._number = data.toInt() ;
            } else
            if( column == ability_table_item::RANK ) {
                int value = data.toInt() ;
                if( 5 < value ) {
                    ui->ability_table->item(row, column)->setText( QString::number(value) ) ;
                    value = 5 ;
                }
                FindIt->second._rank = value ;
            } else
            if( column == ability_table_item::HONE ) {
                int value = data.toInt() ;
                if( 5 < value ) {
                    ui->ability_table->item(row, column)->setText( QString::number(value) ) ;
                    value = 5 ;
                }
                FindIt->second._hone = value ;
            }
        }
    } else {
        if( data.toInt() != 0 && !data.isEmpty() ) {
            orb_data o ;
            o._ability = _curr->ability() ;
            o._number = 0 ;
            o._rank = 0 ;
            o._hone = 0 ;
            if( column == ability_table_item::COUNT ) {
                o._number = ui->ability_table->item(row, ability_table_item::COUNT)->text().toInt() ;
            } else
            if( column == ability_table_item::RANK ) {
                o._rank = ui->ability_table->item(row, ability_table_item::RANK)->text().toInt() ;
            } else
            if( column == ability_table_item::HONE ) {
                o._rank = ui->ability_table->item(row, ability_table_item::HONE)->text().toInt() ;
            }
            _cumulative_orbs.insert( std::make_pair( o._ability->_name, o) ) ;
            return ;
        } else {
            if( column == ability_table_item::COUNT
             || column == ability_table_item::RANK
             || column == ability_table_item::HONE )
            {
                ui->ability_table->item(row, column)->setText( QString() ) ;
            }
        }
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
    ability_map::iterator It = _cumulative_orbs.begin() ;
    ability_map::iterator It_end = _cumulative_orbs.end() ;
    for(int i=0; i<_max_row; ++i) {
        for(int j=0; j<_max_col; ++j) {
            _orbs[i][j] = 0 ;
        }
    }
    while( It != It_end ) {
        rarity_list::iterator rare = It->second._ability->_rare.begin() ;
        rarity_list::iterator rare_end = It->second._ability->_rare.end() ;
        orb_list::iterator types = It->second._ability->_types.begin() ;
        orb_list::iterator types_end = It->second._ability->_types.end() ;
        rank_list::iterator count = It->second._ability->_counts.begin() ;
        rank_list::iterator count_end = It->second._ability->_counts.end() ;
        while( (rare != rare_end) && (types != types_end) && (count != count_end) ) {
            int row = orb_type(*types) ;
            int column = *rare ;
            int multiplier = It->second._number ;
            int s = int(*count) ;
            int r = It->second._rank - 1 ;
            int rh = It->second._hone - 1 ;
            if( rh < 0 ) rh = 0 ;
            if( r < 1 ) {
                _orbs[row][column] += (multiplier * _ranks.num_orbs(s,rh)) ;
            } else {
                _orbs[row][column] += (multiplier * (_ranks.num_orbs(s,rh) - _ranks.num_orbs(s, r))) ;
            }
            rare++ ;
            types++ ;
            count++ ;
        }
        It++ ;
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
