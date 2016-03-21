//
//  ReadSpectrum.h
//  Sprachkomposition
//
//  Created by Lukas Nowok on 26.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//
//  Class to Read out Note-Files and store Data in Vector "spectrumData"

#ifndef Sprachkomposition_ReadSpectrum_h
#define Sprachkomposition_ReadSpectrum_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SpectrumData.h"

#endif

class ReadSpectrum
{
private:
    std::vector<std::vector<float>> spectrumData;
public:
    //  Method to pass Spectrum-Data as "SpectrumData"-Object
    //  arguments:
    //  Filepath of Note-File
    SpectrumData getSpectrumData(std::string noteFilePath);
};