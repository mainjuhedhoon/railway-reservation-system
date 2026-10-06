#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    // Default Constructor
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int number, const char name[], const char src[],
          const char dest[], const char time[]) {

        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Destructor
    ~Train() {
        trainCount--;
    }

    // Setters
    void setTrainNumber(int number) {
        trainNumber = number;
    }

    void setTrainName(const char name[]) {
        strcpy(trainName, name);
    }

    void setSource(const char src[]) {
        strcpy(source, src);
    }

    void setDestination(const char dest[]) {
        strcpy(destination, dest);
    }

    void setTrainTime(const char time[]) {
        strcpy(trainTime, time);
    }

    // Getters
    int getTrainNumber() const {
        return trainNumber;
    }

    const char* getTrainName() const {
        return trainName;
    }

    const char* getSource() const {
        return source;
    }

    const char* getDestination() const {
        return destination;
    }

    const char* getTrainTime() const {
        return trainTime;
    }

    // Input train details
    void inputTrainDetails() {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display train details
    void displayTrainDetails() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    // Static method
    static int getTrainCount() {
        return trainCount;
    }
};

// Initialize static member
int Train::trainCount = 0;


class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    // Add new train
    void addTrain() {
        if (totalTrains >= 100) {
            cout << "\nTrain record limit reached!\n";
            return;
        }

        trains[totalTrains].inputTrainDetails();
        totalTrains++;

        cout << "\nTrain record added successfully!\n";
    }

    // Display all trains
    void displayAllTrains() {
        if (totalTrains == 0) {
            cout << "\nNo train records available.\n";
            return;
        }

        cout << "\n========== ALL TRAIN RECORDS ==========\n";

        for (int i = 0; i < totalTrains; i++) {
            cout << "\nTrain " << i + 1 << " details:\n";
            trains[i].displayTrainDetails();
        }
    }

    // Search train by number
    void searchTrainByNumber(int number) {
        bool found = false;

        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\nTrain found!\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nTrain with number " << number
                 << " not found!\n";
        }
    }
};


int main() {
    RailwaySystem railway;
    int choice;

    // Minimum three initial train records
    cout << "Enter details for 3 initial trains:\n";

    for (int i = 0; i < 3; i++) {
        cout << "\n--- Train " << i + 1 << " ---\n";
        railway.addTrain();
    }

    do {
        cout << "\n\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            railway.addTrain();
            break;

        case 2:
            railway.displayAllTrains();
            break;

        case 3: {
            int number;

            cout << "Enter Train Number to search: ";
            cin >> number;

            railway.searchTrainByNumber(number);
            break;
        }

        case 4:
            cout << "\nExiting the system. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}