/**
 * Orbs per level data
 */
#pragma once

#include <cstddef>
#include <vector>

class OrbRanks
{
public:
    typedef std::size_t     CountType ;

    /**
     * Constructor
     */
    OrbRanks() {
        m_xxiRanks = new CountType*[16] ;
        for(int i=0; i<16; ++i) {
            m_xxiRanks[i] = new CountType[5] ;
            switch (i) {
                case 1:   // rank_2 {2, 5, 11, 23, 41} -- Base {2, 3, 6, 12, 18}
                    m_xxiRanks[i][0] = 2 ;
                    m_xxiRanks[i][1] = 5 ;
                    m_xxiRanks[i][2] = 11 ;
                    m_xxiRanks[i][3] = 23 ;
                    m_xxiRanks[i][4] = 41 ;
                    break ;
                case 2:   // rank_2a {2, 7, 17, 37, 67} -- Base {2, 5, 10, 20, 30}
                    m_xxiRanks[i][0] = 2 ;
                    m_xxiRanks[i][1] = 7 ;
                    m_xxiRanks[i][2] = 17 ;
                    m_xxiRanks[i][3] = 37 ;
                    m_xxiRanks[i][4] = 67 ;
                    break ;
                case 3:   // rank_3 {3, 9, 21, 39, 69} -- Base {3, 6, 12, 18, 30}
                    m_xxiRanks[i][0] = 3 ;
                    m_xxiRanks[i][1] = 9 ;
                    m_xxiRanks[i][2] = 21 ;
                    m_xxiRanks[i][3] = 39 ;
                    m_xxiRanks[i][4] = 69 ;
                    break ;
                case 4:   // rank_3a {3, 11, 26, 46, 91} -- Base {3, 8, 15, 30, 45}
                    m_xxiRanks[i][0] = 3 ;
                    m_xxiRanks[i][1] = 11 ;
                    m_xxiRanks[i][2] = 26 ;
                    m_xxiRanks[i][3] = 46 ;
                    m_xxiRanks[i][4] = 91 ;
                    break ;
                case 5:   // rank_3b {3, 8, 18, 38, 68} -- Base {3, 5, 10, 20, 30}
                    m_xxiRanks[i][0] = 3 ;
                    m_xxiRanks[i][1] = 8 ;
                    m_xxiRanks[i][2] = 18 ;
                    m_xxiRanks[i][3] = 38 ;
                    m_xxiRanks[i][4] = 68 ;
                    break ;
                case 6:   // rank_3c {3, 8, 18, 33, 58} -- Base {3, 5, 10, 15, 25}
                    m_xxiRanks[i][0] = 3 ;
                    m_xxiRanks[i][1] = 8 ;
                    m_xxiRanks[i][2] = 18 ;
                    m_xxiRanks[i][3] = 33 ;
                    m_xxiRanks[i][4] = 58 ;
                    break ;
                case 7:   // rank_3d {3, 9, 18, 30, 45} -- Base {3, 6, 9, 12, 15}
                    m_xxiRanks[i][0] = 3 ;
                    m_xxiRanks[i][1] = 9 ;
                    m_xxiRanks[i][2] = 18 ;
                    m_xxiRanks[i][3] = 30 ;
                    m_xxiRanks[i][4] = 45 ;
                    break ;
                case 8:   // rank_5 {5, 15, 35, 65, 115} -- Base {5, 10, 20, 30, 50}
                    m_xxiRanks[i][0] = 5 ;
                    m_xxiRanks[i][1] = 15 ;
                    m_xxiRanks[i][2] = 35 ;
                    m_xxiRanks[i][3] = 65 ;
                    m_xxiRanks[i][4] = 115 ;
                        break ;
                case 9:   // rank_6 {6, 18, 36, 66, 126} -- Base {6, 12, 18, 30, 60}
                    m_xxiRanks[i][0] = 6 ;
                    m_xxiRanks[i][1] = 18 ;
                    m_xxiRanks[i][2] = 36 ;
                    m_xxiRanks[i][3] = 66 ;
                    m_xxiRanks[i][4] = 126 ;
                    break ;
                case 10:  // rank_6a {6, 18, 42, 78, 138} -- Base {6, 12, 24, 36, 60}
                    m_xxiRanks[i][0] = 6 ;
                    m_xxiRanks[i][1] = 18 ;
                    m_xxiRanks[i][2] = 42 ;
                    m_xxiRanks[i][3] = 78 ;
                    m_xxiRanks[i][4] = 138 ;
                    break ;
                case 11:  // rank_6b {6, 16, 36, 76, 136} -- Base {6, 10, 20, 40, 60}
                    m_xxiRanks[i][0] = 6 ;
                    m_xxiRanks[i][1] = 16 ;
                    m_xxiRanks[i][2] = 36 ;
                    m_xxiRanks[i][3] = 76 ;
                    m_xxiRanks[i][4] = 136 ;
                    break ;
                case 12:  // rank_8 {8, 23, 53, 98, 173} -- Base {8, 15, 30, 45, 75}
                    m_xxiRanks[i][0] = 8 ;
                    m_xxiRanks[i][1] = 23 ;
                    m_xxiRanks[i][2] = 53 ;
                    m_xxiRanks[i][3] = 98 ;
                    m_xxiRanks[i][4] = 173 ;
                    break ;
                case 13:  // rank_10 {10, 30, 70, 130, 230} -- Base {10, 20, 40, 60, 100}
                    m_xxiRanks[i][0] = 10 ;
                    m_xxiRanks[i][1] = 30 ;
                    m_xxiRanks[i][2] = 70 ;
                    m_xxiRanks[i][3] = 130 ;
                    m_xxiRanks[i][4] = 230 ;
                    break ;
                case 14:  // rank_10a {10, 30, 60, 110, 210} -- Base {10, 20, 30, 50, 100}
                    m_xxiRanks[i][0] = 10 ;
                    m_xxiRanks[i][1] = 30 ;
                    m_xxiRanks[i][2] = 60 ;
                    m_xxiRanks[i][3] = 110 ;
                    m_xxiRanks[i][4] = 210 ;
                    break ;
                case 15:  // rank_15 {15, 45, 90, 165, 315} -- Base {15, 30, 45, 75, 150}
                    m_xxiRanks[i][0] = 15 ;
                    m_xxiRanks[i][1] = 45 ;
                    m_xxiRanks[i][2] = 90 ;
                    m_xxiRanks[i][3] = 165 ;
                    m_xxiRanks[i][4] = 315 ;
                    break ;
                default:  // rank_1 {1, 3, 6, 10, 15} -- Base {1, 2, 3, 4, 5}
                    m_xxiRanks[i][0] = 1 ;
                    m_xxiRanks[i][1] = 3 ;
                    m_xxiRanks[i][2] = 6 ;
                    m_xxiRanks[i][3] = 10 ;
                    m_xxiRanks[i][4] = 15 ;
                    break ;
            }
        }
    }

