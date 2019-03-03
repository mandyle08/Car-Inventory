#include <iostream>
using namespace std;
#include "Customer.h"
#include "LinkedList.h"

int Customer::nextId = 1000;

Customer::Customer(string fname, string lname, string add, string pnum) : 
        Person(fname,lname,add,pnum), id(Customer::nextId++) { }
        
// get customer id        
int Customer::getId() const { return id; }


int Customer::getNumVehicles() const  { return vehicles.getSize(); }

// Gets vehicle info
LinkedList<Vehicle>&  Customer::getVehicles()  { return vehicles; }

// adds vehicle to list
Customer& Customer::operator+=(Vehicle* v)
{
    vehicles += v;
    return *this;
}

// return customer with higher last name
bool Customer::operator<(Customer& c)
{
    return lastName < c.lastName;
}

// return the customer with the lower last name
bool Customer::operator>(Customer& c)
{
    return lastName > c.lastName;
}

// print contents of customer objects
ostream& operator<<(ostream& output, Customer& c)
{
    ostringstream name;
    name << c.firstName << " " << c.lastName;

    output << "Customer ID " << c.id << endl << endl
           << "    Name: " << setw(40) << name.str() << endl 
           << "    Address: " << setw(37) << c.address << endl
           << "    Phone Number: " << setw(32) << c.phoneNumber << endl;
    
    if (c.getNumVehicles() > 0) {
        output << endl << "    " << c.getNumVehicles() << " vehicle(s): " << endl << endl;
        output << c.getVehicles() << endl<<endl;
    }
  return output;
}
