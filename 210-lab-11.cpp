// COMSC-210 | Lab 11 | Gillian Rhett
#include <iostream>
#include <string> // for getline to take string with spaces
#include <iomanip> // for displaying data e.g. price with 2 decimal places
#include <stdexcept> // for input validation
#include <limits> // for clearing invalid input
using namespace std;

struct Trip {
// this struct is for planning and storing info about group trips
    string destination; // name of location they will travel to    
    int duration; // number of days
    double price = 1.0; // price per person - using default while testing other stuff
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
void inputTripData(Trip*);
void displayTripData(Trip*);

int main() {

    int numTrips = 0; // let the user decide
    cout << "==== Trip Manager ====" << endl << endl;
    cout << "How many trips do you want to store? ";
    bool validInput = false;
    while (!validInput) {
        try
        {
            cin >> numTrips;
            if (cin.fail() || numTrips < 1)
                throw invalid_argument("enter a number at least 1: ");
            validInput = true;
        }
        catch(invalid_argument& e)
        {
            cout << "Error: " << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // then it repeats the while loop so they can enter another number
        }
    }
    cout << endl;
    // one example trip for testing
    Trip* april = new Trip;
    inputTripData(april);

    // make an array to store trips
    Trip* tripsArr = new Trip[numTrips];
    
    // user enters data about each trip
    cout << "== Enter trip data ==" << endl;
    for(int i = 0; i < numTrips; ++i) {
        
    }

    // after they input the trips, display the data
    cout << "\n== Stored Trips ==" << endl;
    for(int i = 0; i < numTrips; ++i) {

    }

    delete april;
    delete[] tripsArr;

    return 0;
}

void inputTripData(Trip* trip) {
// takes a pointer to an existing Trip
//  prompts user to enter data via console

    // get the destination; it will accept any string
    cout << "Enter the destination: ";
    // clear the console input so getline will work
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, trip->destination);
    
    cout << "Enter the duration (number of days): ";
    // input validation: duration is an integer > 0
    bool validInput = false;
    while (!validInput) {
        try
        {
            cin >> trip->duration;
            if (cin.fail() || trip->duration < 1)
                throw invalid_argument("enter a number at least 1: ");
            validInput = true;
        }
        catch(invalid_argument& e)
        {
            cout << "Error: " << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // then it repeats the while loop so they can enter another number
        }
    }

    cout << "Enter the price per person: ";
    // input validation: price is a double > 0.0
    validInput = false;
    while (!validInput) {
        try
        {
            cin >> trip->price;
            if (cin.fail() || trip->price <= 0.0)
                throw invalid_argument("enter a number greater than 0: ");
            validInput = true;
        }
        catch(invalid_argument& e)
        {
            cout << "Error: " << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // then repeat the while loop so they can enter another number
        }
    }

    int numParticipants = 0;
    cout << "Enter the number of participants: ";
    cin >> numParticipants;    
    trip->participants = new string[numParticipants]; // change from nullptr to point at this new array

    // clear the console input so getline will work
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // let them enter the number of participants they chose
    for(int i = 0; i < numParticipants; ++i) {
        cout << "Enter participant " << i + 1 << "'s name: ";
        getline(cin, *(trip->participants + i));
    }
}

void displayTripData(Trip* trip) {

}