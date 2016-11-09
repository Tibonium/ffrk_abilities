#include "ability_selector.h"
#include "ui_ability_selector.h"

/**
 * @brief ability_selector::ability_selector
 * @param parent
 */
ability_selector::ability_selector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ability_selector),
    m_iAbilityCount(0),
    m_oSettings("Tibonium Inc.", "FFRK Ability Selector"),
    m_sFilepath(),
    m_poFocus(0),
    m_bCancel(false),
    m_lClassFilter(0),
    m_uOrbFilter(0),
    m_uRarityFilter(0)
{
    ui->setupUi(this);
    std::fstream file("ffrk_ability_config") ;
    std::getline(file, m_sFilepath) ;
    importSpellMaps() ;
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
    m_oSettings.setValue("position", pos()) ;
    m_oSettings.setValue("size", size()) ;
    on_ability_list_itemSelectionChanged() ;
    e->accept() ;
}

/**
 * @brief ability_selector::on_ability_list_doubleClicked
 * @param index
 */
void ability_selector::on_ability_list_doubleClicked(const QModelIndex &index)
{
    m_poFocus = reinterpret_cast<ability_list_item*>(ui->ability_list->item(index.row()))->ability() ;
    close() ;
}

/**
 * Event that allows user to make a mapping selection between
 * an AWSIM name and MEL/MEW Entity.
 */
void ability_selector::choose_ability()
{
    m_bCancel = false ;
    m_poFocus = 0 ;
    if( m_oSettings.contains("position") )
        move( m_oSettings.value("position").toPoint() ) ;
    if( m_oSettings.contains("size") )
        resize( m_oSettings.value("size").toSize() ) ;
    exec() ;
}

void ability_selector::importSpellMaps()
{
    // Setup the parser
    spell_parser p ;
    QMessageBox msg ;

    std::string file = m_sFilepath + "black_magic" ;
    std::string t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oBlack = p.abilities() ;
        m_xoAbilityList.push_back( m_oBlack ) ;
    }

    file = m_sFilepath + "white_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oWhite = p.abilities() ;
        m_xoAbilityList.push_back( m_oWhite ) ;
    }

    file = m_sFilepath + "summon_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oSummon = p.abilities() ;
        m_xoAbilityList.push_back( m_oSummon ) ;
    }

    file = m_sFilepath + "knight_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oKnight = p.abilities() ;
        m_xoAbilityList.push_back( m_oKnight ) ;
    }

    file = m_sFilepath + "ninja_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oNinja = p.abilities() ;
        m_xoAbilityList.push_back( m_oNinja ) ;
    }

    file = m_sFilepath + "thief_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oThief = p.abilities() ;
        m_xoAbilityList.push_back( m_oThief ) ;
    }

    file = m_sFilepath + "samurai_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oSamurai = p.abilities() ;
        m_xoAbilityList.push_back( m_oSamurai ) ;
    }

    file = m_sFilepath + "dancer_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oDancer = p.abilities() ;
        m_xoAbilityList.push_back( m_oDancer ) ;
    }

    file = m_sFilepath + "bard_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oBard = p.abilities() ;
        m_xoAbilityList.push_back( m_oBard ) ;
    }

    file = m_sFilepath + "spellblade_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oSpellblade = p.abilities() ;
        m_xoAbilityList.push_back( m_oSpellblade ) ;
    }

    file = m_sFilepath + "celerity_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oCelerity = p.abilities() ;
        m_xoAbilityList.push_back( m_oCelerity ) ;
    }

    file = m_sFilepath + "support_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oSupport = p.abilities() ;
        m_xoAbilityList.push_back( m_oSupport ) ;
    }

    file = m_sFilepath + "dragoon_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oDragoon = p.abilities() ;
        m_xoAbilityList.push_back( m_oDragoon ) ;
    }

    file = m_sFilepath + "combat_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oCombat = p.abilities() ;
        m_xoAbilityList.push_back( m_oCombat ) ;
    }

    file = m_sFilepath + "monk_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oMonk = p.abilities() ;
        m_xoAbilityList.push_back( m_oMonk ) ;
    }

    file = m_sFilepath + "blue_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oBlue = p.abilities() ;
        m_xoAbilityList.push_back( m_oBlue ) ;
    }

    file = m_sFilepath + "engineer_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oEngineer = p.abilities() ;
        m_xoAbilityList.push_back( m_oEngineer ) ;
    }

    file = m_sFilepath + "darkness_magic" ;
    t = p.parse_file(file.c_str()) ;
    if( !t.empty() ) {
        msg.setText( t.c_str() ) ;
        msg.exec() ;
    } else {
        m_oDarkness = p.abilities() ;
        m_xoAbilityList.push_back( m_oDarkness ) ;
    }

    populateList() ;
}

