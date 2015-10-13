#include "spell_parser.h"

spell_parser::spell_parser(const char *filename)
{
    parse_file( filename ) ;
}

spell_parser::~spell_parser()
{

}

void spell_parser::parse_file(const char *filename)
{
    std::fstream fi( filename ) ;
    while( true ) {
        std::string line ;
        std::getline(fi, line) ;
        if( fi.eof() ) break ;
        if(line.substr(0,7) == "Ability") {
            parse_ability( line, fi ) ;
        }
    }
}

void spell_parser::parse_ability(std::string line, std::fstream &fi)
{
    ability_base a ;
    determine_ability_class(line, &a) ;
    extract_name(fi, &a) ;
    extract_rank(fi, &a) ;
    extract_orb_types(fi, &a) ;
    extract_orb_ranks(fi, &a) ;
    extract_lvl_ranks(fi, &a) ;
    _abilities._spells.push_back( a ) ;
}

void spell_parser::extract_name(std::fstream &fi, ability_base *a)
{
    std::string line ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    iss << line ;
    iss >> line ;
    if( line.substr(0,4) == "Name" ) {
        iss >> a->_name ;
    }
}

void spell_parser::extract_rank(std::fstream &fi, ability_base *a)
{
    std::string line, tmprank ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    iss << line ;
    iss >> line ;
    if( line.substr(0,4) == "Rank" ) {
        iss >> tmprank ;
        a->_rarity = rarity_type(std::atoi(tmprank.c_str())) ;
    }
}

void spell_parser::extract_orb_types(std::fstream &fi, ability_base *a)
{
    std::string line, type ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    if( line.substr(4,4) == "Type" ) {
        std::stringstream iss2 ;
        iss2 << line.substr(line.find('[')+1) ;
        while( !iss2.eof() ) {
            orb_type _type ;
            std::getline(iss2, type, ',') ;
            if( type.find(']') != std::string::npos ) {
                type.erase( type.find(']'),1 ) ;
            }
            if( type.find(' ') != std::string::npos ) {
                type.erase( type.find(' '), 1 ) ;
            }
            if( type == "Power" ) {
                _type = POWER ;
            } else
            if( type == "Black" ) {
                _type = BLACK ;
            } else
            if( type == "White" ) {
                _type = WHITE ;
            } else
            if( type == "Summon" ) {
                _type = SUMMON ;
            } else
            if( type == "Non-Elem" ) {
                _type = NON_ELEM ;
            } else
            if( type == "Fire" ) {
                _type = FIRE ;
            } else
            if( type == "Ice" ) {
                _type = ICE ;
            } else
            if( type == "Lightning" ) {
                _type = LIGHTNING ;
            } else
            if( type == "Earth" ) {
                _type = EARTH ;
            } else
            if( type == "Wind" ) {
                _type = WIND ;
            } else
            if( type == "Holy" ) {
                _type = HOLY ;
            } else
            if( type == "Dark" ) {
                _type = DARK ;
            } else
            if( type == "Blue" ) {
                _type = BLUE ;
            } else {
                std::cout << "Unknown Orb Type: " << type << std::endl ;
            }
            a->_types.push_back( _type ) ;
        }
    }
}

void spell_parser::extract_orb_ranks(std::fstream &fi, ability_base *a)
{
    std::string line, type ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    if( line.substr(4,4) == "Rank" ) {
        std::stringstream iss2 ;
        iss2 << line.substr(line.find('[')+1) ;
        while( !iss2.eof() ) {
            orb_rarity _type ;
            std::getline(iss2, type, ',') ;
            if( type.find(']') != std::string::npos ) {
                type.erase( type.find(']'), 1 ) ;
            }
            if( type.find(' ') != std::string::npos ) {
                type.erase( type.find(' '), 1 ) ;
            }
            if( type == "Minor" ) {
                _type = MINOR ;
            } else
            if( type == "Lesser" ) {
                _type = LESSER ;
            } else
            if( type == "NORMAL" ) {
                _type = NORMAL ;
            } else
            if( type == "Greater" ) {
                _type = GREATER ;
            } else
            if( type == "Major" ) {
                _type = MAJOR ;
            } else
            if( type == "Crystal" ) {
                _type = CRYSTAL ;
            } else {
                std::cout << "Unknown Orb Rank: " << type << std::endl ;
            }
            a->_rare.push_back( _type ) ;
        }
    }
}

