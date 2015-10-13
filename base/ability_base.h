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
    BLM = 0x00000001, // <Black> Magic
    WHM = 0x00000002, // <White> Magic
    SMN = 0x00000004, // <Summon>ing
    CBT = 0x00000008, // <Combat>
    KNT = 0x00000010, // <Knight>
    NIN = 0x00000020, // <Ninja>
    SAM = 0x00000040, // <Samurai>
    BRD = 0x00000080, // <Bard>
    DRG = 0x00000100, // <Dragoon>
    DNC = 0x00000200, // <Dancer>
    CEL = 0x00000400, // <Celerity>
    SPT = 0x00000800, // <Support>
    MNK = 0x00001000, // <Monk>
    THF = 0x00002000, // <Thief>
    BLU = 0x00004000, // <Blue> Magic
    ENG = 0x00008000, // <Engineer>
    SPB = 0x00010000  // <Spellblade>
} ability_type ;

/**
 * Base ability structure
 */
struct ability_base {
    long                  _class ;
    std::string           _name ;
    short                 _rarity ;
    std::list<orb_type>   _types ;
    std::list<orb_rarity> _rare ;
    std::list<rank_type>  _counts ;
};
