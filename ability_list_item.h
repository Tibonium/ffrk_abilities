#pragma once

#include <QListWidgetItem>
#include "base/AbilityBase.h"

class ability_list_item : public QListWidgetItem {
public:

    ability_list_item(std::string name, AbilityBase *a = 0)
        : QListWidgetItem(name.c_str()), _ability(a)
    {

    }

    virtual ~ability_list_item()
    {

    }

    AbilityBase* ability() {
        return _ability ;
    }

private:

    AbilityBase *_ability ;

};
