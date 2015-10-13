/**
 * List of all Rank 1 Black Magic Abilities
 */
#pragma once

#include "../base/ability_base.h"

struct Fira : public ability_base {
    Fira() {
        _types.push_back(BLACK) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(FIRE) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_8) ;

        _rarity = STAR_2 ;
        _name = "Fira" ;
    }
};

struct Blizzara : public ability_base {
    Blizzara() {
        _types.push_back(BLACK) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(ICE) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_8) ;

        _rarity = STAR_2 ;
        _name = "Blizzara" ;
    }
};

struct Thundara : public ability_base {
    Thundara() {
        _types.push_back(BLACK) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(LIGHTNING) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_8) ;

        _rarity = STAR_2 ;
        _name = "Thundara" ;
    }
};

struct Watera : public ability_base {
    Watera() {
        _types.push_back(BLACK) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(FIRE) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_3) ;

        _types.push_back(ICE) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_3) ;

        _rarity = STAR_2 ;
        _name = "Watera" ;
    }
};

struct Bio : public ability_base {
    Bio() {
        _types.push_back(BLACK) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_5) ;

        _types.push_back(DARK) ;
        _rare.push_back(LESSER) ;
        _counts.push_back(RANK_8) ;

        _rarity = STAR_2 ;
        _name = "Bio" ;
    }
};
