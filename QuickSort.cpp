#include "QuickSort.h"

// Basic constructor calls parent basic contructor and initializes variables
QuickSort::QuickSort(){
    quickSortSteps = 0;
    quickSortComparisons = 0;
    quickSortedList = unsortedList;
}

// Secondary onstructor calls parent secondary constructor with user inputs and initializes variables
QuickSort::QuickSort(int s, int m) : List(s,m){
    quickSortSteps = 0;
    quickSortComparisons = 0;
    quickSortedList = unsortedList;
}

// Quick sort sorting done using a different method
vector<int> QuickSort::quick_sort_old(vector<int> &vecList){
    if (vecList.size() < 2){
        return vecList;
    }
    int pivot = vecList[vecList.size()-1];
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < vecList.size()-1; i++){ //not the pivot
        if (vecList[i] <= pivot){
            quickSortComparisons++;
            left.push_back(vecList[i]);
            quickSortSteps++;
        }else if (vecList[i] > pivot){
            quickSortComparisons++;
            right.push_back(vecList[i]);
            quickSortSteps++;
        }
    }
    vecList.clear();
    quick_sort_old(left);
    quick_sort_old(right);
    vecList = left;
    quickSortSteps++;
    vecList.push_back(pivot);
    quickSortSteps++;
    for (int i = 0; i < right.size(); i++){
        vecList.push_back(right[i]);
        quickSortSteps++;
    }
    return vecList;
}

// Quick sort sorting done using new method of in-place sorting
void QuickSort::quick_sort(int minimum, int maximum){ //max is the size of the array, min is 0 to start
    // Set pivot to be at the maximum index
    int pivot = quickSortedList[maximum];
    // Increment steps
    quickSortSteps++;
    // Create two temporary vectors to store sub-lists
    vector<int> left;
    vector<int> right;
    // Display list in allegro window
    show_sorting(maximum, minimum, left.size(), false, false, false);
    // Iterate through given portion of list not including the pivot variable
    for (int i = minimum; i < maximum; i++){
        // If element is smaller than pivot, put it in the left vector
        if (quickSortedList[i] <= pivot){
            // Increment comparisons
            quickSortComparisons++;
            left.push_back(quickSortedList[i]);
            // Increment steps
            quickSortSteps++;
        // If element is bigger than pivot, put it in the right vector
        }else if (quickSortedList[i] > pivot){
            // Increment comparisons
            quickSortComparisons++;
            right.push_back(quickSortedList[i]);
            // Increment steps
            quickSortSteps++;
        }
    }
    int j = 0;
    // Iterate through all values of left vector and place them in the quick sorted list at the correct indexes
    for (int i = minimum; i < minimum+left.size(); i++){
        quickSortedList[i] = left[j];
        // Increment number of steps
        quickSortSteps++;
        // Increment left list iterator
        j++;
    }
    // Put pivot at the right index in quick sorted list
    quickSortedList[minimum+left.size()] = pivot;
    // Increment number of steps
    quickSortSteps++;
    // Reset vector iterator
    j = 0;
    // Iterate through all valuesof right vector and place them in the quick sorted list at the correct indexes
    for (int i = maximum-right.size()+1; i <= maximum; i++){
        quickSortedList[i] = right[j];
        // Increment number of steps
        quickSortSteps++;
        // Increment right list iterator
        j++;
    }
    // Show quicksorted list after sorting
    show_sorting(maximum, minimum, left.size(), true, false, false);
    // Set sorted list variable
    sortedList = quickSortedList;
    // Check to see if the list has been completely sorted, if not call function recursively with new parameters
    if (maximum-minimum > 1){
        quick_sort(minimum, minimum+left.size()-1);
        quick_sort(maximum-right.size()+1, maximum);
    }
}

// Displays the quick sorted list in the allegro window
void QuickSort::show_sorting(int maximum, int minimum, int leftSize, bool swapped, bool complete, bool binarySearch){
    // Clears screen to black
    al_clear_to_color(al_map_rgb(0,0,0));
    // Display stats to the screen
    al_draw_text(font, al_map_rgb(255,255,255), 0, 0, ALLEGRO_ALIGN_LEFT, "Quick Sort");
    string statement = "Steps " + to_string(quickSortSteps);
    al_draw_text(font, al_map_rgb(255,255,255), 0, TEXT_SIZE, ALLEGRO_ALIGN_LEFT, statement.c_str());
    statement = "Comparisons " + to_string(quickSortComparisons);
    al_draw_text(font, al_map_rgb(255,255,255), 0, TEXT_SIZE*2, ALLEGRO_ALIGN_LEFT, statement.c_str());
    // Assigns colour to each value depending on its role in the sorting
    for (int i = 0; i < quickSortedList.size(); i++){
        ALLEGRO_COLOR colour;
        // If list has been completely sorted
        if (complete){
            // Make all values green
            colour = al_map_rgb(0,255,0);
            // If binary search has been implemented and a value was found display it in light blue
            if (binarySearch){
                if (i == binaryIndex){
                    colour = al_map_rgb(0,255,255);
                }
            }
        // If list has not been sorted
        }else{
            // If the values have not been swapped
            if (!swapped){
                // Display pivot in red
                if (i == maximum){
                    colour = al_map_rgb(255,0,0);
                // Display values to be compared to pivot in blue
                }else if (i < maximum && i >= minimum){
                    colour = al_map_rgb(0,0,255);
                // Display values outside of range in white
                }else{
                    colour = al_map_rgb(255,255,255);
                }
            // Once the values have been swapped
            }else{
                // Display the pivot in red
                if (i == minimum+leftSize){
                    colour = al_map_rgb(255,0,0);
                // Display the values outside of range in white
                }else if (i > maximum || i < minimum){
                    colour = al_map_rgb(255,255,255);
                // Display values in range in blue
                }else{
                    colour = al_map_rgb(0,0,255);
                }
            }
        }
        // Account for extra space at top for displaying stats
        int headerSpace = TEXT_SIZE*4;
        // Draw each value with a rectangle of corresponding height and with the correct colour
        al_draw_filled_rectangle(i*TEXT_SIZE, headerSpace+((maximumValue-quickSortedList[i])*TEXT_SIZE), i*TEXT_SIZE+TEXT_SIZE, displayHeight+headerSpace, colour);//how is it indexed again???
    }
    // Update display and rest
    al_flip_display();
    al_rest(.08);
}
