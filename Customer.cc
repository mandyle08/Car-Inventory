#include <iostream>
using namespace std;
#include "Customer.h"
#include "LinkedList.h"

int Customer::nextId = 1000;
/*
Purpose:Constuctor
input/output: firstname, lastname, address, phone number
return: none

*/
Customer::Customer(string fname, string lname, string add, string pnum) : 
        Person(fname,lname,add,pnum), id(Customer::nextId++) { }
/*
Function: getId
Purpose:gets id
input/output:none
return: id

*/
int           Customer::getId() const           { return id; }


/*
Function: getNumVehicle
Purpose:gets number of vehicles
input/output:none
return: number of vehicles

*/
int           Customer::getNumVehicles() const  { return vehicles.getSize(); }

/*
Function: getVehicle
Purpose:gets vehicle
input/output:none
return: Gets vehicle info

*/
LinkedList<Vehicle>&  Customer::getVehicles()           { return vehicles; }
//void          Customer::addVehicle(Vehicle* v)  { vehicles.add(v); }

/*
Function: += operator
Purpose:adds vehicle to list
input/output:vehicle
return:none

*/
Customer& Customer::operator+=(Vehicle* v)
{
    vehicles += v;
    return *this;
}

/*
Function: < operator
Purpose: compare of customer objects
input/output:none
return: customer with higher last name

*/
bool Customer::operator<(Customer& c)
{
    return lastName < c.lastName;
}

/*
Function: > operator
Purpose: compare of customer objects
input/output:none
return: the customer with the lower last name

*/

bool Customer::operator>(Customer& c)
{
    return lastName > c.lastName;
}

/*
Function: << operator
Purpose: prints contents of customer objects
input/output:none
return: customers

*/
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
}
