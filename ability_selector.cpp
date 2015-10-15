#include "ability_selector.h"
#include "ui_ability_selector.h"

/**
 * @brief ability_selector::ability_selector
 * @param parent
 */
ability_selector::ability_selector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ability_selector),
    _ability_count(0),
    _settings("Tibonium Inc.", "FFRK Ability Selector"),
    _filepath(),
    _focus_ability(0),
    _cancel(false),
    _class_filter(0),
    _orb_filter(0),
    _rarity_filter(0)
{
    ui->setupUi(this);
    std::fstream file("ffrk_ability_config") ;
    std::getline(file, _filepath) ;
    import_spells() ;
}

/**
 * @brief ability_selector::~ability_selector
 */
ability_selector::~ability_selector()
{
    delete ui;
}

/**
 * @brief ability_selector::closeEvent
 * @param e
 */
void ability_selector::closeEvent(QCloseEvent *e)
{
    _settings.setValue("position", pos()) ;
    _settings.setValue("size", size()) ;
    on_ability_list_itemSelectionChanged() ;
    e->accept() ;
}

/**
 * @brief ability_selector::on_ability_list_doubleClicked
 * @param index
 */
void ability_selector::on_ability_list_doubleClicked(const QModelIndex &index)
{
    _focus_ability = reinterpret_cast<ability_list_item*>(ui->ability_list->item(index.row()))->ability() ;
    close() ;
}

/**
 * Event that allows user to make a mapping selection between
 * an AWSIM name and MEL/MEW Entity.
 */
void ability_selector::choose_ability()
{
    _cancel = false ;
    _focus_ability = 0 ;
    if( _settings.contains("position") )
        move( _settings.value("position").toPoint() ) ;
    if( _settings.contains("size") )
        resize( _settings.value("size").toSize() ) ;
    exec() ;
}

void ability_selector::import_spells()
{
    // Setup the parser
    spell_parser p ;
    QMessageBox msg ;

    std::string file = _filepath + "black_magic" ;
    std::string t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _black = p.abilities() ;
    _ability_list.push_back( _black ) ;

    file = _filepath + "white_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _white = p.abilities() ;
    _ability_list.push_back( _white ) ;

    file = _filepath + "summon_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _summon = p.abilities() ;
    _ability_list.push_back( _summon ) ;

    file = _filepath + "knight_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _knight = p.abilities() ;
    _ability_list.push_back( _knight ) ;

    file = _filepath + "ninja_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _ninja = p.abilities() ;
    _ability_list.push_back( _ninja ) ;

    file = _filepath + "thief_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _thief = p.abilities() ;
    _ability_list.push_back( _thief ) ;

    file = _filepath + "samurai_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _samurai = p.abilities() ;
    _ability_list.push_back( _samurai ) ;

    file = _filepath + "dancer_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _dancer = p.abilities() ;
    _ability_list.push_back( _dancer ) ;

    file = _filepath + "bard_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _bard = p.abilities() ;
    _ability_list.push_back( _bard ) ;

    file = _filepath + "spellblade_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _spellblade = p.abilities() ;
    _ability_list.push_back( _spellblade ) ;

    file = _filepath + "celerity_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _celerity = p.abilities() ;
    _ability_list.push_back( _celerity ) ;

    file = _filepath + "support_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _support = p.abilities() ;
    _ability_list.push_back( _support ) ;

    file = _filepath + "dragoon_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _dragoon = p.abilities() ;
    _ability_list.push_back( _dragoon ) ;

    file = _filepath + "combat_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _combat = p.abilities() ;
    _ability_list.push_back( _combat ) ;

    file = _filepath + "monk_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
        exit(0) ;
    }
    _monk = p.abilities() ;
    _ability_list.push_back( _monk ) ;

//    file = filepath + "blue_magic" ;
//    p.parse_file(file.c_str()) ;
//    _blue = p.abilities() ;
//    _ability_count += _blue.size() ;
//    _ability_list.push_back( _blue ) ;

//    file = filepath + "engineer_magic" ;
//    p.parse_file(file.c_str()) ;
//    _engineer = p.abilities() ;
//    _ability_count += _engineer.size() ;
//    _ability_list.push_back( _engineer ) ;

    populate_list() ;
}

/**
 * Adds all Abilities to the list
 */
void ability_selector::populate_list()
{
    std::list<spell_map>::iterator listIt = _ability_list.begin() ;
    std::list<spell_map>::iterator listIt_end = _ability_list.end() ;
    int count = 0 ;
    while( listIt != listIt_end ) {
        spell_map::iterator It = listIt->begin() ;
        spell_map::iterator It_end = listIt->end() ;
        while( It != It_end ) {
            ability_list_item *ability = new ability_list_item(It->second._name, &It->second) ;
            ui->ability_list->addItem( ability ) ;
            ui->ability_list->setRowHidden(count++, true) ;
            It++ ;
        }
        listIt++ ;
    }
}

/**
 * Closes the selector
 */
void ability_selector::on_ok_button_clicked()
{
    _focus_ability = reinterpret_cast<ability_list_item*>(ui->ability_list->currentItem())->ability() ;
    close() ;
}

/**
 * Sets focus to NULL before exiting.
 */
void ability_selector::on_cancel_button_clicked()
{
    _focus_ability = 0 ;
    _cancel = true ;
    close() ;
}

/**
 * Sets the current focus entity
 */
