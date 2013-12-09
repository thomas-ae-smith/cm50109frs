#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include "Model.h"
#include <string>

class Controller;

class AbstractView {

//This is an abstract interface for the view
//Different types of views will inherit from this class and implement their own methods

public:

//All virtual functions (do not require implementation)

	
//Help
	virtual void help() = 0;

//Starting point
	virtual void start() = 0;

//Refresh
    virtual void refresh() = 0;    

//Displaying Information
//Display one passenger's information (name)
    virtual void displayPassenger(Passenger* _passenger) = 0;

//Display one flight's information (code, number of seats, time and date)
    virtual void displayFlight(Flight* _flight) = 0;
    
//Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
    virtual void displayPassengers(pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>* _passengers) = 0;

//Display all the flights a passenger's on
    virtual void displayFlights(vector<Flight*>* _flights) = 0;


//Methods from interface
//Takes info from interface and delivers it to controller which then updates model
//Messages of the actions taken will then be sent from the controller to the view
//Once updated the model will ask the view to update

//Reservation
    virtual void makeReservationEvent(string _name, string _code, string _class) = 0;

//Cancellation
    virtual void makeCancellationEvent(string _name, string _code) = 0;

//Passenger Inquiry
    virtual void makePassengerInquiryEvent(string _name) = 0;

//Flight Inquiry
    virtual void makeFlightInquiryEvent(string _code) = 0;


//Auxiliary methods
    virtual bool checkAnswer(char _answer) = 0;
    virtual bool yesNoDialog(string _message) = 0;
    virtual void dialogMessage(string _message) = 0;

//Setters and getters
    virtual void setController(Controller* _controller) = 0;
    virtual Controller* getController() = 0;    
};

#endif // ABSTRACTVIEW_H
