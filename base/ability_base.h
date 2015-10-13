/**
 * Base Structure for all abilities
 */
#pragma once

#include <list>
#include <cstring>
#include "orb_base.h"

/**
 * Ability Classes
 */
typedef enum {
    BLM = 0,    // <Black> Magic
    WHT = 1,    // <White> Magic
    SMN = 2,    // <Summon>ing
    CBT = 3,    // <Combat>
    KNT = 4,    // <Knight>
    NIN = 5,    // <Ninja>
    SAM = 6,    // <Samurai>
    BRD = 7,    // <Bard>
    DRG = 8,    // <Dragoon>
    DNC = 9,    // <Dancer>
    CEL = 10,   // <Celerity>
    SPT = 11,   // <Support>
    MNK = 12,   // <Monk>
    THF = 13,   // <Thief>
    BLU = 14,   // <Blue> Magic
    ENG = 15,   // <Engineer>
    SPB = 16    // <Spellblade>
} ability_type ;

/**
 * Base ability structure
 */
struct ability_base {
    ability_type          _class ;
    std::string           _name ;
    rarity_type           _rarity ;
    std::list<orb_type>   _types ;
    std::list<orb_rarity> _rare ;
    std::list<rank_type>  _counts ;
};
