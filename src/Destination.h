#ifndef DESTINATION_H
#define DESTINATION_H

#include <iostream>
#include <string>
using namespace std;

class Destination {
protected:
    string name, country;
    double costPerDay;
    string type;

public:
    Destination();
    Destination(const string& n, const string& c, double cost, const string& t);
    Destination(const Destination& other);
    virtual ~Destination();
    
    string getName() const { return name; }
    string getCountry() const { return country; }
    double getCost() const { return costPerDay; }
    string getType() const { return type; }
    
    void setName(const string& n) { name = n; }
    void setCountry(const string& c) { country = c; }
    void setCost(double c) { costPerDay = c; }
    
    virtual void display() const;
    virtual string toString() const;
    
    bool operator<(const Destination& other) const;
    bool operator==(const Destination& other) const;
    Destination& operator=(const Destination& other);
    
    friend ostream& operator<<(ostream& os, const Destination& d);
};

class BeachDestination : public Destination {
private:
    bool waterSports;

public:
    BeachDestination();
    BeachDestination(const string& n, const string& c, double cost, bool sports);
    BeachDestination(const BeachDestination& other);
    ~BeachDestination();
    
    bool hasWaterSports() const { return waterSports; }
    void setWaterSports(bool w) { waterSports = w; }
    
    void display() const override;
    string toString() const override;
};

class MountainDestination : public Destination {
private:
    double altitude;

public:
    MountainDestination();
    MountainDestination(const string& n, const string& c, double cost, double alt);
    MountainDestination(const MountainDestination& other);
    ~MountainDestination();
    
    double getAltitude() const { return altitude; }
    void setAltitude(double a) { altitude = a; }
    
    void display() const override;
    string toString() const override;
};

#endif

