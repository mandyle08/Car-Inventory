#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class Vehicle {

    friend ostream& operator<<(ostream&, Vehicle&);

    public:
        Vehicle(string, string, string, int, int);
        virtual ~Vehicle() =0;  
        string getMake() const;
        string getModel() const;
        string getColour() const;
        int getYear() const;
        int getMilage() const;

        bool operator<(Vehicle&);
        bool operator>(Vehicle&);

    protected:
        string make;
        string model;
        string colour;
        int year;
        int mileage;
        virtual void toString(string&)=0;
};

#endif
