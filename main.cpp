//
//  main.cpp
//  Sprachkomposition
//
//  Created by Lukas Nowok on 23.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ReadMetadataFile.h"
//#include "ReadSpectrum.h"
#include "SortSpectra.h"

int main()
{
    //input variables
    //   = "/Users/Lukas/Documents/MD/5.Semester/Musiklehre/Sprachkomposition/sharc-angular-master"
    std::string sharcMasterPath = "/Users/Lukas/Documents/MD/5.Semester/Musiklehre/Sprachkomposition/sharc-angular-master";
    float freq = 325.3;
    std::string voice = "bass", formant = "o";
    int numFormant = 1;
    int indexClosest;
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
    };
    std::cout << "Formant Resynthesis, March 2015,  Lukas Nowok" << std::endl << std::endl << std::endl;
    //angular-master path
    std::cout << "File-Path /sharc-angular-master:" << std::endl;
    std::cin >> sharcMasterPath;
    std::cout << std::endl;
    std::cout << "Fundamental-Frequency:" << std::endl;
    std::cin >> freq;
    std::cout << std::endl;
    //voice input
    std::cout << "Voice (bass/tenor/alto/soprano):" << std::endl;
    std::cin >> voice;
    std::cout << std::endl;
    //formant input
    std::cout << "Formant (a/e/i/o/u):" << std::endl;
    std::cin >> formant;
    std::cout << std::endl;
    //formant-number input
    std::cout << "Formant-Number (1-5):" << std::endl;
    std::cin >> numFormant;
    std::cout << std::endl;
    
    

    //Vector mit ReadSpectrum Objekten (Spektrum-Daten)
    std::vector<SpectrumData> spectrumVector;
    //sorted vector mitReadSpectrum Objekten (Spektrum-Daten)
    std::vector<SpectrumData> sortedSpectra;
    //Vector mit Filenamen
    std::vector<std::string> fileNameVector;
    //String aus metadata.json
    std::string someString;
    
    //Objekt der Klasse "ReadMetadataFile" + Aufruf der Methode "getMetadata" und Übergabe an "fileNameVector"
    ReadMetadataFile reader;
    fileNameVector = reader.ReadMetadataFile::getMetadata(sharcMasterPath);
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //metadata.json-Dateien laden, Frequenz + Amplitude auslesen + speichern
    
    ReadSpectrum spectrum;
    
    for (int i = 0; i < fileNameVector.size(); i++)
    {
        someString = sharcMasterPath + fileNameVector[i];
        spectrumVector.push_back(spectrum.getSpectrumData(someString));
    }
    
    SortSpectra sorting;
    sortedSpectra = sorting.getSortedSpectra(freq, voice, formant, numFormant, spectrumVector);
    
    for (int i = 1; i < sortedSpectra.size(); i++)
    {
        indexClosest = sortedSpectra[sortedSpectra.size()-i].closest.second;
        std::cout
        << sortedSpectra[sortedSpectra.size()-i].closest.first
        << " "
        << indexClosest+1
        << " "
        << sortedSpectra[sortedSpectra.size()-i].db[indexClosest]
        << " "
        << sortedSpectra[sortedSpectra.size()-i].file
        << std::endl;
    };
};