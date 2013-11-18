#include "AbstractView.h"

//Command line View class

class CLIView: public class AbstractView
{
//This is an abstract interface for the view
//Different types of views will inherit from this class and implement their own methods

public:

//Display one passenger's information (name)
    void displayPassenger(Passenger* _passenger);

//Display one flight's information (code, number of seats, time and date)
    void displayFlight(Flight* _flight);
    
//Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
    void displayPassengers(vector<Passenger*>* _passengers);    

//Display all the flights a passenger's on
    void displayFlights(vector<Flight*>* _flights);   


//Reservation
    void makeReservationEvent(string _name, string _code, SeatClass _class);
//Cancellation
    void makeCancellationEvent(string _name, string _code);
//Passenger Inquiry
    void makePassengerInquiryEvent(string _name);
//Flight Inquiry
    void makeFlightInquiry(string _code);


//Auxiliary methods

    bool checkAnswer(char _answer);

    bool yesNoPopup(string _message);

    void popupMessage(string _message);

};
