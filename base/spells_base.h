/**
 * Base class for all spell lists
 */
#pragma once

#include "ability_base.h"
#include <list>

struct spells_base {
    std::list<ability_base> _spells ;
};
