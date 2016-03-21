//
//  SortSpectra.h
//  Sprachkomposition
//
//  Created by Lukas Nowok on 26.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#ifndef Sprachkomposition_SortSpectra_h
#define Sprachkomposition_SortSpectra_h

#include <iostream>
#include <vector>
#include "ReadSpectrum.h"
#include <algorithm>


#endif

class SortSpectra
{
private:
    //Formant Data (voice+formant), freq (Hz), amp (db), bandwidth (Hz)
    std::vector<std::vector<float>> sopranoa {{800, 0, 80}, {1150, -6, 90}, {2900, -32, 120}, {3900, -20, 130}, {4950, -50, 140}};
    std::vector<std::vector<float>> sopranoe {{350, 0, 60}, {2000, -20, 100}, {2800, -15, 120}, {3600, -40, 150}, {4950, -56, 200}};
    std::vector<std::vector<float>> sopranoi {{270, 0, 60}, {2140, -12, 90}, {2950, -26, 100}, {3900, -26, 120}, {4950, -44, 120}};
    std::vector<std::vector<float>> sopranoo {{450, 0, 40}, {800, -11, 80}, {2830, -22, 100}, {3800, -22, 120}, {4950, -50, 120}};
    std::vector<std::vector<float>> sopranou {{325, 0, 50}, {700, -12, 60}, {2700, -9, 170}, {3800, -12, 180}, {4950, -18, 200}};
    
    std::vector<std::vector<float>> altoa {{800, 0, 80}, {1150, -4, 90}, {2800, -20, 120}, {3500, -36, 130}, {4950, -60, 140}};
    std::vector<std::vector<float>> altoe {{400, 0, 60}, {1600, -24, 80}, {2700, -30, 120}, {3300, -35, 150}, {4950, -60, 200}};
    std::vector<std::vector<float>> altoi {{350, 0, 50}, {1700, -20, 100}, {2700, -30, 120}, {3700, -36, 150}, {4950, -60, 200}};
    std::vector<std::vector<float>> altoo {{450, 0, 70}, {800, -9, 80}, {2830, -16, 100}, {3500, -28, 130}, {4950, -55, 135}};
    std::vector<std::vector<float>> altou {{325, 0, 50}, {700, -12, 60}, {2530, -30, 170}, {3500, -40, 180}, {4950, -64, 200}};
    
    std::vector<std::vector<float>> tenora {{650, 0, 80}, {1080, -6, 120}, {2650, -7, 120}, {2900, -8, 130}, {3250, -22, 140}};
    std::vector<std::vector<float>> tenore {{400, 0, 70}, {1700, -14, 80}, {2600, -12, 120}, {3200, -14, 120}, {3580, -20, 120}};
    std::vector<std::vector<float>> tenori {{290, 0, 40}, {1870, -15, 90}, {2800, -18, 100}, {2800, -12, 130}, {3540, -30, 120}};
    std::vector<std::vector<float>> tenoro {{400, 0, 70}, {800, -10, 80}, {2600, -12, 100}, {2800, -12, 130}, {3000, -26, 135}};
    std::vector<std::vector<float>> tenoru {{350, 0, 40}, {600, -12, 60}, {2700, -17, 100}, {2900, -14, 120}, {3300, -26, 120}};
    
    std::vector<std::vector<float>> bassa {{600, 0, 60}, {1040, -7, 70}, {2250, -9, 110}, {2450, -9, 120}, {2750, -20, 130}};
    std::vector<std::vector<float>> basse {{400, 0, 40}, {1620, -12, 80}, {2400, -9, 100}, {2800, -12, 120}, {3150, -18, 120}};
    std::vector<std::vector<float>> bassi {{250, 0, 60}, {1750, -30, 90}, {2600, -16, 100}, {3050, -22, 120}, {3340, -28, 120}};
    std::vector<std::vector<float>> basso {{400, 0, 40}, {750, -11, 80}, {2400, -21, 100}, {2600, -20, 120}, {2900, -40, 120}};
    std::vector<std::vector<float>> bassu {{350, 0, 40}, {600, -20, 80}, {2400, -32, 100}, {2675, -28, 120}, {2950, -36, 120}};

    
public:
    std::vector <SpectrumData> getSortedSpectra(float freq, std::string voice, std::string formant, int formantNum, std::vector <SpectrumData> sharcInstrumentVector);
    void bubblesort(std::vector<SpectrumData> &w);
};