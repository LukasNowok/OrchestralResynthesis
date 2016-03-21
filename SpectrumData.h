//
//  SpectrumData.h
//  Sprachkomposition
//
//  Created by Lukas Nowok on 26.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//
//  Class to store data from one file, Access of Members throu .-operator (i.e. spectrum.freq[2])

#ifndef Sprachkomposition_SpectrumData_h
#define Sprachkomposition_SpectrumData_h

#include <string>
#include <vector>

#endif

class SpectrumData
{
public:
    std::string file;
    std::vector<float> freq;
    std::vector<float> amp;
    std::vector<float> db;
    std::vector<float> phase;
    
    std::vector<std::pair<float, int>> freqDifference;
    std::pair<float, int> closest;
    
    bool operator< (const SpectrumData &s2) const;
    bool operator> (const SpectrumData &s2) const;
    bool comparator (const std::pair<float, int> &l, const std::pair<float, int> &r);
};