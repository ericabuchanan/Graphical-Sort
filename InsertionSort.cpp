#include "InsertionSort.h"

// Basic constructor calls parent basic contructor and initializes variables
InsertionSort::InsertionSort() : List(){
    insertionSteps = 0;
    insertionComparisons = 0;
    insertionSortedList = unsortedList;
}

// Secondary onstructor calls parent secondary constructor with user inputs and initializes variables
InsertionSort::InsertionSort(int s, int m) : List(s,m){
    insertionSteps = 0;
    insertionComparisons = 0;
    insertionSortedList = unsortedList;
}

// Insertion sort algorithm
void InsertionSort::insertion_sort(){
    // Iterate through all values of list
    for (int i = 1; i < insertionSortedList.size(); i++){
        // Create secondary iterator
        int j = i;
        bool sorted = false;
        // Iterate through value at given index, moving it until it is sorted
        while(!sorted){
            // Increment comparisons
            insertionComparisons++;
            // Display list before it is sorted
            show_sorting(j, false, false, false);
            // Check if value is greater than the one before
            if (insertionSortedList[j] < insertionSortedList[j-1] && j > 0){
                // If yes, it is not sorted
                sorted = false;
                // Swap the two values
                int temp = insertionSortedList[j];
                insertionSortedList[j] = insertionSortedList[j-1];
                insertionSortedList[j-1] = temp;
                // Display the new swapped list
                show_sorting(j-1, true, false, false);
                // Decrement secondary iterator
                j--;
                // Increment steps
                insertionSteps++;
            }else{
                // If value is not bigger than the one before it, it is sorted
                sorted = true;
            }
        }
    }
    // Show completely sorted list
    show_sorting(-1, false, true, false);
    // Print sorted list to console
    cout << "Sorted list: ";
    show_sortedList(insertionSortedList);
    sortedList = insertionSortedList;
}

// Displays the insertion sorted list in the allegro window
void InsertionSort::show_sorting(int j, bool swapped, bool complete, bool binarySearch){
    // Clears screen to black
    al_clear_to_color(al_map_rgb(0,0,0));
    // Display stats to screen
    al_draw_text(font, al_map_rgb(255,255,255), 0, 0, ALLEGRO_ALIGN_LEFT, "Insertion Sort");
    string statement = "Steps " + to_string(insertionSteps);
    al_draw_text(font, al_map_rgb(255,255,255), 0, TEXT_SIZE, ALLEGRO_ALIGN_LEFT, statement.c_str());
    statement = "Comparisons " + to_string(insertionComparisons);
    al_draw_text(font, al_map_rgb(255,255,255), 0, TEXT_SIZE*2, ALLEGRO_ALIGN_LEFT, statement.c_str());
    // Assigns colour to each value depending on its role in the sorting
    for (int i = 0; i < insertionSortedList.size(); i++){
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
                // Display value being compared in red
                if (i == j){
                    colour = al_map_rgb(255,0,0);
                // Display value you're comparing to in blue
                }else if (i == (j-1)){
                    colour = al_map_rgb(0,0,255);
                // Display values not involved in white
                }else{
                    colour = al_map_rgb(255,255,255);
                }
            // If values have been swapped
            }else{
                // Display value that was compared in red
                if (i == j){
                    colour = al_map_rgb(255,0,0);
                // Display value you compared to in blue
                }else if (i == (j+1)){
                    colour = al_map_rgb(0,0,255);
                // Display values not involved in white
                }else{
                    colour = al_map_rgb(255,255,255);
                }
            }
        }
        // Account for extra space at top for displaying stats
        int headerSpace = TEXT_SIZE*4;
        // Draw each value with a rectangle of corresponding height and with the correct colour
        al_draw_filled_rectangle(i*TEXT_SIZE, headerSpace+((maximumValue-insertionSortedList[i])*TEXT_SIZE), i*TEXT_SIZE+TEXT_SIZE, displayHeight+headerSpace, colour);//how is it indexed again???
    }
    // Update display and rest
    al_flip_display();
    al_rest(.03);
}
