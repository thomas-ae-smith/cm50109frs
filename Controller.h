#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string.h>
#include "Passenger.h"
#include "Flight.h"


class Crontroller
{
private:
    Model* m_model;
    View* m_view;

public:
    Controller(string _filename);
    ~Controller();

    string makeReservation(string _name, string _number, SeatClass _class);
    string makeCancellation(string _name, string _number);
    vector<Flight*> makePassengerEnquiry(string _name);
    vector <Passenger*> makeFlightEnquiry(string _code, SeatClass _class);
    vector <Passenger*> makeFlightWaitingEnquiry(string _code, SeatClass _class);



};

#endif // CONTROLLER_H
