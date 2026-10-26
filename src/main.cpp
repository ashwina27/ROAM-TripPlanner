#include <iostream>
#include <string>
#include "Trip.h"
#include "Destination.h"
#include "Traveler.h"
#include "Date.h"
#include "Trace.h"
using namespace std;

int readInt(const string& prompt) {
    int value;
    cout << prompt;
    cin >> value;
    cin.ignore(10000, '\n');
    return value;
}

string readString(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

double readDouble(const string& prompt) {
    double value;
    cout << prompt;
    cin >> value;
    cin.ignore(10000, '\n');
    return value;
}

void viewTrip(Trip& trip) {
    trip.display();
    trip.displayDestinations();
}

void addDestination(Trip& trip) {
    cout << "\n===== Add Destination =====\n";
    int type = readInt("Type: 1) General  2) Beach  3) Mountain\nChoose: ");
    
    string name = readString("Name: ");
    string country = readString("Country: ");
    double cost = readDouble("Cost per day (Rs.): ");
    
    if (type == 2) {
        char sports;
        cout << "Water sports available? (y/n): ";
        cin >> sports;
        cin.ignore(10000, '\n');
        BeachDestination beach(name, country, cost, sports == 'y');
        trip += beach;
        cout << "✓ Added: " << name << " to trip\n";
    } else if (type == 3) {
        double altitude = readDouble("Altitude (m): ");
        MountainDestination mountain(name, country, cost, altitude);
        trip += mountain;
        cout << "✓ Added: " << name << " to trip\n";
    } else {
        Destination dest(name, country, cost, "General");
        trip += dest;
        cout << "✓ Added: " << name << " to trip\n";
    }
}

void sortDestinations(Trip& trip) {
    cout << "\n===== Sort Destinations =====\n";
    int choice = readInt("Sort by: 1) Cost  2) Name\nChoose: ");
    
    if (choice == 1) {
        trip.sortByCost();
        cout << "\nDestinations sorted by cost:\n";
    } else {
        trip.sortByName();
        cout << "\nDestinations sorted by name:\n";
    }
    trip.displayDestinations();
}

void recordExpense(Trip& trip) {
    cout << "\n===== Record Expense =====\n";
    cout << "Current Budget: Rs." << trip.getBudget() << "\n";
    cout << "Remaining: Rs." << trip.getRemaining() << "\n\n";
    
    double expense = readDouble("Expense to record (Rs.): ");
    
    if (trip.spend(expense)) {
        cout << "✓ Recorded expense Rs." << expense << "\n";
        cout << "Remaining budget: Rs." << trip.getRemaining() << "\n";
    } else {
        cout << "✗ Rejected! Cannot exceed remaining budget of Rs." << trip.getRemaining() << "\n";
    }
}

void costEstimate(Trip& trip) {
    cout << "\n===== Cost Estimate =====\n";
    cout << "Total destinations: " << trip.getCount() << "\n";
    
    double costPerDay = 0;
    for (int i = 0; i < trip.getCount(); i++) {
        costPerDay += trip[i].getCost();
    }
    
    cout << "Cost per day: Rs." << costPerDay << "\n";
    cout << "For 5 days: Rs." << (costPerDay * 5) << "\n";
    cout << "Budget: Rs." << trip.getBudget() << "\n";
    
    if (costPerDay * 5 > trip.getBudget()) {
        cout << "Status: ✗ Insufficient budget!\n";
    } else {
        cout << "Status: ✓ Budget sufficient!\n";
    }
}

void copyMergeDemo(Trip& trip) {
    cout << "\n===== Copy & Merge Demo =====\n";
    
    cout << "\n--- Original Trip ---\n";
    cout << "Trip: " << trip.getTitle() << "\n";
    cout << "Destinations: " << trip.getCount() << "\n";
    
    cout << "\n--- Copying Trip ---\n";
    Trip copiedTrip = trip;
    cout << "✓ Deep copy created successfully\n";
    
    cout << "\n--- Modified Copy ---\n";
    BeachDestination beach("Dubai", "UAE", 5000, true);
    copiedTrip += beach;
    cout << "Added new destination to copy\n";
    
    cout << "\n--- Merging Trips ---\n";
    Trip merged = trip + copiedTrip;
    cout << "✓ Merged trip has " << merged.getCount() << " destinations\n";
}

void inheritanceDemo(Trip& trip) {
    cout << "\n===== Inheritance Demo =====\n";
    
    cout << "\nGeneral Destination:\n";
    Destination general("Paris", "France", 8000, "General");
    general.display();
    
    cout << "\n\nBeach Destination:\n";
    BeachDestination beach("Goa", "India", 3500, true);
    beach.display();
    
    cout << "\n\nMountain Destination:\n";
    MountainDestination mountain("Manali", "India", 2500, 2000);
    mountain.display();
    
    cout << "\n";
}

void ctorDtorDemo(Trip& trip) {
    cout << "\n===== Constructor/Destructor Tracing =====\n";
    cout << "\nCreating objects in scope:\n";
    Trace::on = true;
    
    {
        Date d(15, 11, 2024);
        Traveler t("Arjun", 22);
        Destination dest("Goa", "India", 3500, "Beach");
        Trip t2("Demo Trip", t, d, 10000);
        
        cout << "\n...all objects are alive in memory...\n";
    }
    
    cout << "\nAll objects destroyed - memory freed!\n";
    Trace::on = false;
}

int main() {
    cout << "===== ROAM - Smart Trip Planner =====\n";
    
    string name = readString("Enter Traveler Name: ");
    int age = readInt("Age: ");
    string title = readString("Trip title: ");
    int day = readInt("Start day: ");
    int month = readInt("Start month: ");
    int year = readInt("Start year: ");
    int days = readInt("Days: ");
    double budget = readDouble("Budget (Rs.): ");
    
    Traveler traveler(name, age);
    Date startDate(day, month, year);
    Trip trip(title, traveler, startDate, budget);
    
    int choice;
    while (true) {
        cout << "\n===== Menu =====\n";
        cout << "1. View trip\n";
        cout << "2. Add destination\n";
        cout << "3. Sort destinations\n";
        cout << "4. Record expense\n";
        cout << "5. Cost estimate\n";
        cout << "6. Copy and merge trips\n";
        cout << "7. Inheritance demo\n";
        cout << "8. Constructor/destructor order\n";
        cout << "9. Exit\n";
        
        choice = readInt("Enter choice: ");
        
        if (choice == 1) viewTrip(trip);
        else if (choice == 2) addDestination(trip);
        else if (choice == 3) sortDestinations(trip);
        else if (choice == 4) recordExpense(trip);
        else if (choice == 5) costEstimate(trip);
        else if (choice == 6) copyMergeDemo(trip);
        else if (choice == 7) inheritanceDemo(trip);
        else if (choice == 8) ctorDtorDemo(trip);
        else if (choice == 9) {
            cout << "\nThank you for using ROAM!\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}

