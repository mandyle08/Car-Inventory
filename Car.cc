#include <string>
#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include <sstream>

using namespace std;

/*
Purpose:Constuctor
input/output: make, model, colour, year, mileage
return: none

*/
Car::Car(string ma, string mo, string col, int y, int m) :
  Vehicle(ma, mo, col, y, m){}

  /*
Function: << operator
Purpose: prints contents of car objects
input/output:none
return: cars

*/
void Car::toString(string& outStr){
    ostringstream ss;

      ostringstream make_model;
      make_model << getMake() << " " << getModel();

      ss <<setw(11)<< "CAR:\t" << setw(7) << getColour()<< " "
        << "   Year:" << getYear() << " " << setw(17) << make_model.str() << " ("
        << getMilage() << "km)";
    
    ss<<endl;
    outStr=ss.str();
  }
