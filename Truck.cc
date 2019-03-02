#include <string>
#include "Vehicle.h"
#include "Truck.h"
using namespace std;


/*
Purpose:Constuctor
input/output: make, model, colour, year, mileage, axel
return: none

*/
Truck::Truck(string ma, string mo, string col, int y, int m, int a) :
  Vehicle(ma, mo, col, y, m), axles(a) {}

/*
Function: << operator
Purpose: prints contents of truck objects
input/output:none
return: trucks

*/
void Truck::toString(string& outStr){
    ostringstream ss;

      ostringstream make_model;
      make_model << getMake() << " " << getModel();

      ss << setw(11)<<"TRUCK:\t" << setw(7) << getColour()<< " "
        << "   Year:" << getYear() << " " << setw(17) << make_model.str() << " ("
        << getMilage() << "km)" << " " << getAxles() << " Axles";

    ss<<endl;
    outStr=ss.str();
  }

int Truck::getAxles() const{
  return axles;
}
