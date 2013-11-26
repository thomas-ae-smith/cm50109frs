#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include <vector>
#include "Model.h"
#include "AbstractView.h"


class Controller
{
//The controller class that stands between the data (model) and the visual display (view)

private:
//Pointers to the model and the view
	Model* m_model;
	AbstractView* m_view;

public:

//Constructor and destructor of Controller class
	Controller(Model* _model, AbstractView *_view);
	~Controller();

//Make a reservation by getting the info from the view and passing it to the model
    void makeReservation(string _name, string _code, string _class);

//Make a cancellation, given the passenger name and flight code
	void makeCancellation(string _name, string _code);

// Make a passenger inquiry, ie. return the flights the passenger's on
	vector<Flight*>* makePassengerInquiry(string _name);

// Make a flight inquiry, ie return the passengers waiting or booked on a certain flight
    pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>* makeFlightInquiry(string _code, Flight::SeatClass _class, Flight::SeatStatus _status);

 //Check if a passenger has any flights on the same day with the given flight
    bool hasSameDayFlights(string _name, Flight* _flight);


//Setters and getters
	Model* getModel();
	AbstractView* getView();
};

#endif // CONTROLLER_H
