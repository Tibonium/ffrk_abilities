#pragma once

#include <QTableWidgetItem>
#include "base/AbilityBase.h"
#include "base/OrbRanks.h"

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

    ability_table_item(std::string data, AbilityBase* a=0)
        : QTableWidgetItem(data.c_str()), _ability(a)
    {

    }

    virtual ~ability_table_item()
    {

    }

    AbilityBase* getAbility() {
        return _ability ;
    }

    void setAbility(AbilityBase *a) {
        _ability = a ;
    }

private:

    AbilityBase *_ability ;
};

