#include "Trip.h"
#include "Trace.h"
#include <algorithm>

Trip::Trip() : title("Untitled"), traveler(), startDate(), stops(nullptr), budget(0), spent(0), count(0), capacity(2) {
    stops = new Destination[capacity];
    if (Trace::on)
        cout << ">> Trip constructor (default): Trip created\n";
}

Trip::Trip(const string& t, const Traveler& tr, const Date& d, double b)
    : title(t), traveler(tr), startDate(d), budget(b), spent(0), count(0), capacity(2) {
    stops = new Destination[capacity];
    if (Trace::on)
        cout << ">> Trip constructor: " << title << " created\n";
}

Trip::Trip(const Trip& other) 
    : title(other.title), traveler(other.traveler), startDate(other.startDate), 
      budget(other.budget), spent(other.spent), count(other.count), capacity(other.capacity) {
    stops = new Destination[capacity];
    for (int i = 0; i < count; i++)
        stops[i] = other.stops[i];
    if (Trace::on)
        cout << ">> Trip copy constructor: Trip copied\n";
}

Trip::~Trip() {
    delete[] stops;
    if (Trace::on)
        cout << ">> Trip destructor: Trip destroyed\n";
}

void Trip::grow() {
    Destination* newStops = new Destination[capacity * 2];
    for (int i = 0; i < count; i++)
        newStops[i] = stops[i];
    delete[] stops;
    stops = newStops;
    capacity *= 2;
}

void Trip::addDestination(const Destination& dest) {
    if (count >= capacity)
        grow();
    stops[count++] = dest;
}

bool Trip::spend(double amount) {
    if (amount < 0 || amount > getRemaining())
        return false;
    spent += amount;
    return true;
}

void Trip::sortByCost() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (stops[j].getCost() > stops[j + 1].getCost()) {
                Destination temp = stops[j];
                stops[j] = stops[j + 1];
                stops[j + 1] = temp;
            }
        }
    }
}

void Trip::sortByName() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (stops[j].getName() > stops[j + 1].getName()) {
                Destination temp = stops[j];
                stops[j] = stops[j + 1];
                stops[j + 1] = temp;
            }
        }
    }
}

void Trip::display() const {
    cout << "\n===== Trip Details =====\n";
    cout << "Trip: " << title << "\n";
    cout << "Traveler: " << traveler << "\n";
    cout << "Start Date: " << startDate << "\n";
    cout << "Days: 5\n";
    cout << "Budget: Rs." << budget << "\n";
    cout << "Spent: Rs." << spent << "\n";
    cout << "Destinations: " << count << "\n";
    cout << "Remaining: Rs." << getRemaining() << "\n";
}

void Trip::displayDestinations() const {
    cout << "\n===== Destinations =====\n";
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ". ";
        stops[i].display();
        cout << "\n";
    }
}

Trip& Trip::operator+=(const Destination& d) {
    addDestination(d);
    return *this;
}

Trip Trip::operator+(const Trip& other) const {
    Trip merged = *this;
    for (int i = 0; i < other.count; i++)
        merged += other.stops[i];
    return merged;
}

Trip& Trip::operator=(const Trip& other) {
    if (this != &other) {
        delete[] stops;
        title = other.title;
        traveler = other.traveler;
        startDate = other.startDate;
        budget = other.budget;
        spent = other.spent;
        count = other.count;
        capacity = other.capacity;
        stops = new Destination[capacity];
        for (int i = 0; i < count; i++)
            stops[i] = other.stops[i];
    }
    return *this;
}

Destination& Trip::operator[](int index) {
    if (index >= 0 && index < count)
        return stops[index];
    throw out_of_range("Invalid index");
}

ostream& operator<<(ostream& os, const Trip& t) {
    os << "Trip: " << t.title << "\n";
    os << "Traveler: " << t.traveler << "\n";
    os << "Start Date: " << t.startDate << "\n";
    os << "Budget: Rs." << t.budget << "\n";
    os << "Destinations: " << t.count << "\n";
    return os;
}

