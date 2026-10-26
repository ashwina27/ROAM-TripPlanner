#include "Traveler.h"
#include "Trace.h"

Traveler::Traveler() : name("Unknown"), age(0) {
    if (Trace::on)
        cout << ">> Traveler constructor (default): Traveler created\n";
}

Traveler::Traveler(const string& n, int a) : name(n), age(a) {
    if (Trace::on)
        cout << ">> Traveler constructor (parameterized): " << name << " created\n";
}

Traveler::Traveler(const Traveler& other) : name(other.name), age(other.age) {
    if (Trace::on)
        cout << ">> Traveler copy constructor: Traveler copied\n";
}

Traveler::~Traveler() {
    if (Trace::on)
        cout << ">> Traveler destructor: Traveler destroyed\n";
}

bool Traveler::setName(const string& n) {
    if (n.length() > 0) {
        name = n;
        return true;
    }
    return false;
}

bool Traveler::setAge(int a) {
    if (a > 0 && a < 120) {
        age = a;
        return true;
    }
    return false;
}

void Traveler::display() const {
    cout << name << " (Age: " << age << ")";
}

string Traveler::toString() const {
    return name + " (Age: " + to_string(age) + ")";
}

Traveler& Traveler::operator=(const Traveler& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
    }
    return *this;
}

bool Traveler::operator==(const Traveler& other) const {
    return (name == other.name && age == other.age);
}

ostream& operator<<(ostream& os, const Traveler& t) {
    os << t.name << " (Age: " << t.age << ")";
    return os;
}

