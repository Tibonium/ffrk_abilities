#include "SpellParser.h"

SpellParser::SpellParser()
    : _line_number(0)
{

}

SpellParser::~SpellParser()
{

}

SpellParser::string_type
SpellParser::parse_file(const char *filename)
{
    std::fstream fi( filename ) ;
    if( !fi.good() ) {
        string_type tmp = filename ;
        tmp += ": " ;
        tmp += std::strerror(errno) ;
        return tmp ;
    }
    _abilities.clear() ;
    string_type result ;
    _line_number = 0 ;
    while( true ) {
        std::string line ;
        std::getline(fi, line) ;
        _line_number++ ;
        if( fi.eof() ) break ;
        if(line.substr(0,5) == "Class") {
            result = parse_ability( line, fi ) ;
        }
        if( !result.empty() ) {
            QMessageBox msg ;
            std::stringstream iss ;
            iss << "Error in spell file [" << filename << "] on line:"
                << _line_number << ", " << result ;
            msg.setText( iss.str().c_str() ) ;
            msg.exec() ;
            return string_type() ;
        }
    }
    return string_type() ;
}

SpellParser::string_type
SpellParser::parse_ability(std::string line, std::fstream &fi)
{
    AbilityBase a ;
    string_type error_msg ;
    error_msg = determine_ability_class(line, &a) ;
    if( !error_msg.empty() ) return error_msg ;
    extract_name(fi, &a) ;
    error_msg = extract_rank(fi, &a) ;
    if( !error_msg.empty() ) return error_msg ;
    error_msg = extract_orb_types(fi, &a) ;
    if( !error_msg.empty() ) return error_msg ;
    error_msg = extract_orb_ranks(fi, &a) ;
    if( !error_msg.empty() ) return error_msg ;
    error_msg = extract_lvl_ranks(fi, &a) ;
    if( !error_msg.empty() ) return error_msg ;
    std::pair<map_type::iterator,bool> result = _abilities.insert( std::make_pair(a.m_sName, a) ) ;
    if( result.second ) {
        return string_type() ;
    } else {
        return string_type("Unable to insert spell with name: " + a.m_sName) ;
    }
}

void SpellParser::extract_name(std::fstream &fi, AbilityBase *a)
{
    std::string line ;
    std::getline(fi, line) ;
    _line_number++ ;
    if( line.substr(0,4) == "Name" ) {
        a->m_sName = line.substr(5) ;
    }
}

SpellParser::string_type
SpellParser::extract_rank(std::fstream &fi, AbilityBase *a)
{
    std::string line, tmprank ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    _line_number++ ;
    iss << line ;
    iss >> line ;
    if( line.substr(0,4) == "Rank" ) {
        iss >> tmprank ;
        OrbRarityMask _type = STAR_1 ;
        if( tmprank == "1" ) {
            _type = STAR_1 ;
        } else
        if( tmprank == "2" ) {
            _type = STAR_2 ;
        } else
        if( tmprank == "3" ) {
            _type = STAR_3 ;
        } else
        if( tmprank == "4" ) {
            _type = STAR_4 ;
        } else
        if( tmprank == "5" ) {
            _type = STAR_5 ;
        } else
        if( tmprank == "6" ) {
            _type = STAR_6 ;
        } else {
            return string_type(" Unknown Rarity: " + _type) ;
        }
        a->m_uRarity = _type ;
    }
    return string_type() ;
}

