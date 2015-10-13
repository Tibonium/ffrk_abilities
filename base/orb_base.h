/**
 * Orb enumerations and scales
 */
#pragma once

/**
 * Rarity Enumerations
 */
typedef enum {
    STAR_1 = 1,
    STAR_2 = 2,
    STAR_3 = 3,
    STAR_4 = 4,
    STAR_5 = 5,
    STAR_6 = 6
} rarity_type ;

/**
 * Orb Type Enumerations
 */
typedef enum {
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
} orb_type ;

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
    MINOR   = 1,
    LESSER  = 2,
    NORMAL  = 3,
    GREATER = 4,
    MAJOR   = 5,
    CRYSTAL = 6
} orb_rarity ;

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
} rank_type ;
