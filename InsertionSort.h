// Define Insertion Sort subclass

#include "List.h"

#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

class InsertionSort: public List{
    // Declare public methods
    public:
        // Basic constructor
        InsertionSort();
        // Constructor using user inputs
        InsertionSort(int s, int m);
        // Deconstructor
        ~InsertionSort(){};
        // Sorting functions
        void insertion_sort();
        void show_sorting(int j, bool swapped, bool complete, bool binarySearch);
    // Declare private attributes
    private:
        vector<int> insertionSortedList;
        int insertionSteps;
        int insertionComparisons;
};


#endif // INSERTIONSORT_H_INCLUDED
