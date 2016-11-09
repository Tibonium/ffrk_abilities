/**
 * Orb enumerations and scales
 */
#pragma once

#include <list>

typedef short       SmallMask;
typedef long        LargeMask;

/**
 * Orb Rarities
 * 1 Star = Minor
 * 2 Star = Lesser
 * 3 Star = Normal
 * 4 Star = Greater
 * 5 Star = Major
 * 6 Star = Crystal
 */
typedef enum {
    MINOR   = 0,
    LESSER  = 1,
    NORMAL  = 2,
    GREATER = 3,
    MAJOR   = 4,
    CRYSTAL = 5
} OrbRarity ;

/**
 * Rarity Enumerations
 */
typedef enum {
    STAR_1 = 1<<1,
    STAR_2 = 1<<2,
    STAR_3 = 1<<3,
    STAR_4 = 1<<4,
    STAR_5 = 1<<5,
    STAR_6 = 1<<6
} OrbRarityMask ;

/**
 * Orb Type Enumerations
 */
typedef enum {
    UNKNOWN   = -1,
    POWER     = 0,
    WHITE     = 1,
    BLACK     = 2,
    SUMMON    = 3,
    NON_ELEM  = 4,
    FIRE      = 5,
    ICE       = 6,
    LIGHTNING = 7,
    EARTH     = 8,
    WIND      = 9,
    HOLY      = 10,
    DARK      = 11,
    BLUE      = 12
} OrbType ;

typedef enum {
    CPOWER     = 1<<1,
    CWHITE     = 1<<2,
    CBLACK     = 1<<3,
    CSUMMON    = 1<<4,
    CNON_ELEM  = 1<<5,
    CFIRE      = 1<<6,
    CICE       = 1<<7,
    CLIGHTNING = 1<<8,
    CEARTH     = 1<<9,
    CWIND      = 1<<10,
    CHOLY      = 1<<11,
    CDARK      = 1<<12,
    CBLUE      = 1<<13
} OrbTypeMask ;

/**
 * Orb count per level ranks
 */
typedef enum {
    RANK_1   = 0,
    RANK_2   = 1,
    RANK_2A  = 2,
    RANK_3   = 3,
    RANK_3A  = 4,
    RANK_3B  = 5,
    RANK_3C  = 6,
    RANK_3D  = 7,
    RANK_5   = 8,
    RANK_6   = 9,
    RANK_6A  = 10,
    RANK_6B  = 11,
    RANK_8   = 12,
    RANK_10  = 13,
    RANK_10A = 14,
    RANK_15  = 15
} RankType ;

/**
 * Orb specifics
 */
struct Orb
{
    OrbType         m_iType;
    OrbTypeMask     m_lTypeMask;
    OrbRarity       m_iRarity;
    OrbRarityMask   m_lRarityMask;
};

/**
 * Helper typedefs
 */
typedef std::list<Orb>      OrbList;
