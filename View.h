#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"
#include "Mechanic.h"
#include "LinkedList.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(LinkedList<Customer>&) const;
        void pause() const;
        void promptUserInfo(string&, string&, string&, string&);
        void promptUserId(int&);
        void promptVehicleType(int&);
        void displayInvalid();
        void promptVehicleInfo(string&, string&, string&, int&, int&);
        void promptTruckInfo(string&, string&, string&, int&, int&, int&);
        void promptCarInfo(string&, string&, string&, int&, int&);
        void promptMotorcycleInfo(string&, string&, string&, int&, int&, bool&);
        void promptVehicle(int, int&);
        void printMechanics(LinkedList<Mechanic>&) const;
    private:
        int readInt() const;
};

#endif
