#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

class Flight;
class Passenger;
class SeatClass;

#include <string>
#include <vector>

using namespace std;

class AbstractView{

//This is an abstract interface for the view
//Different types of views will inherit from this class and implement their own methods

public:

//All virtual functions (do not require implementation)

	
//Help
	virtual void help() = 0;

//Starting point
	virtual void start();

//Displaying Information
//Display one passenger's information (name)
    virtual void displayPassenger(Passenger* _passenger);

//Display one flight's information (code, number of seats, time and date)
    virtual void displayFlight(Flight* _flight);
    
//Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
    virtual void displayPassengers(vector<Passenger*>* _passengers);    

//Display all the flights a passenger's on
    virtual void displayFlights(vector<Flight*>* _flights);


//Methods from interface
//Takes info from interface and delivers it to controller which then updates model
//Messages of the actions taken will then be sent from the controller to the view
//Once updated the model will ask the view to update

//Reservation
    virtual void makeReservationEvent(string _name, string _code, SeatClass _class);
//Cancellation
    virtual void makeCancellationEvent(string _name, string _code);
//Passenger Inquiry
    virtual void makePassengerInquiryEvent(string _name);
//Flight Inquiry
    virtual void makeFlightInquiry(string _code);


//Auxiliary methods

    virtual bool checkAnswer(char _answer);

    virtual bool yesNoDialog(string _message);

    virtual void dialogMessage(string _message);




    
};

#endif // ABSTRACTVIEW_H
