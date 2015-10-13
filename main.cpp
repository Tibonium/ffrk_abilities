#include "ffrk_abilities.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ffrk_abilities w;
    w.show();

    return a.exec();
}
