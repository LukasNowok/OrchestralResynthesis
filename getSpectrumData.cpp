//
//  getSpectrumData.cpp
//  Sprachkomposition
//
//  Created by Lukas Nowok on 26.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include <stdio.h>
#include "ReadSpectrum.h"

SpectrumData ReadSpectrum::getSpectrumData(std::string noteFilePath)
{
    //SpectrumData-Object to be returned
    SpectrumData spectrumDataObjekt;
    
    std::fstream instrumentDataFile;
    std::string someString;
    float floatValue;
    int numValue = 0;
    
    std::pair<float, int> pushbackPair;
    
    instrumentDataFile.open(noteFilePath);
    
    while (!instrumentDataFile.eof())
    {
        getline(instrumentDataFile, someString);
        //Print Line
        //std::cout << someString << std::endl;
        if (someString.find("\"num\":") == 3)
        {
            someString.erase(0, 10).erase(someString.find(","), 1);
            numValue = std::atoi(someString.c_str());
            
            //std::cout << numValue << " ";
        }
        else if (someString.find("\"freq\":") == 3)
        {
            someString.erase(0, 11).erase(someString.find(","), 1);
            floatValue = std::stof(someString);
            
            spectrumDataObjekt.freqDifference.push_back({0.0, numValue-1});
            
            spectrumDataObjekt.freq.push_back(floatValue);
            //std::cout << spectrumDataObjekt.freq[numValue-1] << " ";
        }
        else if  (someString.find("\"amp\":") == 3)
        {
            someString.erase(0, 10).erase(someString.find(","), 1);
            floatValue = std::stof(someString);
            
            spectrumDataObjekt.amp.push_back(floatValue);
            //std::cout << spectrumDataObjekt.amp[numValue-1] << " ";
        }
        else if  (someString.find("\"db\":") == 3)
        {
            someString.erase(0, 9).erase(someString.find(","), 1);
            floatValue = std::stof(someString);
            
            spectrumDataObjekt.db.push_back(floatValue);
            //std::cout << spectrumDataObjekt.db[numValue-1] << " ";
        }
        else if  (someString.find("\"phase\":") == 3)
        {
            someString.erase(0, 12);
            floatValue =std::stof(someString);
            //std::cout << floatValue << std::endl;
            
            spectrumDataObjekt.phase.push_back(floatValue);
            //std::cout << spectrumDataObjekt.phase[numValue-1] << std::endl;
        }
        else
        {
            //do nothing
        }
    };
    
    instrumentDataFile.close();
    
    //assigning Member "file"
    spectrumDataObjekt.file = noteFilePath.erase(0, noteFilePath.find("/json/")+5);
    
    return spectrumDataObjekt;
};