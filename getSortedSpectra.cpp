//
//  getSortedSpectra.cpp
//  Sprachkomposition
//
//  Created by Lukas Nowok on 27.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include <stdio.h>
#include "SortSpectra.h"

std::vector <SpectrumData> SortSpectra::getSortedSpectra(float freq, std::string voice, std::string formant, int formantNum, std::vector <SpectrumData> sharcInstrumentVector)
{
    std::vector<SpectrumData> sortedSpectrum;
    
    formantNum -= 1;
    
    std::vector<std::vector<float>> formantData;
    int voiceValue;
    int formantValue;
    int resultingVoiceCode;
    
    //assign voiceValue
    if (voice == "sopran")
    {
        voiceValue = 1;
    }
    else if (voice == "alto")
    {
        voiceValue = 2;
    }
    else if (voice == "tenor")
    {
        voiceValue = 3;
    }
    else if (voice == "bass")
    {
        voiceValue = 4;
    }
    else
    {
        std::cout << "bad voice" << std::endl;
    };
    
    //assign formantValue
    if (formant == "a")
    {
        formantValue = 1;
    }
    else if (formant == "e")
    {
        formantValue = 2;
    }
    else if (formant == "i")
    {
        formantValue = 3;
    }
    else if (formant == "o")
    {
        formantValue = 4;
    }
    else if (formant == "u")
    {
        formantValue = 5;
    }
    else
    {
        std::cout << "bad formant" << std::endl;
    };
    
    //coding of voice code
    resultingVoiceCode = (voiceValue*10)+formantValue;
    
    switch (resultingVoiceCode)
    {
        case 11: formantData = SortSpectra::sopranoa;
            break;
        case 12: formantData = SortSpectra::sopranoe;
            break;
        case 13: formantData = SortSpectra::sopranoi;
            break;
        case 14: formantData = SortSpectra::sopranoo;
            break;
        case 15: formantData = SortSpectra::sopranou;
            break;
            
        case 21: formantData = SortSpectra::altoa;
            break;
        case 22: formantData = SortSpectra::altoe;
            break;
        case 23: formantData = SortSpectra::altoi;
            break;
        case 24: formantData = SortSpectra::altoo;
            break;
        case 25: formantData = SortSpectra::altou;
            break;
            
        case 31: formantData = SortSpectra::tenora;
            break;
        case 32: formantData = SortSpectra::tenore;
            break;
        case 33: formantData = SortSpectra::tenori;
            break;
        case 34: formantData = SortSpectra::tenoro;
            break;
        case 35: formantData = SortSpectra::tenoru;
            break;
            
        case 41: formantData = SortSpectra::bassa;
            break;
        case 42: formantData = SortSpectra::basse;
            break;
        case 43: formantData = SortSpectra::bassi;
            break;
        case 44: formantData = SortSpectra::basso;
            break;
        case 45: formantData = SortSpectra::bassu;
            break;
    };
    
    //scalar-factor, scale spectrum frequencies
    float scalar = (float)freq/(float)formantData[0][0];
    
    //calculate difference between formant-frequencies and all instrument-spectrum-frequencies

    formantData[formantNum][0] = formantData[formantNum][0]*scalar;
    //std::cout << tempSpectrumData[i][0] << std::endl;
    
    //number of instrument-files
    for (int i = 0; i < sharcInstrumentVector.size(); i++)
    {
        //number of partials
        for (int j = 0; j < sharcInstrumentVector[i].freq.size(); j++)
        {
            if (sharcInstrumentVector[i].freq[j] - formantData[formantNum][0] < 0)
            {
                sharcInstrumentVector[i].freqDifference[j].first = (sharcInstrumentVector[i].freq[j] - formantData[formantNum][0])* -1;
            }
            else
            {
                sharcInstrumentVector[i].freqDifference[j].first = sharcInstrumentVector[i].freq[j] - formantData[formantNum][0];
            };
            //std::cout << sharcInstrumentVector[i].freqDifference[j] << " " << sharcInstrumentVector[i].file << std::endl;
        };
    };
    
    //number of instrument-files
    for (int i = 0; i < sharcInstrumentVector.size(); i++)
    {
        sort(sharcInstrumentVector[i].freqDifference.begin(), sharcInstrumentVector[i].freqDifference.end());
        sharcInstrumentVector[i].closest.first = sharcInstrumentVector[i].freqDifference[0].first;
        sharcInstrumentVector[i].closest.second = sharcInstrumentVector[i].freqDifference[0].second;
    };
    
    sort(sharcInstrumentVector.begin(), sharcInstrumentVector.end());
    
    //std::cout << sharcInstrumentVector[0].db[0] << std::endl;
    
//    int indexClosest;
//    for (int i = 1; i < sharcInstrumentVector.size(); i++)
//    {
//        indexClosest = sharcInstrumentVector[sharcInstrumentVector.size()-i].closest.second;
//        std::cout
//        << sharcInstrumentVector[sharcInstrumentVector.size()-i].closest.first
//        << " "
//        << indexClosest+1
//        << " "
//        << sharcInstrumentVector[sharcInstrumentVector.size()-i].db[indexClosest]
//        << " "
//        << sharcInstrumentVector[sharcInstrumentVector.size()-i].file
//        << std::endl;
//    };

    
    return sharcInstrumentVector;
};





///////////////bubblesort-function///////////////
//void BubbleSort(SpectrumData &num)
//{
//    int i, j, flag = 1;    // set flag to 1 to start first pass
//    float temp;             // holding variable
//    int numLength = num.freq.size();
//    for(i = 1; (i <= numLength) && flag; i++)
//    {
//        flag = 0;
//        for (j=0; j < (numLength -1); j++)
//        {
//            if (num[j+1] > num[j])      // ascending order simply changes to <
//            {
//                temp = num[j];             // swap elements
//                num[j] = num[j+1];
//                num[j+1] = temp;
//                flag = 1;               // indicates that a swap occurred.
//            }
//        }
//    }
//    return;   //arrays are passed to functions by address; nothing is returned
//}