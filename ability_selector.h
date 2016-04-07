#ifndef ABILITY_SELECTOR_H
#define ABILITY_SELECTOR_H

#include <QDialog>
#include <QCloseEvent>
#include <QSettings>
#include <QMessageBox>

#include "base/spell_parser.h"
#include "ability_list_item.h"

namespace Ui {
class ability_selector;
}

class ability_selector : public QDialog
{
    Q_OBJECT

public:
    explicit ability_selector(QWidget *parent = 0);
    ~ability_selector();

    void closeEvent(QCloseEvent *e) ;

    void choose_ability() ;

    ability_base* result() {
        return _focus_ability ;
    }

    ability_base* find_ability(std::string name) ;

private slots:
    void on_ability_list_doubleClicked(const QModelIndex &index) ;

    void on_ok_button_clicked() ;

    void on_cancel_button_clicked() ;

    void on_ability_list_itemSelectionChanged() ;

    void on_black_cb_clicked() ;

    void on_bard_cb_clicked() ;

    void on_blue_cb_clicked() ;

    void on_celerity_cb_clicked() ;

    void on_combat_cb_clicked() ;

    void on_dance_cb_clicked() ;

    void on_dragoon_cb_clicked() ;

    void on_engineer_cb_clicked() ;

    void on_knight_cb_clicked() ;

    void on_monk_cb_clicked() ;

    void on_ninja_cb_clicked() ;

    void on_samurai_cb_clicked() ;

    void on_spellblade_cb_clicked() ;

    void on_summon_cb_clicked() ;

    void on_support_cb_clicked() ;

    void on_theif_cb_clicked() ;

    void on_white_cb_clicked() ;

    void on_power_orb_cb_clicked() ;

    void on_white_orb_cb_clicked() ;

    void on_black_orb_cb_clicked() ;

    void on_summon_orb_cb_clicked() ;

    void on_non_elem_orb_cb_clicked() ;

    void on_fire_orb_cb_clicked() ;

    void on_ice_orb_cb_clicked() ;

    void on_lightning_orb_cb_clicked() ;

    void on_earth_orb_cb_clicked() ;

    void on_wind_orb_cb_clicked() ;

    void on_holy_orb_cb_clicked() ;

    void on_dark_orb_cb_clicked() ;

    void on_blue_orb_cb_clicked() ;

    void on_rarity_filter_currentIndexChanged(int index) ;

    void on_darkness_cb_clicked();

private:
    typedef spell_parser::map_type     spell_map ;

    Ui::ability_selector *ui ;

    void import_spells() ;

    std::list<spell_map> _ability_list ;
    int _ability_count ;

    spell_map _black ;
    spell_map _white ;
    spell_map _summon ;
    spell_map _knight ;
    spell_map _combat ;
    spell_map _samurai ;
    spell_map _ninja ;
    spell_map _dragoon ;
    spell_map _thief ;
    spell_map _dancer ;
    spell_map _bard ;
    spell_map _support ;
    spell_map _spellblade ;
    spell_map _blue ;
    spell_map _celerity ;
    spell_map _monk ;
    spell_map _engineer ;
    spell_map _darkness ;

    QSettings _settings ;
    std::string _filepath ;
    ability_base* _focus_ability ;
    bool _cancel ;

    long _class_filter ;
    short _rarity_filter ;
    short _orb_filter ;

    void populate_list() ;

    void update_ability_list() ;
};

#endif // ABILITY_SELECTOR_H
