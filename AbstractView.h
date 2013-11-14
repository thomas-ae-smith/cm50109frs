#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include "Flight.h"
#include "Passenger.h"

class AbstractView{

//This is an abstract interface for the view
//Different types of views will inherit from this class and implement their own methods

public:

//All virtual functions (do not require implementation)
//Constructor and destructor
    AbstractView();	
    ~AbstractView();
	
//Display one passenger's information (name)
    virtual void displayPassenger(Passenger* _passenger);

//Display one flight's information (code, number of seats, time and date)
    virtual void displayFlight(Flight* _flight);
    
//Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
    virtual void displayPassengers(vector<Passenger*>* _passengers);    

//Display all the flights a passenger's on
    virtual void displayFlights(vector<Flight*>* _flights);
    
};

#endif // ABSTRACTVIEW_H
