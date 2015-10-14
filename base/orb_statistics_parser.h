/**
 * Parsers the orb_statistics files and stores the data
 */
#pragma once

#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>

#include "orb_base.h"

class orb_statistics_parser {
public:
    typedef std::vector<double>     container_type ;
    typedef std::string             string_type ;

    /**
     * Constructor
     */
    orb_statistics_parser() ;

    /**
     * Destructor
     */
    virtual ~orb_statistics_parser() ;

    /**
     * Primary parser
     */
    int parse_file(const char* filename) ;

    /**
     * Accessor to the stamina container
     */
    container_type stamina() {
        return _stamina ;
    }

    /**
     * Accessor to the probability container
     */
    container_type probability() {
        return _probability ;
    }

private:

    /**
     * Sub-parser for stamina values
     */
    string_type parse_stamina(std::fstream &file) ;

    /**
     * Sub-parser for probability values
     */
    string_type parse_probability(std::fstream &file) ;

    /**
     * Container of all stamina per orb values
     */
    container_type _stamina ;

    /**
     * Container of all orb drop probabilities
     */
    container_type _probability ;

    /**
     * Keeps track of current line number, used in error handling
     */
    int _line_number ;
};