void spell_parser::extract_lvl_ranks(std::fstream &fi, ability_base *a)
{
    std::string line, type ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    if( line.substr(0,3) == "Lvl" ) {
        std::stringstream iss2 ;
        iss2 << line.substr(line.find('[')+1) ;
        while( !iss2.eof() ) {
            rank_type _type ;
            std::getline(iss2, type, ',') ;
            if( type.find(']') != std::string::npos ) {
                type.erase( type.find(']'), 1 ) ;
            }
            if( type.find(' ') != std::string::npos ) {
                type.erase( type.find(' '), 1 ) ;
            }
            if( type == "1" ) {
                _type = RANK_1 ;
            } else
            if( type == "2" ) {
                _type = RANK_2 ;
            } else
            if( type == "2A" ) {
                _type = RANK_2A ;
            } else
            if( type == "3" ) {
                _type = RANK_3 ;
            } else
            if( type == "3A" ) {
                _type = RANK_3A ;
            } else
            if( type == "3B" ) {
                _type = RANK_3B ;
            } else
            if( type == "3C" ) {
                _type = RANK_3C ;
            } else
            if( type == "3D" ) {
                _type = RANK_3D ;
            } else
            if( type == "5" ) {
                _type = RANK_5 ;
            } else
            if( type == "6" ) {
                _type = RANK_6 ;
            } else
            if( type == "6A" ) {
                _type = RANK_6A ;
            } else
            if( type == "6B" ) {
                _type = RANK_6B ;
            } else
            if( type == "8" ) {
                _type = RANK_8 ;
            } else
            if( type == "10" ) {
                _type = RANK_10 ;
            } else
            if( type == "10A" ) {
                _type = RANK_10A ;
            } else
            if( type == "15" ) {
                _type = RANK_15 ;
            } else {
                std::cout << "Unknown Level Rank: " << type << std::endl ;
            }
            a->_counts.push_back( _type ) ;
        }
    }
}

void spell_parser::determine_ability_class(std::string line, ability_base *a)
{
    std::string acl, junk ;
    std::stringstream tmp1 ;
    tmp1 << line ;
    tmp1 >> junk ;
    tmp1 >> acl ;
    if( acl == "Black" ) {
        a->_class = BLM ;
    } else
    if( acl == "White" ) {
        a->_class = WHT ;
    } else
    if( acl == "Summon" ) {
        a->_class = SMN ;
    } else
    if( acl == "Combat" ) {
        a->_class = CBT ;
    } else
    if( acl == "Knight" ) {
        a->_class = KNT ;
    } else
    if( acl == "Ninja" ) {
        a->_class = NIN ;
    } else
    if( acl == "Samurai" ) {
        a->_class = SAM ;
    } else
    if( acl == "Dragoon" ) {
        a->_class = DRG ;
    } else
    if( acl == "Bard" ) {
        a->_class = BRD ;
    } else
    if( acl == "Dancer" ) {
        a->_class = DNC ;
    } else
    if( acl == "Monk" ) {
        a->_class = MNK ;
    } else
    if( acl == "Engineer" ) {
        a->_class = ENG ;
    } else
    if( acl == "Celerity" ) {
        a->_class = CEL ;
    } else
    if( acl == "Support" ) {
        a->_class = SPT ;
    } else
    if( acl == "Spellblade" ) {
        a->_class = SPB ;
    } else
    if( acl == "Thief" ) {
        a->_class = THF ;
    } else
    if( acl == "Blue" ) {
        a->_class = BLU ;
    } else
    if( acl == "White" ) {
        a->_class = WHT ;
    } else {
        std::cout << "Unknown Ability Class: " << acl << std::endl ;
    }
}
