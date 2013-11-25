#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <map>
#include <vector>
#include "Passenger.h"
#include "Flight.h"

using namespace std;


//this is the class for storing data of passenger and flight using map and multimap
class Model {

	public:
		//Static factory for the singleton pattern
		static Model* getModel();
		Passenger* getPassengerByName(string _passenger);
		Flight* getFlightByCode(string _code);
		vector<Flight*> getFlightsByDate(string _date);
    void addReservation(string _name, string _code, Flight::SeatClass _class);

	private:
		//Map of all passengers, sorted by name
		map<string,Passenger*> m_passengers;
		//Map of all flights, sorted by code
		map<string,Flight*> m_flightByCode;
		//Multimap of all flights, sorted by date
		multimap<string,Flight*> m_flightByDate;

		Passenger* addPassenger(string _name);

		//Private constructor for the singleton pattern
		Model();
		//Static data: instance pointer and filename
		static Model* s_model;
		static const string s_filename;

};

#endif // MODEL_H