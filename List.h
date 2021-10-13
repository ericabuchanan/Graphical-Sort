// Define List class

// Included needed libraries
#include <vector>
#include <time.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

#define TEXT_SIZE 18

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

class List{
    // Declare public methods
    public:
        // Basic constuctor
        List();
        // Constructor with the user's inputs
        List(int s, int m);
        // Deconstructor
        ~List();
        // Other functions
        void show_sortedList(vector<int> vec);
        void show_unsortedList();
        bool initialize_allegro();
        void user_exit();
        int binary_search_algorithm(const int value, int maximum, int minimum);
        // Helper function
        int get_listSize();
    // Declare protected attributes
    protected:
        // Primary sorted and final unsorted list
        vector<int> unsortedList;
        vector<int> sortedList;
        // Allegro variables
        ALLEGRO_DISPLAY *display;
        ALLEGRO_FONT *font;
        ALLEGRO_EVENT_QUEUE *event_queue;
        // Allegro and list variables
        int displayHeight;
        int displayWidth;
        int maximumValue;
        int listSize;
        int binaryIndex;
};


#endif // LIST_H_INCLUDED
