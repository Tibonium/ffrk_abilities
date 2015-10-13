#include "ffrk_abilities.h"
#include "ui_ffrk_abilities.h"

ffrk_abilities::ffrk_abilities(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ffrk_abilities)
{
    ui->setupUi(this);
}

ffrk_abilities::~ffrk_abilities()
{
    delete ui;
}
