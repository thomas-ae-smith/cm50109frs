#include "CLIView.h"
#include <iostream>
#include <cctype>
#include <cstring>
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
	cout << "FRS - CLI interface for the Flight Reservation System" << endl;
	cout << "Commands:" << endl;
	cout << "\tr\tReservation <passenger name> <flight code> <seat class>" << endl;
	cout << "\tc\tCancellation <passenger name> <flight code>" << endl;
	cout << "\tp\tPassenger enquiry <passenger name>" << endl;
	cout << "\tf\tFlight enquiry <flight code>" << endl;
	cout << "\th\tHelp text" << endl;
	cout << "\te\tExit" << endl;
}

//CLI prompt methods
void CLIView::reservationPrompt(string _reservation)
{

	string buffer; // Have a buffer string
	stringstream ss(_reservation); // Insert the string into a stream
	vector<string> tokens; // Create vector to hold the tokens
	while (ss >> buffer)
	{
		tokens.push_back(buffer);
	}

	string name = tokens[1] + " " +tokens[2];
	while (string::npos == name.find(' ',1)) {
		cout << "Please enter a passenger forename and surname: ";
		getline(cin, name);
	}

	string code = tokens[3];
	while (NULL == m_controller->getModel()->getFlightByCode(code)) {
		cout << "Please enter a valid flight code: ";
		getline(cin, code);
	}

	string seatClass = tokens[4];
	while ('f' != tolower(seatClass[0]) && '1' != seatClass[0] && 'e' != tolower(seatClass[0]) && '2' != seatClass[0]) {
		cout << "Please enter a seat class: ";
		getline(cin, seatClass);
	}
    
    if (yesNoDialog("reservation: " + name + ", " + code + ", " + seatClass + "\nAre these details correct? (Y/n) ")) {
        this->makeReservationEvent(name, code, seatClass);
    }

}

void CLIView::cancellationPrompt(string _cancellation)
{
	string buffer; // Have a buffer string
	stringstream ss(_cancellation); // Insert the string into a stream
	vector<string> tokens; // Create vector to hold the tokens
	while (ss >> buffer)
	{
		tokens.push_back(buffer);
	}
    
	string name = tokens[1] + " " +tokens[2];
	while (NULL == m_controller->getModel()->getPassengerByName(name)) {
		cout << "Please enter an existing passenger's forename and surname: ";
		getline(cin, name);
	}
    
	string code = tokens[3];
	while (NULL == m_controller->getModel()->getFlightByCode(code)) {
		cout << "Please enter a valid flight code: ";
		getline(cin, code);
	}
    
    if (yesNoDialog("cancellation: " + name + ", " + code + "\nAre these details correct? (Y/n) ")) {
        this->makeCancellationEvent(name, code);
    }

}

void CLIView::passengerInqPrompt(string _passengerInq)
{
	
	string buffer; // Have a buffer string
	stringstream ss(_passengerInq); // Insert the string into a stream
	vector<string> tokens; // Create vector to hold the tokens
	while (ss >> buffer)
	{
		tokens.push_back(buffer);
	}
    
	string name = tokens[1] + " " +tokens[2];
	while (string::npos == name.find(' ',1)) {
		cout << "Please enter a passenger forename and surname: ";
		getline(cin, name);
	}
    
    this->makePassengerInquiryEvent(name);
}

void CLIView::flightInqPrompt(string _flightInq)
{
	string buffer; // Have a buffer string
	stringstream ss(_flightInq); // Insert the string into a stream
	vector<string> tokens; // Create vector to hold the tokens
	while (ss >> buffer)
	{
		tokens.push_back(buffer);
	}
    
	string code = tokens[1];
	while (NULL == m_controller->getModel()->getFlightByCode(code)) {
		cout << "Please enter a valid flight code: ";
		getline(cin, code);
	}

    this->makeFlightInquiryEvent(code);
}

//Starting point
void CLIView::start() {
	bool quit = false;
	while(!quit) {
		string option;
		cout << "FRS>: ";
		getline(cin, option);
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
			default:
				cout << "Unrecognised command: " << option << endl;
			case '?':
			case 'h':
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
		cout << "Flight " << _flight->getCode() << " at " << _flight->getTime() << "hours on ";
		cout << _flight->getDate().insert(4,"/").insert(2,"/") << endl;
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
	displayFlight(m_controller->getModel()->getFlightByCode(_code));
	cout << "Passengers:" << endl;
	//TODO: Make this into one function that iterates through classes and statuses
	displayPassengers(m_controller->makeFlightInquiry(_code, Flight::First, Flight::Booked));
	displayPassengers(m_controller->makeFlightInquiry(_code, Flight::First, Flight::Waiting));
	displayPassengers(m_controller->makeFlightInquiry(_code, Flight::Economy, Flight::Booked));
	displayPassengers(m_controller->makeFlightInquiry(_code, Flight::Economy, Flight::Waiting));
}


//Auxiliary methods
bool CLIView::yesNoDialog(string _message) {
	string option;
	cout << _message;
	getline(cin, option);

	return checkAnswer(option[0]);
}


void CLIView::dialogMessage(string _message) {
	cout << _message << endl;
}

void CLIView::setController(Controller* _controller) {
	 m_controller = _controller;
}

Controller* CLIView::getController() {
	return m_controller;
}

void CLIView::refresh() {}
