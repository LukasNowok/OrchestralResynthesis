//
//  SpectrumData.cpp
//  Sprachkomposition
//
//  Created by Lukas Nowok on 30.03.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include <stdio.h>
#include "SpectrumData.h"

bool SpectrumData::operator<(const SpectrumData &s2) const
{
    if ((*this).closest < s2.closest)
        return true;
    else
        return false;
};

bool SpectrumData::operator>(const SpectrumData &s2) const
{
    if ((*this).closest > s2.closest)
        return true;
    else
        return false;
};

bool SpectrumData::comparator(const std::pair<float, int> &l, const std::pair<float, int> &r)
{
    return (l.first < r.first);
};