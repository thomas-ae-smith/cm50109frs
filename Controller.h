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

//Methods for accessing the model
	void makeReservation(string _name, string _code, SeatClass _class);
	void makeCancellation(string _name, string _code);
	vector<Flight*>* makePassengerInquiry(string _name);
	vector <Passenger*>* makeFlightInquiry(string _code, SeatClass _class);
	vector <Passenger*>* makeFlightWaitingInquiry(string _code, SeatClass _class);

//Setters and getters
	Model* getModel();
	AbstractView* getView();

};

#endif // CONTROLLER_H
