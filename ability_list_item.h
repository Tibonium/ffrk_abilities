#pragma once

#include <QListWidgetItem>
#include "base/ability_base.h"

class ability_list_item : public QListWidgetItem {
public:

    ability_list_item(std::string name, ability_base *a = 0)
        : QListWidgetItem(name.c_str()), _ability(a)
    {

    }

    virtual ~ability_list_item()
    {

    }

    ability_base* ability() {
        return _ability ;
    }

private:

    ability_base *_ability ;

};
