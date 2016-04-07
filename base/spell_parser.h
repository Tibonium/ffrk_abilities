/**
 * Parses the abilities from the spell text files
 */
#pragma once

#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <QMessageBox>

#include "ability_base.h"

class spell_parser {
public:

    typedef std::string     string_type ;
    typedef std::map<std::string, ability_base>     map_type ;

    /**
     * Constructor
     */
    spell_parser() ;

    /**
     * Destructor
     */
    virtual ~spell_parser() ;

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
    string_type parse_file(const char* filename) ;

    /**
     * Returns a pointer to the list of spells parsed from file
     */
    map_type abilities() {
        return _abilities ;
    }

private:

    /** Helper functions for parsing an individual ability **/
    string_type parse_ability(std::string line, std::fstream &fi) ;

    string_type determine_ability_class(std::string line, ability_base *a) ;

    void extract_name(std::fstream &fi, ability_base *a) ;

    string_type extract_rank(std::fstream &fi, ability_base *a) ;

    string_type extract_orb_types(std::fstream &fi, ability_base *a) ;

    string_type extract_orb_ranks(std::fstream &fi, ability_base *a) ;

    string_type extract_lvl_ranks(std::fstream &fi, ability_base *a) ;

    map_type _abilities ;

    int _line_number ;
};

