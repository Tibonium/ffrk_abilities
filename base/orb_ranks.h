/**
 * Orbs per level data
 */
#pragma once

#include <cstddef>
#include <vector>

class orb_ranks {
public:
    typedef std::size_t     count_type ;

    /**
     * Constructor
     */
    orb_ranks() {
        _ranks = new count_type*[16] ;
        for(int i=0; i<16; ++i) {
            _ranks[i] = new count_type[5] ;
            switch (i) {
                case 1:   // rank_2 {2, 5, 11, 23, 41} -- Base {2, 3, 6, 12, 18}
                    _ranks[i][0] = 2 ;
                    _ranks[i][1] = 5 ;
                    _ranks[i][2] = 11 ;
                    _ranks[i][3] = 23 ;
                    _ranks[i][4] = 41 ;
                    break ;
                case 2:   // rank_2a {2, 7, 17, 37, 67} -- Base {2, 5, 10, 20, 30}
                    _ranks[i][0] = 2 ;
                    _ranks[i][1] = 7 ;
                    _ranks[i][2] = 17 ;
                    _ranks[i][3] = 37 ;
                    _ranks[i][4] = 67 ;
                    break ;
                case 3:   // rank_3 {3, 9, 21, 39, 69} -- Base {3, 6, 12, 18, 30}
                    _ranks[i][0] = 3 ;
                    _ranks[i][1] = 9 ;
                    _ranks[i][2] = 21 ;
                    _ranks[i][3] = 39 ;
                    _ranks[i][4] = 69 ;
                    break ;
                case 4:   // rank_3a {3, 11, 26, 46, 91} -- Base {3, 8, 15, 30, 45}
                    _ranks[i][0] = 3 ;
                    _ranks[i][1] = 11 ;
                    _ranks[i][2] = 26 ;
                    _ranks[i][3] = 46 ;
                    _ranks[i][4] = 91 ;
                    break ;
                case 5:   // rank_3b {3, 8, 18, 38, 68} -- Base {3, 5, 10, 20, 30}
                    _ranks[i][0] = 3 ;
                    _ranks[i][1] = 8 ;
                    _ranks[i][2] = 18 ;
                    _ranks[i][3] = 38 ;
                    _ranks[i][4] = 68 ;
                    break ;
                case 6:   // rank_3c {3, 8, 18, 33, 58} -- Base {3, 5, 10, 15, 25}
                    _ranks[i][0] = 3 ;
                    _ranks[i][1] = 8 ;
                    _ranks[i][2] = 18 ;
                    _ranks[i][3] = 33 ;
                    _ranks[i][4] = 58 ;
                    break ;
                case 7:   // rank_3d {3, 9, 18, 30, 45} -- Base {3, 6, 9, 12, 15}
                    _ranks[i][0] = 3 ;
                    _ranks[i][1] = 9 ;
                    _ranks[i][2] = 18 ;
                    _ranks[i][3] = 30 ;
                    _ranks[i][4] = 45 ;
                    break ;
                case 8:   // rank_5 {5, 15, 35, 65, 115} -- Base {5, 10, 20, 30, 50}
                    _ranks[i][0] = 5 ;
                    _ranks[i][1] = 15 ;
                    _ranks[i][2] = 35 ;
                    _ranks[i][3] = 65 ;
                    _ranks[i][4] = 115 ;
                        break ;
                case 9:   // rank_6 {6, 18, 36, 66, 126} -- Base {6, 12, 18, 30, 60}
                    _ranks[i][0] = 6 ;
                    _ranks[i][1] = 18 ;
                    _ranks[i][2] = 36 ;
                    _ranks[i][3] = 66 ;
                    _ranks[i][4] = 126 ;
                    break ;
                case 10:  // rank_6a {6, 18, 42, 78, 138} -- Base {6, 12, 24, 36, 60}
                    _ranks[i][0] = 6 ;
                    _ranks[i][1] = 18 ;
                    _ranks[i][2] = 42 ;
                    _ranks[i][3] = 78 ;
                    _ranks[i][4] = 138 ;
                    break ;
                case 11:  // rank_6b {6, 16, 36, 76, 136} -- Base {6, 10, 20, 40, 60}
                    _ranks[i][0] = 6 ;
                    _ranks[i][1] = 16 ;
                    _ranks[i][2] = 36 ;
                    _ranks[i][3] = 76 ;
                    _ranks[i][4] = 136 ;
                    break ;
                case 12:  // rank_8 {8, 23, 53, 98, 173} -- Base {8, 15, 30, 45, 75}
                    _ranks[i][0] = 8 ;
                    _ranks[i][1] = 23 ;
                    _ranks[i][2] = 53 ;
                    _ranks[i][3] = 98 ;
                    _ranks[i][4] = 173 ;
                    break ;
                case 13:  // rank_10 {10, 30, 70, 130, 230} -- Base {10, 20, 40, 60, 100}
                    _ranks[i][0] = 10 ;
                    _ranks[i][1] = 30 ;
                    _ranks[i][2] = 70 ;
                    _ranks[i][3] = 130 ;
                    _ranks[i][4] = 230 ;
                    break ;
                case 14:  // rank_10a {10, 30, 60, 110, 210} -- Base {10, 20, 30, 50, 100}
                    _ranks[i][0] = 10 ;
                    _ranks[i][1] = 30 ;
                    _ranks[i][2] = 60 ;
                    _ranks[i][3] = 110 ;
                    _ranks[i][4] = 210 ;
                    break ;
                case 15:  // rank_15 {15, 45, 90, 165, 315} -- Base {15, 30, 45, 75, 150}
                    _ranks[i][0] = 15 ;
                    _ranks[i][1] = 45 ;
                    _ranks[i][2] = 90 ;
                    _ranks[i][3] = 165 ;
                    _ranks[i][4] = 315 ;
                    break ;
                default:  // rank_1 {1, 3, 6, 10, 15} -- Base {1, 2, 3, 4, 5}
                    _ranks[i][0] = 1 ;
                    _ranks[i][1] = 3 ;
                    _ranks[i][2] = 6 ;
                    _ranks[i][3] = 10 ;
                    _ranks[i][4] = 15 ;
                    break ;
            }
        }
    }

    /**
     * Destructor
     */
    virtual ~orb_ranks() {
        for(int i=0; i<16; i++) {
            delete _ranks[i] ;
        }
        delete _ranks ;
    }

    /**
     * Returns the number of orbs needed for a specific
     * leveling schema and rank.
     */
    count_type num_orbs(int schema, int rank) {
        return _ranks[schema][rank] ;
    }

    count_type **_ranks ;
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