QSettings ability_selector::settings() const
{
    return m_oSettings;
}

void ability_selector::setSettings(const QSettings &settings)
{
    m_oSettings = settings;
}

/**
 * Adds all Abilities to the list
 */
void ability_selector::populateList()
{
    std::list<SpellMapType>::iterator listIt = m_xoAbilityList.begin() ;
    std::list<SpellMapType>::iterator listIt_end = m_xoAbilityList.end() ;
    int count = 0 ;
    while( listIt != listIt_end ) {
        SpellMapType::iterator It = listIt->begin() ;
        SpellMapType::iterator It_end = listIt->end() ;
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
    m_poFocus = reinterpret_cast<ability_list_item*>(ui->ability_list->currentItem())->ability() ;
    close() ;
}

/**
 * Sets focus to NULL before exiting.
 */
void ability_selector::on_cancel_button_clicked()
{
    m_poFocus = 0 ;
    m_bCancel = true ;
    close() ;
}

/**
 * Sets the current focus entity
 */
void ability_selector::on_ability_list_itemSelectionChanged()
{
    if( -1 < ui->ability_list->currentRow() )
        m_poFocus = reinterpret_cast<ability_list_item*>(ui->ability_list->currentItem())->ability() ;
}

/**
 * Updates the current table view used for searching
 */
void ability_selector::updateAbilityList()
{
    int size = ui->ability_list->count() ;
    for(int i=0; i<size; ++i) {
        ability_base* _curr = reinterpret_cast<ability_list_item*>(ui->ability_list->item(i))->ability() ;
        if( (_curr->_class & m_lClassFilter) && ((_curr->_rarity & m_uRarityFilter) || m_uRarityFilter == 0)
             && (check_types::has_orb_type(_curr, m_uOrbFilter) || m_uOrbFilter == 0) )
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
    m_lClassFilter = m_lClassFilter ^ BRD ;
    updateAbilityList() ;
}

/**
 * Toggles view of Black Magic abilities
 */
void ability_selector::on_black_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ BLM ;
    updateAbilityList() ;
}

/**
 * Toggles view of Blue Magic abilities
 */
void ability_selector::on_blue_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ BLU ;
    updateAbilityList() ;
}

/**
 * Toggles view of Celerity abilities
 */
void ability_selector::on_celerity_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ CEL ;
    updateAbilityList() ;
}

/**
 * Toggles view of Combat abilities
 */
void ability_selector::on_combat_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ CBT ;
    updateAbilityList() ;
}

/**
 * Toggles view of Dancer abilities
 */
void ability_selector::on_dance_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ DNC ;
    updateAbilityList() ;
}

/**
 * Toggles view of Dragoon abilities
 */
void ability_selector::on_dragoon_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ DRG ;
    updateAbilityList() ;
}

/**
 * Toggles view of Engineer abilities
 */
void ability_selector::on_engineer_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ ENG ;
    updateAbilityList() ;
}

/**
 * Toggles view of Knight abilities
 */
void ability_selector::on_knight_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ KNT ;
    updateAbilityList() ;
}

/**
 * Toggles view of Monk abilities
 */