SpellParser::string_type
SpellParser::extract_orb_types(std::fstream &fi, AbilityBase *a)
{
    std::string line, type ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    _line_number++ ;
    if( line.substr(4,4) == "Type" ) {
        std::stringstream iss2 ;
        iss2 << line.substr(line.find('[')+1) ;
        while( !iss2.eof() ) {
            OrbType _type ;
            OrbTypeMask _code ;
            std::getline(iss2, type, ',') ;
            if( type.find(']') != std::string::npos ) {
                type.erase( type.find(']'),1 ) ;
            }
            if( type.find(' ') != std::string::npos ) {
                type.erase( type.find(' '), 1 ) ;
            }
            if( type == "Power" ) {
                _type = POWER ;
                _code = CPOWER ;
            } else
            if( type == "Black" ) {
                _type = BLACK ;
                _code = CBLACK ;
            } else
            if( type == "White" ) {
                _type = WHITE ;
                _code = CWHITE ;
            } else
            if( type == "Summon" ) {
                _type = SUMMON ;
                _code = CSUMMON ;
            } else
            if( type == "Non-Elem" ) {
                _type = NON_ELEM ;
                _code = CNON_ELEM ;
            } else
            if( type == "Fire" ) {
                _type = FIRE ;
                _code = CFIRE ;
            } else
            if( type == "Ice" ) {
                _type = ICE ;
                _code = CICE ;
            } else
            if( type == "Lightning" ) {
                _type = LIGHTNING ;
                _code = CLIGHTNING ;
            } else
            if( type == "Earth" ) {
                _type = EARTH ;
                _code = CEARTH ;
            } else
            if( type == "Wind" ) {
                _type = WIND ;
                _code = CWIND ;
            } else
            if( type == "Holy" ) {
                _type = HOLY ;
                _code = CHOLY ;
            } else
            if( type == "Dark" ) {
                _type = DARK ;
                _code = CDARK ;
            } else
            if( type == "Blue" ) {
                _type = BLUE ;
                _code = CBLUE ;
            } else {
                return string_type(" Unknown Orb Type: " + type) ;
            }
            a->m_xuTypes.push_back( _type ) ;
            a->m_xuTypeCodes.push_back( _code ) ;
        }
    }
    return string_type() ;
}

SpellParser::string_type
SpellParser::extract_orb_ranks(std::fstream &fi, AbilityBase *a)
{
    std::string line, type ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    _line_number++ ;
    if( line.substr(4,4) == "Rank" ) {
        std::stringstream iss2 ;
        iss2 << line.substr(line.find('[')+1) ;
        while( !iss2.eof() ) {
            OrbRarity _type ;
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
            if( type == "Normal" ) {
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
                return string_type(" Unknown Orb Rank: " + type ) ;
            }
            a->m_xoRare.push_back( _type ) ;
        }
    }
    return string_type() ;
}

SpellParser::string_type
SpellParser::extract_lvl_ranks(std::fstream &fi, AbilityBase *a)
{
    std::string line, type ;
    std::stringstream iss ;
    std::getline(fi, line) ;
    _line_number++ ;
    if( line.substr(0,3) == "Lvl" ) {
        std::stringstream iss2 ;
        iss2 << line.substr(line.find('[')+1) ;
        while( !iss2.eof() ) {
            RankType _type ;
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
                return string_type(" Unknown Level Schema: " + type) ;
            }
            a->m_xuCounts.push_back( _type ) ;
        }
    }
    return string_type() ;
}

SpellParser::string_type
SpellParser::determine_ability_class(std::string line, AbilityBase *a)
{
    std::string acl, junk ;
    std::stringstream tmp1 ;
    tmp1 << line ;
    tmp1 >> junk ;
    tmp1 >> acl ;
    if( acl == "Black" ) {
        a->m_lClass = BLM ;
    } else
    if( acl == "White" ) {
        a->m_lClass = WHM ;
    } else
    if( acl == "Summon" ) {
        a->m_lClass = SMN ;
    } else
    if( acl == "Combat" ) {
        a->m_lClass = CBT ;
    } else
    if( acl == "Knight" ) {
        a->m_lClass = KNT ;
    } else
    if( acl == "Ninja" ) {
        a->m_lClass = NIN ;
    } else
    if( acl == "Samurai" ) {
        a->m_lClass = SAM ;
    } else
    if( acl == "Dragoon" ) {
        a->m_lClass = DRG ;
    } else
    if( acl == "Bard" ) {
        a->m_lClass = BRD ;
    } else
    if( acl == "Dancer" ) {
        a->m_lClass = DNC ;
    } else
    if( acl == "Monk" ) {
        a->m_lClass = MNK ;
    } else
    if( acl == "Engineer" ) {
        a->m_lClass = ENG ;
    } else
    if( acl == "Celerity" ) {
        a->m_lClass = CEL ;
    } else
    if( acl == "Support" ) {
        a->m_lClass = SPT ;
    } else
    if( acl == "Spellblade" ) {
        a->m_lClass = SPB ;
    } else
    if( acl == "Thief" ) {
        a->m_lClass = THF ;
    } else
    if( acl ==  "Darkness" ) {
        a->m_lClass = DRK ;
    } else
    if( acl == "Blue" ) {
        a->m_lClass = BLU ;
    } else {
        return string_type(" Unknown Ability Class: " + acl) ;
    }
    return string_type() ;
}
