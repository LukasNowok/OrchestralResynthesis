//
//  getMetadata.cpp
//  Sprachkomposition
//
//  Created by Lukas Nowok on 25.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include <stdio.h>
#include "ReadMetadataFile.h"

std::vector <std::string> ReadMetadataFile::getMetadata(std::string filePath)
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //metadata.json auslesen: Alle .json Dateinamen in ein Vector speichern
    
    
    //Variable für "sting.find"
    unsigned long pos = 1000;
    //Variable für while-Bedingung
    char testChar = 'a';
    //Temporärer Sting
    std::string tempString;
    //String aus metadata.json
    std::string someString;
    //Inputfilestream metadata.json (Liste aller Files)
    std::ifstream metaData;
    metaData.open(filePath+"/json/metadata.json");
    
    //std::cout << filePath+"/json/metadata.json" << std::endl;
    
    //"get Line-by-Line"
    while (!metaData.eof())
    {
        //Zeile auslesen
        getline(metaData, someString);
        //Find "file:"
        pos = someString.find("\"file\":");
        if (pos < 50)
        {
            //Zählervariable
            int i = 13;
            while (testChar != '\"')
            {
                testChar = someString[i];
                i++;
            }
            //std::cout << i-14 << " while schleife! " << std::endl;
            testChar = 'a';
            //Löscht alle Zeicen von 0-13 ("file... bis "json...)
            someString.erase(0, 13);
            //Löscht Anführungsstriche am Ende
            someString.erase(i-14, 1);
            //Fügt / vor String hinzu
            someString = "/"+someString;
            //
            //std::cout << someString << " " << std::endl;
            //Speichert formatierten String in fileNameVector
            ReadMetadataFile::fileNameVector.push_back(someString);
        };
    }
    metaData.close();
    return ReadMetadataFile::fileNameVector;
};