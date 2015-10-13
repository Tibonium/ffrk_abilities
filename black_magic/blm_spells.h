#pragma once

#include "../base/spells_base.h"
#include "blm1.h"
#include "blm2.h"
#include "blm3.h"
#include "blm4.h"
#include "blm5.h"
#include "blm6.h"

struct blm_spells : public spells_base {
    blm_spells() {
        // Rank 1
        _spells.push_back( Fire() ) ;
        _spells.push_back( Blizzard() ) ;
        _spells.push_back( Thunder() ) ;
        _spells.push_back( Water() ) ;
        _spells.push_back( Confuse() ) ;
        _spells.push_back( Poison() ) ;
        _spells.push_back( Sleep() ) ;

        // Rank 2
        _spells.push_back( Fira() ) ;
        _spells.push_back( Blizzara() ) ;
        _spells.push_back( Thundara() ) ;
        _spells.push_back( Watera() ) ;
        _spells.push_back( Bio() ) ;

        // Rank 3
        _spells.push_back( Biora() ) ;
        _spells.push_back( Firaga() ) ;
        _spells.push_back( Blizzaga() ) ;
        _spells.push_back( Thundaga() ) ;
        _spells.push_back( Waterga() ) ;
        _spells.push_back( Comet() ) ;
        _spells.push_back( Dark() ) ;
        _spells.push_back( Drain() ) ;
        _spells.push_back( Gravity() ) ;
        _spells.push_back( Stop() ) ;
    }
};
