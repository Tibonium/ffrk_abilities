/**
 * Parses the abilities from the spell text files
 */
#pragma once

#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>

#include "spells_base.h"

class spell_parser {
public:

    /**
     * Constructor
     */
    spell_parser(const char* filename) ;

    /**
     * Destructor
     */
    virtual ~spell_parser() ;

    /**
     * Returns a pointer to the list of spells parsed from file
     */
    std::list<ability_base>* abilities() {
        return &_abilities._spells ;
    }

private:

    /**
     * Parses the files as the following format:
     *
     * Ability: <Black,White,etc....>
     * Name: <Ability Name>
     * Rank: <Rarity>
     * Orb_Types: [Orb_Type1, Orb_Type2, ...]
     * Orb_Ranks: [Orb_Rank1, Orb_Rank2, ...]
     * Lvl_Ranks: [Rank1, Rank2, ...]
     *
     * See orb_base and orb_counts for specific requirements on naming and
     * meaning.
     */
    void parse_file(const char* filename) ;

    /** Helper functions for parsing an individual ability **/
    void parse_ability(std::string line, std::fstream &fi) ;

    void determine_ability_class(std::string line, ability_base *a) ;

    void extract_name(std::fstream &fi, ability_base *a) ;

    void extract_rank(std::fstream &fi, ability_base *a) ;

    void extract_orb_types(std::fstream &fi, ability_base *a) ;

    void extract_orb_ranks(std::fstream &fi, ability_base *a) ;

    void extract_lvl_ranks(std::fstream &fi, ability_base *a) ;

    spells_base _abilities ;
};