void ability_selector::on_monk_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ MNK ;
    updateAbilityList() ;
}

/**
 * Toggles view of Ninja abilities
 */
void ability_selector::on_ninja_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ NIN ;
    updateAbilityList() ;
}

/**
 * Toggles view of Samurai abilities
 */
void ability_selector::on_samurai_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ SAM ;
    updateAbilityList() ;
}

/**
 * Toggles view of Spellblade abilities
 */
void ability_selector::on_spellblade_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ SPB ;
    updateAbilityList() ;
}

/**
 * Toggles view of Sharpshooter abilities
 */
void ability_selector::on_shooter_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ SRP ;
    updateAbilityList() ;
}

/**
 * Toggles view of Summoning abilities
 */
void ability_selector::on_summon_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ SMN ;
    updateAbilityList() ;
}

/**
 * Toggles view of Support abilities
 */
void ability_selector::on_support_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ SPT ;
    updateAbilityList() ;
}

/**
 * Toggles view of Thief abilities
 */
void ability_selector::on_theif_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ THF ;
    updateAbilityList() ;
}

/**
 * Toggles view of Darkness abilities
 */
void ability_selector::on_darkness_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ DRK ;
    updateAbilityList() ;
}

/**
 * Toggles view of White Magic abilities
 */
void ability_selector::on_white_cb_clicked()
{
    m_lClassFilter = m_lClassFilter ^ WHM ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Power orbs
 */
void ability_selector::on_power_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CPOWER ;
    updateAbilityList() ;
}
/**
 * Toggles view of abilities with White orbs
 */
void ability_selector::on_white_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CWHITE ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Black orbs
 */
void ability_selector::on_black_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CBLACK ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Summon orbs
 */
void ability_selector::on_summon_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CSUMMON ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Non-Elemental orbs
 */
void ability_selector::on_non_elem_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CNON_ELEM ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Fire orbs
 */
void ability_selector::on_fire_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CFIRE ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Ice orbs
 */
void ability_selector::on_ice_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CICE ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Lightning orbs
 */
void ability_selector::on_lightning_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CLIGHTNING ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Earth orbs
 */
void ability_selector::on_earth_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CEARTH ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Wind orbs
 */
void ability_selector::on_wind_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CWIND ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Holy orbs
 */
void ability_selector::on_holy_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CHOLY ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Dark orbs
 */
void ability_selector::on_dark_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CDARK ;
    updateAbilityList() ;
}

/**
 * Toggles view of abilities with Blue orbs
 */
void ability_selector::on_blue_orb_cb_clicked()
{
    m_uOrbFilter = m_uOrbFilter ^ CBLUE ;
    updateAbilityList() ;
}

/**
 * Filters by ability rarity
 */
void ability_selector::on_rarity_filter_currentIndexChanged(int index)
{
    switch(index) {
        case 1:
            m_uRarityFilter = STAR_1 ;
            break ;
        case 2:
            m_uRarityFilter = STAR_2 ;
            break ;
        case 3:
            m_uRarityFilter = STAR_3 ;
            break ;
        case 4:
            m_uRarityFilter = STAR_4 ;
            break ;
        case 5:
            m_uRarityFilter = STAR_5 ;
            break ;
        case 6:
            m_uRarityFilter = STAR_6 ;
            break ;
        default:
            m_uRarityFilter = 0 ;
            break ;
    }
    updateAbilityList() ;
}

/**
 * Searches for the requested ability
 */
ability_base* ability_selector::find_ability(std::string name)
{
    std::list<SpellMapType>::iterator listIt = m_xoAbilityList.begin() ;
    std::list<SpellMapType>::iterator listIt_end = m_xoAbilityList.end() ;
    while( listIt != listIt_end ) {
        SpellMapType::iterator FindIt = listIt->find( name ) ;
        SpellMapType::iterator It_end = listIt->end() ;
        if( FindIt != It_end ) {
            return &FindIt->second ;
        }
        listIt++ ;
    }
    return 0 ;
}
