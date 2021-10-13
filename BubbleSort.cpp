#include "BubbleSort.h"

// Basic constructor calls parent basic contructor and initializes variables
BubbleSort::BubbleSort(){
    bubbleSteps = 0;
    bubbleComparisons = 0;
    bubbleSortedList = unsortedList;
}

// Secondary onstructor calls parent secondary constructor with user inputs and initializes variables
BubbleSort::BubbleSort(int s, int m) : List(s,m){
    bubbleSteps = 0;
    bubbleComparisons = 0;
    bubbleSortedList = unsortedList;
}

// Bubble sort algorithm
void BubbleSort::bubble_sort(){
    // Set list to not be sorted
    bool sorted = false;
    // While the list isn't sorted, sort it
    while (!sorted){
        sorted = true;
        // Iterate through all values of list
        for (int i = 0; i < bubbleSortedList.size()-1; i++){
            // Increment comparisons
            bubbleComparisons++;
            // Display list before values are swapped
            show_sorting(i, false, false, false);
            // If value is greater than the one to the right of it, swap them
            if (bubbleSortedList[i] > bubbleSortedList[i+1]){
                // Swap values
                int temp = bubbleSortedList[i];
                bubbleSortedList[i] = bubbleSortedList[i+1];
                bubbleSortedList[i+1] = temp;
                // Increment steps
                bubbleSteps++;
                // Display list with swapped values
                show_sorting(i+1, true, false, false);
                // Set sorting to be false
                sorted = false;
            }
        }
    }
    // Display completely sorted list
    show_sorting(-1, false, true, false);
    // Print sorted list to console
    cout << "Sorted list: ";
    show_sortedList(bubbleSortedList);
    sortedList = bubbleSortedList;
}

// Displays the bubble sorted list in the allegro window
void BubbleSort::show_sorting(int j, bool swapped, bool complete, bool binarySearch){
    // Clears screen to black
    al_clear_to_color(al_map_rgb(0,0,0));
    // Display stats to screen
    al_draw_text(font, al_map_rgb(255,255,255), 0, 0, ALLEGRO_ALIGN_LEFT, "Bubble Sort");
    string statement = "Steps " + to_string(bubbleSteps);
    al_draw_text(font, al_map_rgb(255,255,255), 0, TEXT_SIZE, ALLEGRO_ALIGN_LEFT, statement.c_str());
    statement = "Comparisons " + to_string(bubbleComparisons);
    al_draw_text(font, al_map_rgb(255,255,255), 0, TEXT_SIZE*2, ALLEGRO_ALIGN_LEFT, statement.c_str());
    // Assigns colour to each value depending on its role in the sorting
    for (int i = 0; i < bubbleSortedList.size(); i++){
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
                }else if (i == (j+1)){
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
                }else if (i == (j-1)){
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
        al_draw_filled_rectangle(i*TEXT_SIZE, headerSpace+((maximumValue-bubbleSortedList[i])*TEXT_SIZE), i*TEXT_SIZE+TEXT_SIZE, displayHeight+headerSpace, colour);//how is it indexed again???
    }
    // Update display and rest
    al_flip_display();
    al_rest(.03);
}
