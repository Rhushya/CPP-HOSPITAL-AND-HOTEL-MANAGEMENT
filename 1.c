#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Structure to represent a hotel room
struct Room {
    int roomNumber;
    string guestName;
    bool occupied;
};

// Function prototypes
void displayMenu();
void displayRooms(Room rooms[], int size);
void makeReservation(Room rooms[], int size);
void checkIn(Room rooms[], int size);
void checkOut(Room rooms[], int size);
void saveData(Room rooms[], int size);
void loadData(Room rooms[], int size);

int main() {
    const int NUM_ROOMS = 10;
    Room rooms[NUM_ROOMS];
    loadData(rooms, NUM_ROOMS);

    char choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch(choice) {
            case '1':
                displayRooms(rooms, NUM_ROOMS);
                break;
            case '2':
                makeReservation(rooms, NUM_ROOMS);
                break;
            case '3':
                checkIn(rooms, NUM_ROOMS);
                break;
            case '4':
                checkOut(rooms, NUM_ROOMS);
                break;
            case '5':
                saveData(rooms, NUM_ROOMS);
                break;
            case '6':
                cout << "Exiting program...\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(true);

    return 0;
}

void displayMenu() {
    cout << "\nHotel Management System\n";
    cout << "1. Display Rooms\n";
    cout << "2. Make Reservation\n";
    cout << "3. Check-in\n";
    cout << "4. Check-out\n";
    cout << "5. Save Data\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void displayRooms(Room rooms[], int size) {
    cout << "\nRoom Number\tGuest Name\tOccupied\n";
    for(int i = 0; i < size; ++i) {
        cout << rooms[i].roomNumber << "\t\t";
        if(rooms[i].occupied)
            cout << rooms[i].guestName << "\t\tYes\n";
        else
            cout << "N/A\t\tNo\n";
    }
}

void makeReservation(Room rooms[], int size) {
    int roomNum;
    string guestName;
    cout << "Enter room number: ";
    cin >> roomNum;
    cout << "Enter guest name: ";
    cin >> guestName;
    
    for(int i = 0; i < size; ++i) {
        if(rooms[i].roomNumber == roomNum && !rooms[i].occupied) {
            rooms[i].guestName = guestName;
            rooms[i].occupied = true;
            cout << "Reservation successful.\n";
            return;
        }
    }
    cout << "Room not available or does not exist.\n";
}

void checkIn(Room rooms[], int size) {
    int roomNum;
    cout << "Enter room number: ";
    cin >> roomNum;
    
    for(int i = 0; i < size; ++i) {
        if(rooms[i].roomNumber == roomNum && rooms[i].occupied) {
            cout << "Checking in guest: " << rooms[i].guestName << endl;
            return;
        }
    }
    cout << "Room not occupied or does not exist.\n";
}

void checkOut(Room rooms[], int size) {
    int roomNum;
    cout << "Enter room number: ";
    cin >> roomNum;
    
    for(int i = 0; i < size; ++i) {
        if(rooms[i].roomNumber == roomNum && rooms[i].occupied) {
            rooms[i].guestName = "";
            rooms[i].occupied = false;
            cout << "Checking out guest from room " << roomNum << endl;
            return;
        }
    }
    cout << "Room not occupied or does not exist.\n";
}

void saveData(Room rooms[], int size) {
    ofstream outFile("hotel_data.txt");
    if(!outFile) {
        cerr << "Error opening file.\n";
        exit(1);
    }
    for(int i = 0; i < size; ++i) {
        outFile << rooms[i].roomNumber << " " << rooms[i].guestName << " " << rooms[i].occupied << endl;
    }
    outFile.close();
    cout << "Data saved successfully.\n";
}

void loadData(Room rooms[], int size) {
    ifstream inFile("hotel_data.txt");
    if(!inFile) {
        cerr << "Error opening file. Starting with default data.\n";
        for(int i = 0; i < size; ++i) {
            rooms[i].roomNumber = i + 1;
            rooms[i].guestName = "";
            rooms[i].occupied = false;
        }
        return;
    }
    for(int i = 0; i < size; ++i) {
        inFile >> rooms[i].roomNumber >> rooms[i].guestName >> rooms[i].occupied;
    }
    inFile.close();
    cout << "Data loaded successfully.\n";
}
