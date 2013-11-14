#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string.h>
#include "Passenger.h"
#include "Flight.h"


class Controller
{
//The controller class that stands between the data (model) and the visual display (view)

private:
//Pointers to the model and the view
    Model* m_model;
    View* m_view;

public:

//Constructor and destructor of Xontroller class
    Controller(Model* _model, View *_view);
    ~Controller();

//Methods for accessing the model
    string makeReservation(string _name, string _number, SeatClass _class);
    string makeCancellation(string _name, string _code);
    vector<Flight*> makePassengerEnquiry(string _name);
    vector <Passenger*> makeFlightEnquiry(string _code, SeatClass _class);
    vector <Passenger*> makeFlightWaitingEnquiry(string _code, SeatClass _class);

//Methods for accessing the view
	void displayPassengers(vector<Passenger*>* _passengers);	
	void displayFlights(vector<Flight*>* _flights);	
};

#endif // CONTROLLER_H
