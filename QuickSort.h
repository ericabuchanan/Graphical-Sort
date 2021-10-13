// Define QuickSort subclass

#include "List.h"

#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

class QuickSort: public List{
    // Declare public methods and quicksort list variable
    public:
        // Basic constructor
        QuickSort();
        // Constructor using user inputs
        QuickSort(int s, int m);
        // Deconstructor
        ~QuickSort(){};
        // Sorting functions
        vector<int> quick_sort_old(vector<int> &vecList);
        void quick_sort(int minimum, int maximum);
        void show_sorting(int maximum, int minimum, int leftSize, bool swapped, bool complete, bool binarySearch);
        // Quicksorted list
        vector<int> quickSortedList;
    // Declare private attributes
    private:
        int quickSortSteps;
        int quickSortComparisons;
};

#endif // QUICKSORT_H_INCLUDED
