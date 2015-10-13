/**
 * List of all Rank 1 Black Magic Abilities
 */
#pragma once

#include "../base/ability_base.h"

struct Fire : public ability_base {
    Fire() {
        _types.push_back(BLACK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3B) ;

        _types.push_back(FIRE) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_1 ;
        _name = "Fire" ;
    }
};

struct Blizzard : public ability_base {
    Blizzard() {
        _types.push_back(BLACK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3B) ;

        _types.push_back(ICE) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_1 ;
        _name = "Blizzard" ;
    }
};

struct Thunder : public ability_base {
    Thunder() {
        _types.push_back(BLACK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3B) ;

        _types.push_back(LIGHTNING) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_1 ;
        _name = "Thunder" ;
    }
};

struct Water : public ability_base {
    Water() {
        _types.push_back(BLACK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_2A) ;

        _types.push_back(FIRE) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_2) ;

        _types.push_back(ICE) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_2) ;

        _rarity = STAR_1 ;
        _name = "Water" ;
    }
};

struct Confuse : public ability_base {
    Confuse() {
        _types.push_back(BLACK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3B) ;

        _types.push_back(DARK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3A) ;

        _rarity = STAR_1 ;
        _name = "Confuse" ;
    }
};

struct Poison : public ability_base {
    Poison() {
        _types.push_back(BLACK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3B) ;

        _types.push_back(DARK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_3A) ;

        _rarity = STAR_1 ;
        _name = "Poison" ;
    }
};

struct Sleep : public ability_base {
    Sleep() {
        _types.push_back(BLACK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_2A) ;

        _types.push_back(ICE) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_2) ;

        _types.push_back(DARK) ;
        _rare.push_back(MINOR) ;
        _counts.push_back(RANK_2) ;

        _rarity = STAR_1 ;
        _name = "Sleep" ;
    }
};
