//
//  PeakFinding.h
//  Algorithms
//
//  Created by Brandon Boldenow on 3/8/15.
//  Copyright (c) 2015 Me. All rights reserved.
//

#ifndef Algorithms_PeakFinding_h
#define Algorithms_PeakFinding_h

#include <iostream>
#include <vector>

// Lecture 1 - Peak finder algorithm
// returns an index at which the peak was found
// As designed, a peak will ALWAYS be found
template <typename T>
unsigned FindPeak(std::vector<T> &vec, unsigned start, unsigned end)
{
    int pos = start + (end - start) / 2;
    
    for(int i = start; i < end; ++i)
    {
        if(pos - 1 >= start && vec[pos - 1] > vec[pos])
            pos = FindPeak(vec, 0, pos);
        else if(pos + 1 < end && vec[pos + 1] > vec[pos])
            pos = FindPeak(vec, pos + 1, end);
    }
    
    return pos;
}

// Lecture 1 - 2D peak finding algorithm
// Global Max
// Returns the index of the global max of a column
template <typename T>
unsigned GlobalMax(std::vector<std::vector<T>> &dbl_arr, int col)
{
    int ret = 0;
    
    for(int i = 0; i < dbl_arr[col].size(); ++i)
    {
        std::cout << dbl_arr[col][i] << " ";
        if(dbl_arr[col][i] > dbl_arr[col][ret])
        {
            ret = i;
        }
        
    }
    
    return ret;
}

// return - a pair of indices into the 2D array
template <typename T>
std::pair<int, int> FindPeak2D(std::vector<std::vector<T>> &dbl_arr,
                    int col_start, int col_end)
{
    int col = col_start + (col_end - col_start) / 2;
    int row = GlobalMax(dbl_arr, col);
    
    std::pair<double, double> ret(col, row);
    
    if(col - 1 >= col_start && dbl_arr[col - 1][row] > dbl_arr[col][row])
        ret = FindPeak2D(dbl_arr, col_start, col);
    else if(col + 1 < col_end && dbl_arr[col + 1][row] > dbl_arr[col][row])
        ret = FindPeak2D(dbl_arr, col, col_end);
    
    return ret;
}

#endif
