#ifndef TRAVELER_H
#define TRAVELER_H

#include <iostream>
#include <string>
using namespace std;

class Traveler {
private:
    string name;
    int age;

public:
    Traveler();
    Traveler(const string& n, int a);
    Traveler(const Traveler& other);
    ~Traveler();
    
    string getName() const { return name; }
    int getAge() const { return age; }
    
    bool setName(const string& n);
    bool setAge(int a);
    
    void display() const;
    string toString() const;
    
    Traveler& operator=(const Traveler& other);
    bool operator==(const Traveler& other) const;
    
    friend ostream& operator<<(ostream& os, const Traveler& t);
};

#endif