void ability_selector::on_ability_list_itemSelectionChanged()
{
    _focus_ability = reinterpret_cast<ability_list_item*>(ui->ability_list->currentItem())->ability() ;
}

/**
 * Updates the current table view used for searching
 */
void ability_selector::update_ability_list()
{
    int size = ui->ability_list->count() ;
    for(int i=0; i<size; ++i) {
        ability_base* _curr = reinterpret_cast<ability_list_item*>(ui->ability_list->item(i))->ability() ;
        if( (_curr->_class & _class_filter) && ((_curr->_rarity & _rarity_filter) || _rarity_filter == 0)
             && (check_types::has_orb_type(_curr, _orb_filter) || _orb_filter == 0) )
        {
            ui->ability_list->setRowHidden(i, false) ;
        } else {
            ui->ability_list->setRowHidden(i, true) ;
        }
    }
}

/**
 * Toggles view of Bard abilities
 */
void ability_selector::on_bard_cb_clicked()
{
    _class_filter = _class_filter ^ BRD ;
    update_ability_list() ;
}

/**
 * Toggles view of Black Magic abilities
 */
void ability_selector::on_black_cb_clicked()
{
    _class_filter = _class_filter ^ BLM ;
    update_ability_list() ;
}

/**
 * Toggles view of Blue Magic abilities
 */
void ability_selector::on_blue_cb_clicked()
{
    _class_filter = _class_filter ^ BLU ;
    update_ability_list() ;
}

/**
 * Toggles view of Celerity abilities
 */
void ability_selector::on_celerity_cb_clicked()
{
    _class_filter = _class_filter ^ CEL ;
    update_ability_list() ;
}

/**
 * Toggles view of Combat abilities
 */
void ability_selector::on_combat_cb_clicked()
{
    _class_filter = _class_filter ^ CBT ;
    update_ability_list() ;
}

/**
 * Toggles view of Dancer abilities
 */
void ability_selector::on_dance_cb_clicked()
{
    _class_filter = _class_filter ^ DNC ;
    update_ability_list() ;
}

/**
 * Toggles view of Dragoon abilities
 */
void ability_selector::on_dragoon_cb_clicked()
{
    _class_filter = _class_filter ^ DRG ;
    update_ability_list() ;
}

/**
 * Toggles view of Engineer abilities
 */
void ability_selector::on_engineer_cb_clicked()
{
    _class_filter = _class_filter ^ ENG ;
    update_ability_list() ;
}

/**
 * Toggles view of Knight abilities
 */
void ability_selector::on_knight_cb_clicked()
{
    _class_filter = _class_filter ^ KNT ;
    update_ability_list() ;
}

/**
 * Toggles view of Monk abilities
 */
void ability_selector::on_monk_cb_clicked()
{
    _class_filter = _class_filter ^ MNK ;
    update_ability_list() ;
}

/**
 * Toggles view of Ninja abilities
 */
void ability_selector::on_ninja_cb_clicked()
{
    _class_filter = _class_filter ^ NIN ;
    update_ability_list() ;
}

/**
 * Toggles view of Samurai abilities
 */
void ability_selector::on_samurai_cb_clicked()
{
    _class_filter = _class_filter ^ SAM ;
    update_ability_list() ;
}

/**
 * Toggles view of Spellblade abilities
 */
void ability_selector::on_spellblade_cb_clicked()
{
    _class_filter = _class_filter ^ SPB ;
    update_ability_list() ;
}

/**
 * Toggles view of Summoning abilities
 */
void ability_selector::on_summon_cb_clicked()
{
    _class_filter = _class_filter ^ SMN ;
    update_ability_list() ;
}

/**
 * Toggles view of Support abilities
 */
void ability_selector::on_support_cb_clicked()
{
    _class_filter = _class_filter ^ SPT ;
    update_ability_list() ;
}

/**
 * Toggles view of Thief abilities
 */
void ability_selector::on_theif_cb_clicked()
{
    _class_filter = _class_filter ^ THF ;
    update_ability_list() ;
}

/**
 * Toggles view of White Magic abilities
 */
void ability_selector::on_white_cb_clicked()
{
    _class_filter = _class_filter ^ WHM ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Power orbs
 */
void ability_selector::on_power_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CPOWER ;
    update_ability_list() ;
}
/**
 * Toggles view of abilities with White orbs
 */
void ability_selector::on_white_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CWHITE ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Black orbs
 */
void ability_selector::on_black_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CBLACK ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Summon orbs
 */
void ability_selector::on_summon_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CSUMMON ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Non-Elemental orbs
 */
void ability_selector::on_non_elem_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CNON_ELEM ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Fire orbs
 */
void ability_selector::on_fire_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CFIRE ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Ice orbs
 */
void ability_selector::on_ice_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CICE ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Lightning orbs
 */
void ability_selector::on_lightning_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CLIGHTNING ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Earth orbs
 */
void ability_selector::on_earth_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CEARTH ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Wind orbs
 */
void ability_selector::on_wind_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CWIND ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Holy orbs
 */
void ability_selector::on_holy_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CHOLY ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Dark orbs
 */
void ability_selector::on_dark_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CDARK ;
    update_ability_list() ;
}

/**
 * Toggles view of abilities with Blue orbs
 */
void ability_selector::on_blue_orb_cb_clicked()
{
    _orb_filter = _orb_filter ^ CBLUE ;
    update_ability_list() ;
}

/**
 * Filters by ability rarity
 */
void ability_selector::on_rarity_filter_currentIndexChanged(int index)
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
    update_ability_list() ;
}
