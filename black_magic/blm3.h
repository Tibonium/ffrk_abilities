/**
 * List of all Rank 3 Black Magic Abilities
 */
#pragma once

#include "../base/ability_base.h"

struct Firaga : public ability_base {
    Firaga() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(FIRE) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_8) ;

        _rarity = STAR_3 ;
        _name = "Firaga" ;
    }
};

struct Blizzaga : public ability_base {
    Blizzaga() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(ICE) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_8) ;

        _rarity = STAR_3 ;
        _name = "Blizzaga" ;
    }
};

struct Thundaga : public ability_base {
    Thundaga() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(LIGHTNING) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_8) ;

        _rarity = STAR_3 ;
        _name = "Thundaga" ;
    }
};

struct Waterga : public ability_base {
    Waterga() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(FIRE) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _types.push_back(ICE) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_3 ;
        _name = "Waterga" ;
    }
};

struct Biora : public ability_base {
    Biora() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(DARK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _rarity = STAR_3 ;
        _name = "Biora" ;
    }
};

struct Comet : public ability_base {
    Comet() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(NON_ELEM) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _types.push_back(EARTH) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_3 ;
        _name = "Comet" ;
    }
};

struct Dark : public ability_base {
    Dark() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(NON_ELEM) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _types.push_back(DARK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_3 ;
        _name = "Dark" ;
    }
};

struct Drain : public ability_base {
    Drain() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(DARK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_8) ;

        _rarity = STAR_3 ;
        _name = "Drain" ;
    }
};

struct Gravity : public ability_base {
    Gravity() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(LIGHTNING) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _types.push_back(DARK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_3 ;
        _name = "Gravity" ;
    }
};

struct Stop : public ability_base {
    Stop() {
        _types.push_back(BLACK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(NON_ELEM) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _types.push_back(DARK) ;
        _rare.push_back(NORMAL) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_3 ;
        _name = "Stop" ;
    }
};
