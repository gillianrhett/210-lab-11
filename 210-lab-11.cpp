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
int getValidInput(int);
double getValidInput(double);

int main() {
    int num;
    cout << "Enter number: "; // TESTING
    cin >> num; // TESTING
    getValidInput(num); // TESTING
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
    
    cout << "Enter the price per person: ";
    // input validation: price is a number > 0

    cout << "Enter the first participant's name: ";
    // make the array

    // loop where they can enter more names; enter 0 to finish
}

void displayTripData(Trip* trip) {

}

int getValidInput(int numIn) {
    bool validInput = false;
    while (!validInput) {
        try // I haven't had a lot of practice with this yet so it's taking some time
        {
            cin >> numIn;
            if (cin.fail() || numIn < 1)
                throw invalid_argument("enter a number at least 1: ");
            validInput = true;
        }
        catch(invalid_argument& e)
        {
            //cerr << e.what() << '\n'; // VSCode autocompleted this
            cout << "Error: " << e.what();
            // then repeat the while loop so they can enter another number
        }
    }
    return numIn;
}

double getValidInput(double numIn) {

    return numIn;
}