    /**
     * Destructor
     */
    virtual ~OrbRanks() {
        for(int i=0; i<16; i++) {
            delete m_xxiRanks[i] ;
        }
        delete m_xxiRanks ;
    }

    /**
     * Returns the number of orbs needed for a specific
     * leveling schema and rank.
     */
    CountType num_orbs(int schema, int rank) {
        return m_xxiRanks[schema][rank] ;
    }

    CountType **m_xxiRanks ;
};

/**
    // rank_1 {1, 3, 6,10, 15} -- Base {1, 2, 3, 4, 5}

    // rank_2 {2, 5, 11, 23, 41} -- Base {2, 3, 6, 12, 18}
    // rank_2a {2, 7, 17, 37, 67} -- Base {2, 5, 10, 20, 30}

    // rank_3 {3, 9, 21, 39, 69} -- Base {3, 6, 12, 18, 30}
    // rank_3a {3, 11, 26, 46, 91} -- Base {3, 8, 15, 30, 45}
    // rank_3b {3, 8, 18, 38, 68} -- Base {3, 5, 10, 20, 30}
    // rank_3c {3, 8, 18, 33, 58} -- Base {3, 5, 10, 15, 25}
    // rank_3d {3, 9, 18, 30, 45} -- Base {3, 6, 9, 12, 15}

    // rank_5 {5, 15, 35, 65, 115} -- Base {5, 10, 20, 30, 50}

    // rank_6 {6, 18, 36, 66, 126} -- Base {6, 12, 18, 30, 60}
    // rank_6a {6, 18, 42, 78, 138} -- Base {6, 12, 24, 36, 60}
    // rank_6b {6, 16, 36, 76, 136} -- Base {6, 10, 20, 40, 60}

    // rank_8 {8, 23, 63, 108, 183} -- Base {8, 15, 30, 45, 75}

    // rank_10 {10, 30, 70, 130, 230} -- Base {10, 20, 40, 60, 100}
    // rank_10a {10, 30, 60, 110, 210} -- Base {10, 20, 30, 50, 100}

    // rank_15 {15, 45, 90, 165, 315} -- Base {15, 30, 45, 75, 150}
**/

