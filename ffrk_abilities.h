#ifndef FFRK_ABILITIES_H
#define FFRK_ABILITIES_H

#include <QWidget>

#include <map>
#include "base/spell_parser.h"
#include "ability_table_entry.h"

namespace Ui {
class ffrk_abilities;
}

class ffrk_abilities : public QWidget
{
    Q_OBJECT

public:
    explicit ffrk_abilities(QWidget *parent = 0);
    ~ffrk_abilities();

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

private:
    typedef std::list<ability_base>     spell_list ;

    Ui::ffrk_abilities *ui;

    bool _initialized ;

    spell_list _black ;
    spell_list _white ;
    spell_list _summon ;
    spell_list _knight ;
    spell_list _combat ;
    spell_list _samurai ;
    spell_list _ninja ;
    spell_list _dragoon ;
    spell_list _thief ;
    spell_list _dancer ;
    spell_list _bard ;
    spell_list _support ;
    spell_list _spellblade ;
    spell_list _blue ;
    spell_list _celerity ;
    spell_list _monk ;
    spell_list _engineer ;

    void populate_ability_table() ;
    void setup_orb_table() ;

    orb_ranks _ranks ;

    long _class_filter ;
    short _rarity_filter ;
    void update_ability_table() ;

    struct orb_data {
        ability_base *_ability ;
        int _rank ;
        int _number ;
    };

    typedef std::map<std::string, orb_data>      ability_map ;
    ability_map _cumulative_orbs ;
    int **_orbs ;
    int _max_row ;
    int _max_col ;

    void update_orb_table() ;
};

#endif // FFRK_ABILITIES_H
