// P3_QuickSort.cpp : 
// This is the Driver program for the QuickSort Class.
// Cop3530, Fall 2023. 
// Source Codes: Class Lecture/Discussion Notes.
//              Open-DSA (13.11: Quicksort), (13.8: Shellsort), 
//              Other Y-Tube sources on Quicksort. ?GeeksforGeeks?
//
// Started: 12/26(Sun)/23
//

#include "Quicksort.h"

#include <iostream>
#include <string>

#include <random>
#include <ctime>

using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

int main()
{
    // Make instance of class Quicksort to access its functionality.
    Quicksort Qck;

   // Input Total number of elements to sort
   // i.e, N = 10, 12, 15, 20, ...100, 150, 200, ...
    int N = 400;

    // Seed Random-function 
    // i.e seed = 1, 10, 20,..
    int randomSeed = 1;
    random_mt.seed(randomSeed);

    // Declare Array of size N, allocate memory space.
    int* Numbers = new int[N];

    // Determine Range of numbers: i.e range:{1,10}, {1,100}, {1,1000}, etc.
    int range = 110;
    
    //Generate Random numbers:
    for (int i = 0; i < N; i++)
    {
        // Store random numbers in array, Numbers[].
        int num = rand() % range;

        if (num != 0)
        {
            Numbers[i] = num;
        }
        else
        {
            Numbers[i] = 1 + N/2 + N/3;
        }
        
    }

    cout << "==============================================" << endl;

    cout << "Unsorted Array[]: " << endl;
    Qck.PrintArray(Numbers, N);

    Qck.QuickSort(Numbers, 0, N - 1);

    cout << "\nSorted Array[] (via QuickSort): " << endl;
    Qck.PrintArray(Numbers, N);

    cout << "==============================================" << endl;

    return 0;
}


