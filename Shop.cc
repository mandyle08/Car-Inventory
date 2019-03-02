#include "Shop.h"
#include "defs.h"

Shop::Shop() : numMechanics(0) { }

//void Shop::addCustomer(Customer* c) { customers += c; }
Shop& Shop::operator+=(Customer* c) { 
    customers += c; 
    return *this;
}

Shop& Shop::operator-=(Customer* c) { 
    customers -= c; 
    return *this;
}

Customer* Shop::getCustomer(int i)  {  
  
  for(int j=0; j<customers.getSize(); j++){
    if(customers[j]->getId()==i)
      return customers[j];

  }

    return 0;
} 

LinkedList<Customer>&  Shop::getCustomers() { return customers; }

Shop& Shop::operator+=(Mechanic* m) {    
    
    mechanics+=m;

    return *this;
}

int Shop::getNumMechanics()     { return numMechanics; }
LinkedList<Mechanic>& Shop::getMechanics()  { return mechanics; }
