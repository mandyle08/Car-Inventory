#include "VehicleFactory.h"
#include <string>

using namespace std;


/*
Purpose:creates car
input/output: make, model, colour, year, mileage
return: none

*/
Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m){
  
  return new Car(ma,mo,col,y,m);

}

/*
Purpose:Creates a truck
input/output: make, model, colour, year, mileage, axel
return: none

*/
Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m, int a){

  return new Truck(ma,mo,col,y,m,a);
}

/*
Purpose:Creates a Motorcycle
input/output: make, model, colour, year, mileage, sidecar
return: none

*/
Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m, bool s){ 

  return new Motorcycle(ma,mo,col,y,m,s);
}



