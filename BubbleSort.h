// Define Bubble Sort subclass

#include "List.h"

#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

class BubbleSort: public List{
    // Declare public methods
    public:
        // Basic constructor
        BubbleSort();
        // Constructor using user inputs
        BubbleSort(int s, int m);
        // Deconstructor
        ~BubbleSort(){};
        // Sorting functions
        void bubble_sort();
        void show_sorting(int j, bool swapped, bool complete, bool binarySearch);
    // Declare private attributes
    private:
        vector<int> bubbleSortedList;
        int bubbleSteps;
        int bubbleComparisons;
};


#endif // BUBBLESORT_H_INCLUDED
