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
    int numParticipants; // how many participants (length of participants array)

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

    int numTrips = 0; // let the user decide how many trips to store
    cout << "==== Trip Manager ====" << endl << endl;
    cout << "How many trips do you want to store? ";
    // they need to enter a whole number
    bool validInput = false;
    while (!validInput) {
        try
        {
            cin >> numTrips;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    // make an array to store trips
    Trip* tripsArr = new Trip[numTrips];
    // the pointer tripsArr points to a new array of trips
    
    // user enters data about each trip
    cout << "== Enter trip data ==" << endl;
    for(int i = 0; i < numTrips; ++i) {
        cout << "\n= Trip " << i + 1 << " =" << endl;
        inputTripData((tripsArr + i)); // enter each trip's data via the pointer to it
    }

    // after they input the trips, display the data
    cout << "\n== Stored Trips ==" << endl;
    for(int i = 0; i < numTrips; ++i) {
        cout << "Trip " << i + 1 << endl;
        displayTripData((tripsArr + i));
    }

    delete[] tripsArr;

    return 0;
}

void inputTripData(Trip* trip) {
// takes a pointer to an existing Trip
//  prompts user to enter data via console

    // get the destination; it will accept any string
    cout << "Enter the destination: ";
    getline(cin, trip->destination);
    
    cout << "Enter the duration (number of days): ";
    // input validation: duration is an integer > 0
    bool validInput = false;
    while (!validInput) {
        try
        {
            cin >> trip->duration;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (cin.fail() || trip->duration < 1)
                throw invalid_argument("enter a whole number at least 1: ");
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    cout << "Enter the number of participants: ";
    validInput = false;
    while (!validInput) {
        try
        {
            cin >> trip->numParticipants;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (cin.fail() || trip->numParticipants < 1)
                throw invalid_argument("enter a whole number at least 1: ");
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
    trip->participants = new string[trip->numParticipants]; // change from nullptr to point at this new array

    // let them enter the number of participants they chose
    for(int i = 0; i < trip->numParticipants; ++i) {
        cout << "Enter participant " << i + 1 << "'s name: ";
        getline(cin, *(trip->participants + i));
    }
}

void displayTripData(Trip* trip) {
// takes a pointer to an existing Trip
//  displays the data on that trip
    cout << fixed << setw(19) << "Destination: " << trip->destination << endl;
    cout << fixed << setw(19) << "Duration (days): " << trip->duration << endl;
    cout << fixed << setw(19) << "Price per person: $" << setprecision(2) << trip->price << endl;
    cout << fixed << setw(19) << "Participants:" << endl;

    // loop to display the list of participants' names
    for (int i = 0; i < trip->numParticipants; ++i) {
        cout << "    " << *(trip->participants + i) << endl;
    }
    cout << endl;
}