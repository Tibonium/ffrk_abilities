#ifndef ORB_STASH_TABLE_H
#define ORB_STASH_TABLE_H

#include <QWidget>
#include <QCloseEvent>
#include <QSettings>
#include <QMessageBox>

#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>
#include <vector>

#include "base/OrbBase.h"

namespace Ui {
class orb_stash_table;
}

class ffrk_abilities ;

class orb_stash_table : public QWidget
{
    Q_OBJECT

public:
    explicit orb_stash_table(QWidget *parent = 0);
    ~orb_stash_table();

    void closeEvent(QCloseEvent *e) ;

    int stash_count(int type, int rank) {
        return _stash[type][rank] ;
    }

    void unhide() ;

    void add_listener(ffrk_abilities* l) {
        _listener = l ;
    }

private slots:
    void on_stash_table_cellChanged(int row, int column);

private:
    Ui::orb_stash_table *ui ;
    QSettings _settings ;
    void setup_table() ;
    void import_stash() ;
    void save_stash() ;
    OrbType find_type(std::string line) ;
    int _max_row ;
    int _max_col ;
    int **_stash ;
    ffrk_abilities* _listener ;
    std::vector<std::string> _labels ;
};

#endif // ORB_STASH_TABLE_H
