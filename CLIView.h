#include "AbstractView.h"

//Command line View class

class CLIView: public class AbstractView
{
//This is an abstract interface for the view
//Different types of views will inherit from this class and implement their own methods

public:

   CLIView();
   ~CLIView();	

	
//Help
void help();

//Starting point
 void start();

//Display one passenger's information (name)
    void displayPassenger(Passenger* _passenger);

//Display one flight's information (code, number of seats, time and date)
    void displayFlight(Flight* _flight);
    
//Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
    void displayPassengers(vector<Passenger*>* _passengers);    

//Display all the flights a passenger's on
    void displayFlights(vector<Flight*>* _flights);   

//CLI prompt methods

	void reservationPrompt(string _reservation);
	void cancellationPrompt(string _cancellation);
	void passengerInqPrompt(string _passengerInq);
	void flightInqPrompt(string _flightInq);

	


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
    bool yesNoDialog(string _message);
    void dialogMessage(string _message);

//Setters and Getters
    void setController(Controller* _controller);
    Controller* getController(); 		

private:
    Controller* m_controller;
};
