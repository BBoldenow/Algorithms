//
//  DocumentDistance.h
//  Algorithms
//
//  Created by Brandon Boldenow on 3/8/15.
//  Copyright (c) 2015 Me. All rights reserved.
//

#ifndef __Algorithms__DocumentDistance__
#define __Algorithms__DocumentDistance__

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <locale>
#include <map>
#include <vector>

// define a new locale to ignore non-alphanumeric characters
struct alpha_num : std::ctype<char> 
{
    alpha_num(): std::ctype<char>(get_table()) {}
    
    static std::ctype_base::mask const* get_table()
    {
        static std::vector<std::ctype_base::mask> rc(std::ctype<char>::table_size, std::ctype_base::space);
        
        // fill the vector with alphanumerics
        std::fill(&rc['0'], &rc['9'], std::ctype_base::digit);
        std::fill(&rc['a'], &rc['z'], std::ctype_base::lower);
        std::fill(&rc['A'], &rc['Z'], std::ctype_base::upper);
        return &rc[0];
    }
};

// Document distance problem
// Template class
// assumes we want to ignore non-alphanumeric characters
template <typename T> class Document
{
public:
    Document() = default;
    
    // Open the ifstream using the given stream
    Document(std::string f) : file(f)
    {
        if(!file)
        {
            std::cerr << "Error opening file: " << f << std::endl;
        }
        else
            CountFrequency();
    }
    
    void CountFrequency()
    {
        T t;
        
        file.imbue(std::locale(std::locale(), new alpha_num));
        
        while(file.is_open() && !file.eof())
        {
            file >> t;
            
            type_freq[t] += 1;
        }
    }
    
    // Template friend functions for determining distance
    template <class U>
    friend double DotProduct(Document<U> &D1, Document<U> &D2);
    
    template <class U>
    friend double VectorAngle(Document<U> &D1, Document<U> &D2);
    
    template <class U>
    friend double GetDocumentDistance(Document<U> &D1, Document<U> &D2);
    
private:
    std::ifstream file;
    std::map<T, unsigned long long> type_freq;
    
};

/////////////////////////////////////////////
//          Defining friend functions
/////////////////////////////////////////////
template <class T>
double DotProduct(Document<T> &D1, Document<T> &D2)
{
    double sum = 0.0;
    
    for(auto key : D1.type_freq)
    {
        if(D2.type_freq.count(key.first))
            sum += key.second * D2.type_freq[key.first];
    }
    
    return sum;
}

template <class T>
double VectorAngle(Document<T> &D1, Document<T> &D2)
{
    double numerator = DotProduct(D1, D2);
    double denominator = std::sqrt(DotProduct(D1, D1) * DotProduct(D2, D2));
    return std::acos(numerator/denominator);
}

template <class T>
double GetDocumentDistance(Document<T> &D1, Document<T> &D2)
{
    return VectorAngle(D1, D2);
}

#endif /* defined(__Algorithms__DocumentDistance__) */
