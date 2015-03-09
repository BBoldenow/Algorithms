//
//  Sorting.h
//  Algorithms
//
//  Created by Brandon Boldenow on 3/8/15.
//  Copyright (c) 2015 Me. All rights reserved.
//

#ifndef Algorithms_Sorting_h
#define Algorithms_Sorting_h
#include <vector>

// Regular insertion sort
template <typename T>
void InsertionSort(std::vector<T> &vec)
{
    for(int i = 1; i < vec.size(); ++i)
    {
        T key = vec[i];
        
        // As long as i - 1 is valid and greater than
        // the current, swap it with the current key's position
        while(i - 1 >= 0 && vec[i - 1] > key)
        {
            vec[i] = vec[i-1];
            vec[i - 1] = key;
            --i;
        }
    }
}

// Binary insertion sort
template <typename T>
void InsertionSort_Binary(std::vector<T> &vec)
{
    for(unsigned int i = 1; i < vec.size(); ++i)
    {
        T key = vec[i];
        
        // 'i' is the max position aka. "right"
        unsigned int left = 0;
        unsigned int right = i;
        
        // As long as right is greater than left
        // check the middle of the range against the
        // current key. If the key is greater than
        // the current mid-point, adjust the min "left" position
        // otherwise adjust the max "right" position
        while(left < right)
        {
            unsigned int const mid = (left + right) / 2;
            
            if(key > vec[mid])
                left = mid + 1;
            else
                right = mid;
        }
        
        // Perform the swaps from right 'i' to left
        for(unsigned int j = i; j > left; --j)
        {
            vec[j] = vec[j - 1];
            vec[j - 1] = key;
        }
    }
}

template <typename T>
std::vector<T> Merge(std::vector<T> &vec, std::vector<T> &left, std::vector<T> &right)
{
    // define local variables, including the return vector
    std::vector<T> ret;
    unsigned int l = 0;
    unsigned int r = 0;
    
    // As long as left and right are smaller than their vectors
    // figure out which value to sort into the return vector
    while(l < left.size() && r < right.size())
    {
        if(left[l] < right[r])
        {
            ret.push_back(left[l]);
            ++l;
        }
        else
        {
            ret.push_back(right[r]);
            ++r;
        }
    }
    
    // Make sure that the remaining vector values get added to the return
    while(l < left.size())
        ret.push_back(left[l++]);
    
    while(r < right.size())
        ret.push_back(right[r++]);
    
    // Set the original vector to the return vector
    vec = ret;
    
    return ret;
}

// Merge sort
template <typename T>
std::vector<T> MergeSort(std::vector<T> &vec)
{
    // if there's only a single element, there's nothing to sort
    if(vec.size() == 1)
        return vec;
    
    // get the middle of the vector, and construct the left/right vectors
    typename std::vector<T>::iterator middle = vec.begin() + (vec.size() / 2);
    std::vector<T> left(vec.begin(), middle);
    std::vector<T> right(middle, vec.end());

    // Recursively call the merge insertion function on the two smaller vectors
    // This will break them down smaller and smaller until they are size one
    left = MergeSort(left);
    right = MergeSort(right);
    
    // Merge the two smaller vectors together
    return Merge(vec, left, right);
}

#endif
