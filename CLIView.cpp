#include "CLIView.h"
#include <iostream>
#include <vector>
using namespace std;


//Check if the answer is yes or no
bool CLIView::checkAnswer(char _answer)
{
   if(_answer=='y' || _answer=='Y' || _answer=='1')
   {
       return true;
   }
   else
   {
    return false;
   }
}

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

//Add to database
//Reservation
    void CLIView::makeReservationEvent(string _name, string _code, SeatClass _class)
    {
	m_controller->makeReservation(_name, _code, _class);
    }

//Cancellation
    void CLIView::makeCancellationEvent(string _name, string _code)
    {
         m_controller->makeCancellation(_name, _code);
    }

//Get from database
//Passenger Inquiry
    void CLIView::makePassengerInquiryEvent(string _name)
    {
	displayFlights(m_controller->makePassengerInquiry(_name));
    }

//Flight Inquiry
    void CLIView::makeFlightInquiry(string _code)
    {
      displayPassengers(m_controller->makeFlightInquiry(_code, SeatClass.First));
      displayPassengers(m_controller->makeFlightWaitingInquiry(_code, SeatClass.First));
      displayPassengers(m_controller->makeFlightInquiry(_code, SeatClass.Economy));
      displayPassengers(m_controller->makeFlightWaitingInquiry(_code, SeatClass.Economy));
    }


//Auxiliary methods

    bool CLIView::yesNoPopup(string _message)
    {
	char option;
	cout<<_message;
	cin>>option;

	return checkAnswer(option);
    }


    void CLIView::popupMessage(string _message)
    {
	cout<<_message;
    }
    
