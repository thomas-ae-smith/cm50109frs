#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <vector>
#include "Flight.h"

using namespace std;

class Passenger
{
public:
//Constructor
	Passenger (string _name);
//Destructor
	~Passenger();

//Sets passenger name
	void setName(string _name);

//Returns passenger name
	string getName();

//Adds a flight to the passenger's list of flights
	void addFlight (Flight* _flight);

//Removes a flight from the passenger's list of flights
	void removeFlight(Flight* _flight);

//Returns the passenger's list of flights
	vector<Flight*>* getFlights();

private:
//The name of the person.
    string m_name;

//The list of flights the person is on or waiting for a place on.
//QUESTION: Can we change this so it has flight pointers and waiting/not? or change getFlights?
    vector<Flight*> m_flights;
};

#endif // PASSENGER_H
