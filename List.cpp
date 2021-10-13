#include "List.h"

// Basic constructor initializes the unsorted list with the maximum range and size, and sets display size
List::List(){
    // Seed time for randomizer
    srand(time(NULL));
    listSize = 100;
    maximumValue = 50;
    binaryIndex = -1;
    // Create list using random numbers
    unsortedList.resize(listSize);
    for (int i = 0; i < listSize; i++){
        unsortedList[i] = rand()%maximumValue+1;
    }
    // Set size lengths for display
    displayHeight = maximumValue*TEXT_SIZE;
    displayWidth = listSize*TEXT_SIZE;
}

// Secondary constructor gets user inputs to create the list size and values in the right range
List::List(int s, int m){
    binaryIndex = -1;
    // Set new list size if value in range, if not set to default
    if (s >= 10 && s <= 100){
        listSize = s;
    }else{
        listSize = 100;
    }
    // Set new range if values from 2 to 50, if not set to default
    if (m > 1 && m <= 50){
        maximumValue = m;
    }else{
        maximumValue = 50;
    }
    // Seed time for randomizer
    srand(time(NULL));
    // Create list using random numbers
    unsortedList.resize(listSize);
    for (int i = 0; i < listSize; i++){
        unsortedList[i] = rand()%maximumValue+1;
    }
    // Set size lengths for display
    displayHeight = maximumValue*TEXT_SIZE;
    displayWidth = listSize*TEXT_SIZE;
}

// Deconstructor destroys the display
List::~List(){
    al_destroy_display(display);
}

// Shows any list that is passed as an argument
void List::show_sortedList(vector<int> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Shows the original unsorted list
void List::show_unsortedList(){
    for (int i = 0; i < unsortedList.size(); i++){
        cout << unsortedList[i] << " ";
    }
    cout << endl;
}

// Initialize allegro, display, font, keyboard and event queue
bool List::initialize_allegro(){
    // Check if different components were initialized correctly
    if (!al_init() || !al_init_font_addon() || !al_init_ttf_addon() || !al_init_primitives_addon()){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize.", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
    }
    // Create display
    display = al_create_display(displayWidth, displayHeight+(TEXT_SIZE*4)); //maybe more room for text at top?
    // Check if display was created
    if (!display){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display.", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
    }
    // Initialize font
    font = al_load_ttf_font("OpenSans-Regular.ttf", TEXT_SIZE, 0);
    // Check if font was initialized
    if (!font){
        cout << "Could not initialize font." << endl;
        return false;
    }
    // Install keyboard and check if it was installed
    al_install_keyboard();
    if (!al_is_keyboard_installed()){
        al_show_native_message_box(display, "Error", "Error", "Failed to install keyboard.", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
    }
    // Create event queue and check if it was created
    event_queue = al_create_event_queue();
    if (!event_queue){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize event queue.", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
    }
    // Create keyboard event source
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    // Set title for graphics window
    al_set_window_title(display, "Fantasy Game");
    return true;
}

// Helper function gets size of list
int List::get_listSize(){
    return listSize;
}

// Gets the user to press the return character to exit the allegro window
void List::user_exit(){
    bool exitDisplay = false;
    while (!exitDisplay){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
                exitDisplay = true;
            }
        }
    }
}

// Binary search algorithm searches for any given value by looking into smaller and smaller sections of the list
int List::binary_search_algorithm(const int value, int maximum, int minimum){
    // Find the midpoint of the index values
    int midpoint = (maximum-minimum)/2 + minimum;
    // If the indexes are the same (one value left), check to see if it is the right value
    if (maximum == minimum){
        if (value == sortedList[midpoint]){
            binaryIndex = midpoint;
            return midpoint;
        }else{
            return -1;
        }
    // If the value is greater than the midpoint value, search recursively using new indexes of upper end of the list
    }else if (value > sortedList[midpoint]){
        binary_search_algorithm(value, maximum, midpoint+1);
    // If the value is less than the midpoint value, search recursively using indexes of lower end of the list
    }else if (value < sortedList[midpoint]){
        binary_search_algorithm(value, midpoint-1, minimum);
    // If the value is the same as the midpoint value, but there are more than one instances of the value, return the first one found
    }else{
       binaryIndex = midpoint;
       return midpoint;
    }
}
