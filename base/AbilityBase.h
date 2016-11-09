/**
 * Base Structure for all abilities
 */
#pragma once

#include <cstring>
#include "orb_base.h"

/**
 * Ability Classes
 */
typedef enum {
    BLM = 1<<1,     // <Black> Magic
    WHM = 1<<2,     // <White> Magic
    SMN = 1<<3,     // <Summon>ing
    CBT = 1<<4,     // <Combat>
    KNT = 1<<5,     // <Knight>
    NIN = 1<<6,     // <Ninja>
    SAM = 1<<7,     // <Samurai>
    BRD = 1<<8,     // <Bard>
    DRG = 1<<9,     // <Dragoon>
    DNC = 1<<10,    // <Dancer>
    CEL = 1<<11,    // <Celerity>
    SPT = 1<<12,    // <Support>
    MNK = 1<<13,    // <Monk>
    THF = 1<<14,    // <Thief>
    BLU = 1<<15,    // <Blue> Magic
    ENG = 1<<16,    // <Engineer>
    SPB = 1<<17,    // <Spellblade>
    DRK = 1<<18,    // <Darkness>
    SRP = 1<<19     // <Sharpshooter>
} AbilityTypeMask ;

/**
 * Base ability structure
 */
struct AbilityBase
{
    LargeMask             m_lClass;
    std::string           m_sName;
    SmallMask             m_uRarity;
    OrbList               m_xoOrb;
    // TODO: Remove these and update to new Orb structure
    std::list<OrbType>    m_xiTypes;
    std::list<SmallMask>  m_xuTypeCodes;
    std::list<OrbRarity>  m_xiRare;
    std::list<RankType>   m_xiCounts;

    bool hasOrbType(SmallMask p_iType)
    {
        OrbList::iterator itOrb     = m_xoOrb.begin();
        OrbList::iterator itOrb_end = m_xoOrb.end();
        while( itOrb != itOrb_end )
        {
            if( itOrb->m_iType == p_iType )
            {
                return true;
            }
            ++itOrb;
        }
    }
};

/**
 * Searchs the orb types and determines if this ability has
 * the type of requested orb
 */
struct check_types
{
    static bool hasOrbType(AbilityBase* m_poAbility, SmallMask m_iType) {
        std::list<SmallMask>::iterator It =
                m_poAbility->m_xuTypeCodes.begin() ;
        std::list<SmallMask>::iterator It_end =
                m_poAbility->m_xuTypeCodes.end() ;
        while( It != It_end )
        {
            if( *It & m_iType )
            {
                return true ;
            }
            It++ ;
        }
        return false ;
    }
};
