//
//  HeapSorting.h
//  Algorithms
//
//  Created by Brandon Boldenow on 3/10/15.
//  Copyright (c) 2015 Me. All rights reserved.
//

#ifndef Algorithms_HeapSorting_h
#define Algorithms_HeapSorting_h

#include <vector>

unsigned int parent(unsigned int i)
{
    return i / 2;
}

unsigned int left(unsigned int i)
{
    return 2 * i;
}

unsigned int right(unsigned int i)
{
    return 2 * i + 1;
}

// recursively create a max heap from a vector
template <typename T> void MaxHeapify(std::vector<T> &arr, unsigned int i, int n)
{
    // start with left and right leaves
    unsigned int l = left(i);
    unsigned int r = right(i);
    unsigned int largest = i;
    
    // if the left is bigger than the current position
    // set the largest index to the left index
    if(l < n && arr[l] > arr[largest])
        largest = l;
    
    // if the right leaf is bigger than the current largest element
    // set the largest index to the right index
    if(r < n && arr[r] > arr[largest])
        largest = r;
    
    // if the current element in the heap isn't greater than one of its children
    // swap it with the greatest child. Once swapped, ensure it's new branch is a max heap
    if(largest != i)
    {
        T exchange = arr[i];
        arr[i] = arr[largest];
        arr[largest] = exchange;
        
        MaxHeapify(arr, largest, n);
    }
}

// Build a max heap
template <typename T> void BuildMaxHeap(std::vector<T> &arr)
{
    // Start at n/2 - a heap's max depth
    for(int i = arr.size() / 2; i >= 0; --i)
        MaxHeapify(arr, i, arr.size());
}

// Heap sort
template <typename T> void HeapSort(std::vector<T> &arr)
{
    // First make the array/vector into a max heap
    BuildMaxHeap(arr);
    
    // store the size
    int n = arr.size();
    
    // use the size for the check - allows us to simply swap
    // elements instead of having to create and set new containers
    while(n > 0)
    {
        // The max element is the first element
        T max_element = arr[0];
    
        // swap the first and last elements - max will be at the end of the array
        arr[0] = arr[n - 1];
        arr[n - 1] = max_element;
        
        --n;
        
        // Make sure that this is still a max heap after swapping elements
        MaxHeapify(arr, 0, n);
    }
}

#endif
