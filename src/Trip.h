#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include <string>
#include "Destination.h"
#include "Traveler.h"
#include "Date.h"
using namespace std;

class Trip {
private:
    string title;
    Traveler traveler;
    Date startDate;
    Destination* stops;
    double budget, spent;
    int count, capacity;
    
    void grow();

public:
    Trip();
    Trip(const string& t, const Traveler& tr, const Date& d, double b);
    Trip(const Trip& other);
    ~Trip();
    
    string getTitle() const { return title; }
    int getCount() const { return count; }
    double getBudget() const { return budget; }
    double getSpent() const { return spent; }
    double getRemaining() const { return budget - spent; }
    
    void setTitle(const string& t) { title = t; }
    
    void addDestination(const Destination& dest);
    bool spend(double amount);
    
    void sortByCost();
    void sortByName();
    
    void display() const;
    void displayDestinations() const;
    
    Trip& operator+=(const Destination& d);
    Trip operator+(const Trip& other) const;
    Trip& operator=(const Trip& other);
    Destination& operator[](int index);
    
    friend ostream& operator<<(ostream& os, const Trip& t);
};

#endif

