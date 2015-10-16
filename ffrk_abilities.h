#ifndef FFRK_ABILITIES_H
#define FFRK_ABILITIES_H

#include <QWidget>
#include <QSettings>
#include <QCloseEvent>
#include <QMessageBox>

#include <map>
#include "ability_selector.h"
#include "ability_table_item.h"
#include "base/orb_statistics_parser.h"
#include "orb_stash_table.h"

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
    void on_ability_table_cellChanged(int row, int column);

    void on_ability_button_pressed();

    void on_prob_button_clicked();

    void on_addRow_button_clicked();

    void on_removeRow_button_clicked();

    void on_ability_table_doubleClicked(const QModelIndex &index);

    void on_show_stash_clicked();

private:
    typedef spell_parser::map_type     spell_map ;
    friend class orb_stash_table ;

    Ui::ffrk_abilities *ui ;

    QSettings _settings ;
    ability_selector* _abilities ;
    void read_settings() ;
    std::string _filepath ;
    bool _initialized ;
    void setup_orb_table() ;
    orb_stash_table *_stash_table ;

    orb_ranks _ranks ;
    int **_orbs ;
    int _max_row ;
    int _max_col ;
    orb_statistics_parser::container_type _orb_stamina ;
    orb_statistics_parser::container_type _orb_probability ;

    void update_stamina_cost() ;

    void update_orb_table() ;
    void update_orb_cell(int type, int rank) ;
    void load_table() ;
    void save_table() ;
};

#endif // FFRK_ABILITIES_H
