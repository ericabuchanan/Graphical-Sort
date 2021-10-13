/***********************************************
* Erica Buchanan            Sorting Assignment *
* 18/06/2021                                   *
*                                              *
* This game sorts an array of size determined  *
* by the user with random numbers in a range   *
* given by the user. The array can be sorted   *
* in one of three ways (insertion, bubble and  *
* quicksort). The user can then enter any      *
* number to search for using binary search.    *
***********************************************/

#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include "QuickSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"


// Define variable constants
#define INSERTION 1
#define BUBBLE 2
#define QUICKSORT 3

// Prototypes
int get_sorting_choice(int &s, int &v);
int get_value_choice();

int main(int argc, char *argv[]){
    // Declare clock
    clock_t start, end;
    // Declare and initialize variables
    int listSize = 0;
    int maxValue = 0;
    // Get user's choice of algorithm, list size and range
    int userChoice = get_sorting_choice(listSize, maxValue);
    // Create variable using corresponding algorithm class and user's input values
    if (userChoice == INSERTION){
        InsertionSort userList(listSize, maxValue);
        // Initialize allegro
        if (!userList.initialize_allegro()){
            return -1;
        }
        // Print unsorted list
        cout << "Unsorted list: ";
        userList.show_unsortedList();
        // Get clock time at start
        start = clock();
        // Sort using insertion and display process
        userList.insertion_sort();
        // Get clock time at end
        end = clock();
        // Calculate the time taken and print to screen
        double time_t = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by insertion program is " << fixed << time_t << setprecision(5);
        cout << " seconds including display time" << endl;
        // Get user to enter a value for binary search
        int value = get_value_choice();
        // Find index of that value in sorted list or index of -1 if it isn't in the list
        int index = userList.binary_search_algorithm(value, userList.get_listSize()-1, 0);
        if (index != -1){
            cout << "Value was found at index " << index << endl;
            userList.show_sorting(-1, false, true, true);
        }else{
            cout << "Value was not found" << endl;
        }
        cout << endl <<  "Press enter in allegro window to exit display.";
        // Get user to press enter to exit allegro window
        userList.user_exit();
    }else if (userChoice == BUBBLE){
        BubbleSort userList(listSize, maxValue);
        // Initialize allegro
        if (!userList.initialize_allegro()){
            return -1;
        }
        // Print unsorted list
        cout << "Unsorted list: ";
        userList.show_unsortedList();
        // Get clock time at start
        start = clock();
        // Sort using bubble and display process
        userList.bubble_sort();
        // Get clock time at end
        end = clock();
        // Calculate the time taken and print to screen
        double time_t = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by bubble program is " << fixed << time_t << setprecision(5);
        cout << " seconds including display time" << endl;
        // Get user to enter a value for binary search
        int value = get_value_choice();
        // Find index of that value in sorted list or index of -1 if it is not in the list
        int index = userList.binary_search_algorithm(value, userList.get_listSize()-1, 0);
        if (index != -1){
            cout << "Value was found at index " << index << endl;
            userList.show_sorting(-1, false, true, true);
        }else{
            cout << "Value was not found" << endl;
        }
        cout << endl << "Press enter in allegro window to exit display.";
        // Get user to press enter to exit allegro display
        userList.user_exit();
    }else if (userChoice == QUICKSORT){
        QuickSort userList(listSize, maxValue);
        // Initialize allegro
        if (!userList.initialize_allegro()){
            return -1;
        }
        // Print unsorted list
        cout << "Unsorted list: ";
        userList.show_unsortedList();
        // Get clock time at start
        start = clock();
        // Sort using quicksort with the indexes of unsorted list and display process
        userList.quick_sort(0, userList.get_listSize()-1);
        // Old quicksort method
        ///userList.quick_sort_old(userList.quickSortedList);
        // Get clock time at end
        end = clock();
        // Display sorted list in allegro window
        userList.show_sorting(-1, -1, -1, false, true, false);
        // Display sorted list in console
        cout << "Sorted list: ";
        userList.show_sortedList(userList.quickSortedList);
        // Calculate time taken and print to screen
        double time_t = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by quick sort program is " << fixed << time_t << setprecision(5);
        cout << " seconds including display time" << endl;
        // Get user to enter a value for binary search
        int value = get_value_choice();
        // Find index of that value in sorted list or index of -1 if it is not in the list
        int index = userList.binary_search_algorithm(value, userList.get_listSize()-1, 0);
        if (index != -1){
            cout << "Value was found at index " << index << endl;
            userList.show_sorting(-1, -1, -1, false, true, true);
        }else{
            cout << "Value was not found" << endl;
        }
        cout << endl << "Press enter in allegro window to exit display.";
        // Get user to press enter to exit allegro display
        userList.user_exit();
    }
    return 0;
}

// Function returns the user's algorithm choice and gets their range maximum and list size
int get_sorting_choice(int &s, int &v){
    cout << "What program would you like to use to sort your list?" << endl;
    cout << "The choices are: insertion (1), bubble (2) or quicksort (3). Enter your choice: ";
    int choice;
    cin >> choice;
    cout << "Pick a list size (10-100): ";
    cin >> s;
    cout << "Pick a max value (2-50): ";
    cin >> v;
    return choice;
}

// Function returns the user's choice of number to search for
int get_value_choice(){
    cout << endl <<  "Pick a value to find using binary search: ";
    int choice;
    cin >> choice;
    return choice;
}
