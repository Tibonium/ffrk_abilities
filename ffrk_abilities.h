#ifndef FFRK_ABILITIES_H
#define FFRK_ABILITIES_H

#include <QWidget>

#include "black_magic/blm_spells.h"

namespace Ui {
class ffrk_abilities;
}

class ffrk_abilities : public QWidget
{
    Q_OBJECT

public:
    explicit ffrk_abilities(QWidget *parent = 0);
    ~ffrk_abilities();

private:
    Ui::ffrk_abilities *ui;
};

#endif // FFRK_ABILITIES_H
