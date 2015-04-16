//
//  main.cpp
//  Word Generator
//
//  Created by Zoltán Majoros on 16/Apr/15.
//  Copyright (c) 2015 Zoltán Majoros. All rights reserved.
//

#include <iostream>
#include <random>
#include <sys/time.h>

using namespace std;

std::mersenne_twister_engine<std::uint_fast32_t, 32, 624, 397, 31,
0x9908b0df, 11,
0xffffffff, 7,
0x9d2c5680, 15,
0xefc60000, 18, 1812433253> randomEngine;

int main(int argc, const char * argv[])
{
    const string vowels = "aeiou";
    const string consonants = "bcdfghjklmnprstvwyz"; // removed 'q' and 'x'
    
    {
        timeval time;
        gettimeofday(&time, NULL);
        randomEngine.seed(time.tv_usec);
    }
    
    int numWords = 13;
    
    while (numWords--)
    {
        int numPairs = 3;

        string word;
        
        while (numPairs--)
        {
            char c = consonants[randomEngine() % consonants.size()];
            if(word.length() == 0)
                c = toupper(c);
            
            word.push_back(c);
            word.push_back(vowels[randomEngine() % vowels.size()]);
        }

        cout << word << endl;
    }

    return 0;
}
