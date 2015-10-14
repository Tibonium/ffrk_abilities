#ifndef FFRK_ABILITIES_H
#define FFRK_ABILITIES_H

#include <QWidget>
#include <QSettings>
#include <QCloseEvent>

#include <map>
#include "base/spell_parser.h"
#include "ability_table_entry.h"
#include "base/orb_statistics_parser.h"

namespace Ui {
class ffrk_abilities;
}

class ffrk_abilities : public QWidget
{
    Q_OBJECT

public:
    explicit ffrk_abilities(QWidget *parent = 0);
    ~ffrk_abilities();

    void closeEvent(QCloseEvent *e) ;

private slots:
    void on_black_cb_clicked();

    void on_bard_cb_clicked();

    void on_blue_cb_clicked();

    void on_celerity_cb_clicked();

    void on_combat_cb_clicked();

    void on_dance_cb_clicked();

    void on_dragoon_cb_clicked();

    void on_engineer_cb_clicked();

    void on_knight_cb_clicked();

    void on_monk_cb_clicked();

    void on_ninja_cb_clicked();

    void on_samurai_cb_clicked();

    void on_spellblade_cb_clicked();

    void on_summon_cb_clicked();

    void on_support_cb_clicked();

    void on_theif_cb_clicked();

    void on_white_cb_clicked();

    void on_rarity_filter_currentIndexChanged(int index);

    void on_ability_table_cellChanged(int row, int column);

    void on_power_orb_cb_clicked();

    void on_white_orb_cb_clicked();

    void on_black_orb_cb_clicked();

    void on_summon_orb_cb_clicked();

    void on_non_elem_orb_cb_clicked();

    void on_fire_orb_cb_clicked();

    void on_ice_orb_cb_clicked();

    void on_lightning_orb_cb_clicked();

    void on_earth_orb_cb_clicked();

    void on_wind_orb_cb_clicked();

    void on_holy_orb_cb_clicked();

    void on_dark_orb_cb_clicked();

    void on_blue_orb_cb_clicked();

    void on_ability_button_pressed();

    void on_prob_button_clicked();

private:
    typedef spell_parser::map_type     spell_map ;

    Ui::ffrk_abilities *ui;

    QSettings _settings ;
    void read_settings() ;
    std::string _filepath ;
    bool _initialized ;

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

    void populate_ability_table() ;
    void setup_orb_table() ;

    orb_ranks _ranks ;

    long _class_filter ;
    short _rarity_filter ;
    short _orb_filter ;
    void update_ability_table() ;

    struct orb_data {
        ability_base *_ability ;
        int _rank ;
        int _hone ;
        int _number ;
    };

    typedef std::map<std::string, orb_data>      ability_map ;
    ability_map _cumulative_orbs ;
    int **_orbs ;
    int _max_row ;
    int _max_col ;
    orb_statistics_parser::container_type _orb_stamina ;
    orb_statistics_parser::container_type _orb_probability ;
    void update_stamina_cost() ;

    void update_orb_table() ;
};

#endif // FFRK_ABILITIES_H
