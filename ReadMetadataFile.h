//
//  ReadMetadataFile.h
//  Sprachkomposition
//
//  Created by Lukas Nowok on 25.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//
//  Reads the "metadata.json" of the sharc-Database and stores the filenames into a vector

#ifndef Sprachkomposition_ReadMetadataFile_h
#define Sprachkomposition_ReadMetadataFile_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#endif

class ReadMetadataFile
{
private:
    //Vector mit Filenamen
    std::vector<std::string> fileNameVector;
public:
    //  Method to read and save all filenames in a vector
    //  Returns Vector of "
    //  arguments:
    //  Filepath of "/sharc-angular-master/"
    std::vector <std::string> getMetadata(std::string filePath);
};