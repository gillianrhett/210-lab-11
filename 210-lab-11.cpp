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
int checkInput(int);
double checkInput(double); //

int main() {

    return 0;
}

void inputTripData(Trip* trip) {
// takes a pointer to an existing Trip
//  prompts user to enter data via console

    // get the destination; it will accept any string
    cout << "Enter the destination: ";
    getline(cin, trip->destination);
    
    cout << "Enter the duration (number of days): ";
    // input validation: duration is a number > 0
    bool validInput = false;
    while (!validInput) {
        try
        {
            cin >> trip->duration;
            if (cin.fail())
                throw invalid_argument("enter a number at least 1:");
            validInput = true;
        }
        catch(invalid_argument& e)
        {
            cerr << e.what() << '\n';
        }
    }
    validInput = false; // using this again for validating the price input
    cout << "Enter the price per person: ";
    // input validation: price is a number > 0

    cout << "Enter the first participant's name: ";
    // make the array

    // loop where they can enter more names; enter 0 to finish
}

void displayTripData(Trip* trip) {

}