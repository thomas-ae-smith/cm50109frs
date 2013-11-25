#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <vector>
#include "Flight.h"


class Passenger
{
private:
//Data

//The name of the person.
	string m_name;
//The list of flights the person is on or waiting for a place on.
//can we change this so it has flight pointers and waiting/not? or change getFlights?
	vector<Flight*> m_flights;

public:
//Methods

//constructor
	Passenger (string _name);
//destructor
	~Passenger();
//sets passenger name
	void setName(string _name);
//returns passenger name
	string getName();
//adds a flight to the passenger's list of flights
	void addFlight (Flight* _flight);
//removes a flight from the passenger's list of flights
	void removeFlight(Flight* _flight);
//returns the passenger's list of flights
	vector<Flight*>* getFlights();

};

#endif // PASSENGER_H