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

        //TODO: Deallocates the memory for the model instance when the program terminates
        static void cleanUp();

        //Returns a passenger by name
        Passenger* getPassengerByName(string _passenger);

        //Returns a flight by its code
		Flight* getFlightByCode(string _code);

        //Get a pointer to a vector of flights on the same date
        vector<Flight*>* getFlightsByDate(string _date);

        //Adds a new reservation to the data base
        void addReservation(string _name, string _code, Flight::SeatClass _class);

        //Removes a flight from the passeger and vice versa
        void addCancellation(string _name, string _code);

        //Adds a flight to the database
        void addFlight(Flight* _flight);

        //Given a string, returns the class it corresponds to
        Flight::SeatClass getClass(string _class);

        //Makes a passenger inquiry and returns the flights a passenger is currently on
        vector<Flight*>* makePassengerInquiry(string _name);

        //Make a flight inquiry and return a pointer to a pair of iterators, delimiting a list of booked/waiting passengers
        pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>*  makeFlightInquiry(string _code, Flight::SeatClass _class, Flight::SeatStatus _status);

        //Get a pointer to all the passengers
        map<string, Passenger*>* getPassengers();

        //Get a pointer to all the flights
        map<string, Flight*>* getFlights();

		//Check if the date given is valid
		bool checkDate(string _date);



	private:
		//Map of all passengers, sorted by name
		map<string,Passenger*> m_passengers;

		//Map of all flights, sorted by code
		map<string,Flight*> m_flightByCode;

		//Multimap of all flights, sorted by date
		multimap<string,Flight*> m_flightByDate;

        //Add a new passeger to the passenger map
		Passenger* addPassenger(string _name);

        //Private constructor and destructor for the singleton pattern
		Model();
        ~Model();

        //Static data: instance pointer and filename
		static Model* s_model;
		static const string s_filename;
};

#endif // MODEL_H
