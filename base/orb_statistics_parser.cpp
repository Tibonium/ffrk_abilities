#include "base/orb_statistics_parser.h"

/**
 * Constructor
 */
orb_statistics_parser::orb_statistics_parser()
    : _stamina(6,0), _probability(13,0), _line_number(0)
{

}

/**
 * Destructor
 */
orb_statistics_parser::~orb_statistics_parser()
{

}

/**
 * Parses the file and determines when to call which sub-parser
 */
int orb_statistics_parser::parse_file(const char *filename)
{
    string_type line, result ;
    _line_number = 0 ;
    std::fstream file(filename) ;
    while( true ) {
        std::getline(file, line) ;
        _line_number++ ;
        if( file.eof() ) break ;
        if( line.find("Stamina") != string_type::npos ) {
            result = parse_stamina(file) ;
        } else
        if( line.find("Probability") != string_type::npos ) {
            result = parse_probability(file) ;
        }
        if( !result.empty() ) {
            std::cout << "Error in spell file [" << filename << "] on line:"
                      << _line_number << ", " << result << std::endl ;
            return -1 ;
        }
    }
    return 1 ;
}

/**
 * Extracts the stamina per orb values
 */
orb_statistics_parser::string_type
orb_statistics_parser::parse_stamina(std::fstream &file)
{
    string_type value ;
    int type ;
    while( true ) {
        std::getline(file, value) ;
        if( file.eof() || (value[0] == '\0') ) break ;
        std::stringstream iss ;
        iss << value ;
        iss >> value ;
        if( value.find("Minor") != string_type::npos ) {
            type = MINOR ;
        } else
        if( value.find("Lesser") != string_type::npos ) {
            type = LESSER ;
        } else
        if( value.find("Normal") != string_type::npos ) {
            type = NORMAL ;
        } else
        if( value.find("Greater") != string_type::npos ) {
            type = GREATER ;
        } else
        if( value.find("Major") != string_type::npos ) {
            type = MAJOR ;
        } else
        if( value.find("Crystal") != string_type::npos ) {
            type = CRYSTAL ;
        } else {
            return string_type(" Unknown Orb Rank: " + value.substr(0, string_type::npos-1) ) ;
        }
        iss >> value ;
        if( value.find("Inf") != string_type::npos ) {
            _stamina[type] = 0 ;
        } else {
            _stamina[type] = std::atof(value.c_str()) ;
        }
    }
    return string_type() ;
}

/**
 * Extracts the probability of a specific orb type dropping
 */
orb_statistics_parser::string_type
orb_statistics_parser::parse_probability(std::fstream &file)
{
    string_type value ;
    int type ;
    while( true ) {
        std::getline(file, value) ;
        if( file.eof() || (value[0] == '\0') ) break ;
        std::stringstream iss ;
        iss << value ;
        iss >> value ;
        if( value.find("Power") != string_type::npos ) {
            type = POWER ;
        } else
        if( value.find("White") != string_type::npos ) {
            type = WHITE ;
        } else
        if( value.find("Black") != string_type::npos ) {
            type = BLACK ;
        } else
        if( value.find("Summon") != string_type::npos ) {
            type = SUMMON ;
        } else
        if( value.find("Non-Elem") != string_type::npos ) {
            type = NON_ELEM ;
        } else
        if( value.find("Fire") != string_type::npos ) {
            type = FIRE ;
        } else
        if( value.find("Ice") != string_type::npos ) {
            type = ICE ;
        } else
        if( value.find("Lightning") != string_type::npos ) {
            type = LIGHTNING ;
        } else
        if( value.find("Earth") != string_type::npos ) {
            type = EARTH ;
        } else
        if( value.find("Wind") != string_type::npos ) {
            type = WIND ;
        } else
        if( value.find("Holy") != string_type::npos ) {
            type = HOLY ;
        } else
        if( value.find("Dark") != string_type::npos ) {
            type = DARK ;
        } else
        if( value.find("Blue") != string_type::npos ) {
            type = BLUE ;
        } else {
            return string_type(" Unknown Orb Type: " + value.substr(0, string_type::npos-1) ) ;
        }
        iss >> value ;
        double v = std::atof(value.c_str()) ;
        if( v > 1.0 ) {
            return string_type(" Invalid probability value: " + value + ", value must be a normalized.") ;
        } else {
            _probability[type] = v ;
        }
    }
    return string_type() ;
}
