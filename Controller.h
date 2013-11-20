#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string.h>
#include "Passenger.h"
#include "Flight.h"
#include "AbstractView.h"


class Controller
{
//The controller class that stands between the data (model) and the visual display (view)

private:
//Pointers to the model and the view
    Model* m_model;
    AbstractView* m_view;

public:

//Constructor and destructor of Xontroller class
    Controller(Model* _model, AbstractView *_view);
    ~Controller();

//Methods for accessing the model
    void makeReservation(string _name, string _code, SeatClass _class);
    void makeCancellation(string _name, string _code);
    vector<Flight*>* makePassengerInquiry(string _name);
    vector <Passenger*>* makeFlightInquiry(string _code, SeatClass _class);
    vector <Passenger*>* makeFlightWaitingInquiry(string _code, SeatClass _class);

//Methods for accessing the view
    void refreshPassengers(vector<Passenger*>* _passengers);
    void refreshFlights(vector<Flight*>* _flights);

//Setters and getters
    Model* getModel();
    AbstractView* getView();	

};

#endif // CONTROLLER_H
