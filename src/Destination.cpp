#include "Destination.h"
#include "Trace.h"

Destination::Destination() : name("Unknown"), country("Unknown"), costPerDay(0), type("General") {
    if (Trace::on)
        cout << ">> Destination constructor (default): Destination created\n";
}

Destination::Destination(const string& n, const string& c, double cost, const string& t) 
    : name(n), country(c), costPerDay(cost), type(t) {
    if (Trace::on)
        cout << ">> Destination constructor: " << name << " created\n";
}

Destination::Destination(const Destination& other) 
    : name(other.name), country(other.country), costPerDay(other.costPerDay), type(other.type) {
    if (Trace::on)
        cout << ">> Destination copy constructor: Destination copied\n";
}

Destination::~Destination() {
    if (Trace::on)
        cout << ">> Destination destructor: Destination destroyed\n";
}

void Destination::display() const {
    cout << name << ", " << country << " - Rs." << costPerDay << "/day";
}

string Destination::toString() const {
    return name + ", " + country + " - Rs." + to_string((int)costPerDay) + "/day";
}

bool Destination::operator<(const Destination& other) const {
    return costPerDay < other.costPerDay;
}

bool Destination::operator==(const Destination& other) const {
    return (name == other.name && country == other.country);
}

Destination& Destination::operator=(const Destination& other) {
    if (this != &other) {
        name = other.name;
        country = other.country;
        costPerDay = other.costPerDay;
        type = other.type;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Destination& d) {
    os << d.name << ", " << d.country << " - Rs." << d.costPerDay << "/day";
    return os;
}

BeachDestination::BeachDestination() : Destination("Unknown", "Unknown", 0, "Beach"), waterSports(false) {
    if (Trace::on)
        cout << ">> BeachDestination constructor (default): Beach created\n";
}

BeachDestination::BeachDestination(const string& n, const string& c, double cost, bool sports)
    : Destination(n, c, cost, "Beach"), waterSports(sports) {
    if (Trace::on)
        cout << ">> BeachDestination constructor: " << n << " created\n";
}

BeachDestination::BeachDestination(const BeachDestination& other)
    : Destination(other), waterSports(other.waterSports) {
    if (Trace::on)
        cout << ">> BeachDestination copy constructor: Beach copied\n";
}

BeachDestination::~BeachDestination() {
    if (Trace::on)
        cout << ">> BeachDestination destructor: Beach destroyed\n";
}

void BeachDestination::display() const {
    cout << name << ", " << country << " - Rs." << costPerDay << "/day (Beach";
    if (waterSports) cout << " - Water Sports Available";
    cout << ")";
}

string BeachDestination::toString() const {
    return name + ", " + country + " - Rs." + to_string((int)costPerDay) + "/day (Beach)";
}

MountainDestination::MountainDestination() : Destination("Unknown", "Unknown", 0, "Mountain"), altitude(0) {
    if (Trace::on)
        cout << ">> MountainDestination constructor (default): Mountain created\n";
}

MountainDestination::MountainDestination(const string& n, const string& c, double cost, double alt)
    : Destination(n, c, cost, "Mountain"), altitude(alt) {
    if (altitude > 3000)
        costPerDay += 500;
    if (Trace::on)
        cout << ">> MountainDestination constructor: " << n << " created\n";
}

MountainDestination::MountainDestination(const MountainDestination& other)
    : Destination(other), altitude(other.altitude) {
    if (Trace::on)
        cout << ">> MountainDestination copy constructor: Mountain copied\n";
}

MountainDestination::~MountainDestination() {
    if (Trace::on)
        cout << ">> MountainDestination destructor: Mountain destroyed\n";
}

void MountainDestination::display() const {
    cout << name << ", " << country << " - Rs." << costPerDay << "/day (Mountain - Altitude: " 
         << altitude << "m)";
}

string MountainDestination::toString() const {
    return name + ", " + country + " - Rs." + to_string((int)costPerDay) + "/day (Mountain)";
}

