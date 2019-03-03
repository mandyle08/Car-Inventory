#include <string>
#include "Vehicle.h"
#include "Motorcycle.h"
using namespace std;

/*
Purpose:Constuctor
input/output: make, model, colour, year, mileage, sidecar
return: none

*/
Motorcycle::Motorcycle(string ma, string mo, string col, int y, int m, bool s) :
  Vehicle(ma, mo, col, y, m), sideCar(s) {}

  /*
Function: << operator
Purpose: prints contents of motorcycle objects
input/output:none
return: motorcycle

*/
void Motorcycle::toString(string& outStr){
    ostringstream ss;

      ostringstream make_model;
      make_model << getMake() << " " << getModel();

      ss <<setw(11)<< "MOTORCYCLE\t" << setw(7) << getColour()<< " "
        << "   Year:" << getYear() << " " << setw(17) << make_model.str() << " ("
        << getMilage() << "km)" << " SideCar present: " << getSideCar();

    ss<<endl;
    outStr=ss.str();
  }

bool Motorcycle::getSideCar() const{
  return sideCar;
}
