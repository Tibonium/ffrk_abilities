#include "ffrk_abilities.h"
#include "ui_ffrk_abilities.h"

ffrk_abilities::ffrk_abilities(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ffrk_abilities),
    _initialized(false),
    _ranks(),
    _class_filter(0),
    _rarity_filter(0),
    _max_row(13),
    _max_col(6)
{
    ui->setupUi(this) ;
    spell_parser p ;

    p.parse_file("../../ffrk_abilities/black_magic/black_magic") ;
    _black = *(p.abilities()) ;

    populate_ability_table() ;
    setup_orb_table() ;
    _orbs = new int*[_max_row] ;
    for(int i=0; i<_max_row; ++i) {
        _orbs[i] = new int[_max_col] ;
    }
    _initialized = true ;
}

ffrk_abilities::~ffrk_abilities()
{
    for(int i=0; i<13; ++i) {
        delete _orbs[i] ;
    }
    delete _orbs ;
    delete ui;
}

/**
 * Populates the ability table with all of the abilities
 * from the files
 */
void ffrk_abilities::populate_ability_table()
{
    // Add the black magic abilities to the table
    ui->ability_table->setRowCount( _black.size() ) ;
    int count = 0 ;
    spell_list::iterator It = _black.begin() ;
    spell_list::iterator It_end = _black.end() ;
    while( It != It_end ) {
        ability_table_item *name = new ability_table_item(It->_name, &(*It)) ;
        name->setFlags( name->flags() ^ Qt::ItemIsEditable ) ;
        ui->ability_table->setItem(count, ability_table_item::NAME, name) ;
        ui->ability_table->setItem(count, ability_table_item::COUNT, new QTableWidgetItem() ) ;
        ui->ability_table->setItem(count, ability_table_item::RANK, new QTableWidgetItem() ) ;
        It++ ;
        ui->ability_table->setRowHidden(count++, true) ;
    }
}

/**
 * Initializes all of the table cells for the orbs
 */
void ffrk_abilities::setup_orb_table()
{
    for(int i=0; i<_max_row; ++i) {
        for(int j=0; j<_max_col; ++j) {
            ui->orb_table->setItem(i, j, new QTableWidgetItem()) ;
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
        ability_table_item* _curr = reinterpret_cast<ability_table_item*>(ui->ability_table->item(i, ability_table_item::NAME)) ;
        if( (_curr->ability()->_class & _class_filter)
        &&  ((_curr->ability()->_rarity & _rarity_filter) || _rarity_filter == 0))
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
        if( data.toInt() == 0 || data.isEmpty() ) {
            _cumulative_orbs.erase( FindIt ) ;
            ui->ability_table->item(row, column)->setText( QString() ) ;
        } else {
            if( column == ability_table_item::COUNT ) {
                FindIt->second._number = data.toInt() ;
            } else
            if( column == ability_table_item::RANK ) {
                int value = data.toInt() ;
                if( 5 < value ) value = 5 ;
                FindIt->second._rank = value ;
            }
        }
    } else {
        if( data.toInt() != 0 && !data.isEmpty() ) {
            orb_data o ;
            o._ability = _curr->ability() ;
            o._number = 0 ;
            o._rank = 0 ;
            if( column == ability_table_item::COUNT ) {
                o._number = ui->ability_table->item(row, ability_table_item::COUNT)->text().toInt() ;
            } else
            if( column == ability_table_item::RANK ) {
                o._rank = ui->ability_table->item(row, ability_table_item::RANK)->text().toInt() ;
            }
            _cumulative_orbs.insert( std::make_pair( o._ability->_name, o) ) ;
            return ;
        } else {
            if( column == ability_table_item::COUNT || column == ability_table_item::RANK ) {
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
            _orbs[row][column] += (multiplier * _ranks.num_orbs(s, r)) ;
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
}
