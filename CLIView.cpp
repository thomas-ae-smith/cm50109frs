#include "CLIView.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include "Controller.h"

//TODO: All the prompt methods need to be implemented

using namespace std;

CLIView::CLIView() {
	m_controller = NULL;
}

CLIView::~CLIView() {}

//Help
void CLIView::help()
{
    //Prints out the list of available commands
}

//CLI prompt methods
void CLIView::reservationPrompt(string _reservation)
{
    //_reservation is of the form [r name surname flight code class]

     string buffer; // Have a buffer string
     stringstream ss(_reservation); // Insert the string into a stream
     vector<string> tokens; // Create vector to hold the tokens

     while (ss >> buffer)
     {
         tokens.push_back(buffer);
     }
     if(tokens.size() == 5)
     {
        this->makeReservationEvent(tokens[1]+tokens[2], tokens[3], tokens[4]);
        this->dialogMessage("You have made a reservation! ");
     }
     else
     {
         this->dialogMessage("The format for reservation: r name surname flght_code class. ");
     }
}

void CLIView::cancellationPrompt(string _cancellation)
{
    cout<<"You are making a cancellation "<<_cancellation<<endl;
}

void CLIView::passengerInqPrompt(string _passengerInq)
{
    cout<<"You are making a passenger inquiry "<<_passengerInq<<endl;
}

void CLIView::flightInqPrompt(string _flightInq)
{
    cout<<"You are making a flight inquiry"<<_flightInq<<endl;
}

//Starting point
void CLIView::start() {
	bool quit = false;
	while(!quit) {
		string option;
		cout << "FRS>: ";
		cin >> option;
		switch(tolower(option[0])) {
			case 'r':
				reservationPrompt(option);
				break;
			case 'c':
				cancellationPrompt(option);
				break;
			case 'p':
				passengerInqPrompt(option);
				break;
			case 'f':
				flightInqPrompt(option);
				break;
            case 'e':
				quit = true;
				break;
            case '?':
            case 'h':
				help();
				break;
			default:
				cout << "Unrecognised command: " << option << endl;
				help();
				break;
		}
	}
}

//Check if the answer is yes or no
bool CLIView::checkAnswer(char _answer) {
	if(tolower(_answer)=='y' || _answer=='1') {
		return true;
	}
	else
	{
		return false;
	}
}

//Display one passenger's information (name)
void CLIView::displayPassenger(Passenger* _passenger) {

    if(_passenger != NULL)
    {
        cout << _passenger->getName() << endl;
    }
}

//Display one flight's information (code, number of seats, time and date)
void CLIView::displayFlight(Flight* _flight) {

    if(_flight != NULL)
    {
        cout << _flight->getCode() << endl;
    }
}

//Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
void CLIView::displayPassengers(pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>* _passengers) {

  if(_passengers != NULL)
   {
    vector<Passenger*>::iterator it;
    for (it = _passengers->first; *it != *(_passengers->second); ++it)
     {
        displayPassenger(*it);
     }
   }
}

//Display all the flights a passenger's on
void CLIView::displayFlights(vector<Flight*>* _flights) {

   if(_flights != NULL)
    {
     vector<Flight*>::iterator it;
     for (it = (*_flights).begin(); it != (*_flights).end(); ++it)
     {
		displayFlight((*it));
     }
   }
}

//Adds to database
//Reservation
void CLIView::makeReservationEvent(string _name, string _code, string _class) {
	m_controller->makeReservation(_name, _code, _class);
}

//Cancellation
void CLIView::makeCancellationEvent(string _name, string _code)
{
	m_controller->makeCancellation(_name, _code);
}

//Gets from database
//Passenger Inquiry
void CLIView::makePassengerInquiryEvent(string _name) {
	displayFlights(m_controller->makePassengerInquiry(_name));
}

//Flight Inquiry
void CLIView::makeFlightInquiryEvent(string _code) {
    //TODO: Make this into one function that iterates through classes and statuses
    displayPassengers(m_controller->makeFlightInquiry(_code, Flight::First, Flight::Booked));
    displayPassengers(m_controller->makeFlightInquiry(_code, Flight::First, Flight::Waiting));
    displayPassengers(m_controller->makeFlightInquiry(_code, Flight::Economy, Flight::Booked));
    displayPassengers(m_controller->makeFlightInquiry(_code, Flight::Economy, Flight::Waiting));
}


//Auxiliary methods
bool CLIView::yesNoDialog(string _message) {
	char option;
	cout << _message;
	cin >> option;

	return checkAnswer(option);
}


void CLIView::dialogMessage(string _message) {
	cout << _message;
}

void CLIView::setController(Controller* _controller) {
	 m_controller = _controller;
}

Controller* CLIView::getController() {
	return m_controller;
}

void CLIView::refresh() {}
