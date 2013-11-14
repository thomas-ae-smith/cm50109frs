#include "CLIView.h"
#include <iostream>
#include <vector>
using namespace std;

//Display one passenger's information (name)
    void CLIView::displayPassenger(Passenger* _passenger)
    {
      cout<<_passenger->getName()<<endl;
    }

//Display one flight's information (code, number of seats, time and date)
    void CLIView::displayFlight(Flight* _flight)
    {
      cout<<_flight->getName()<<endl;
    }
    
//Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
    void CLIView::displayPassengers(vector<Passenger*>* _passengers)
    {
     vector<Passenger*>::iterator it;
     for (it = (*_passengers).begin(); it != (*_passengers).end(); it++) 
	{
	 displayPassenger((*it));	
	}
    }

//Display all the flights a passenger's on
    void CLIView::displayFlights(vector<Flight*>* _flights)
    {
     vector<Flight*>::iterator it;
     for (it = (*_flights).begin(); it != (*_flights).end(); it++) 
	{
	 displayFlight((*it));	
	}
    }
    
