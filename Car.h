#ifndef CAR_H
#define CAR_H

#include <string>

class Car: public Vehicle {

  public:

    Car(string, string, string, int, int);
    virtual void toString(string&);

};

#endif
