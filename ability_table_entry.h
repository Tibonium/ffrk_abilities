#pragma once

#include <QTableWidgetItem>
#include "base/ability_base.h"
#include "base/orb_ranks.h"

class ability_table_item : public QTableWidgetItem {
public:

    typedef enum {
        NAME  = 0,
        RANK  = 1,
        COUNT = 2
    } column_num ;

    ability_table_item(std::string data, ability_base* a=0)
        : QTableWidgetItem(data.c_str()), _ability(a)
    {

    }

    virtual ~ability_table_item()
    {

    }

    ability_base* ability() {
        return _ability ;
    }

private:

    ability_base *_ability ;
};

