#pragma once

#include <QTableWidgetItem>
#include "base/ability_base.h"
#include "base/orb_ranks.h"

class ability_table_item : public QTableWidgetItem {
public:

    typedef enum {
        NAME  = 0,
        RANK  = 1,
        HONE  = 2,
        COUNT = 3
    } column_num ;

    ability_table_item()
        : QTableWidgetItem(QString()), _ability(0)
    {

    }

    ability_table_item(std::string data, ability_base* a=0)
        : QTableWidgetItem(data.c_str()), _ability(a)
    {

    }

    virtual ~ability_table_item()
    {

    }

    ability_base* getAbility() {
        return _ability ;
    }

    void setAbility(ability_base *a) {
        _ability = a ;
    }

private:

    ability_base *_ability ;
};

