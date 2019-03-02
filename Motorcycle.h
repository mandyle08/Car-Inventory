#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include <string>
#include "Vehicle.h"

using namespace std;

class Motorcycle : public Vehicle{

  public:
    Motorcycle(string, string, string, int, int, bool);
    bool getSideCar() const;
    virtual void toString(string&);
  protected:
    int sideCar;
};

#endif
