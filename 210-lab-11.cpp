// COMSC-210 | Lab 11 | Gillian Rhett
#include <iostream>
#include <string> // for getline to take string with spaces
#include <iomanip> // for displaying data e.g. price with 2 decimal places
using namespace std;

struct Trip {
// this is for planning and storing info about group trips
    string destination; // name of location they will travel to    
    int duration; // number of days
    double price; // price per person
    string* participants = nullptr; // dynamic array of people's names

    ~Trip () {
        if(participants != nullptr) {
        // if the participants list exists, delete it
            delete[] participants;
            participants = nullptr;
        }
    }
};

// functions for working with the Trip struct
Trip createTrip();
void inputTripData(Trip*);
void displayTripData(Trip*);

int main() {

    return 0;
}

void inputTripData(Trip* trip) {
// takes a pointer to an existing Trip
//  prompts user to enter data via console

    // get the destination; it will accept any string
    cout << "Enter the destination: ";
    getline(cin, trip->destination);
    int duration; // number of days
    double price; // price per person
    string* participants;
}

