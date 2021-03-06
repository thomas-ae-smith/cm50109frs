#include "Passenger.h"
#include <algorithm>

using namespace std;

//Construct a new passenger instance
Passenger::Passenger(string _name) {
    m_name = _name;
    m_flights = new vector<Flight*>();
}

Passenger::~Passenger()
{
    delete m_flights;
}

//Retrieve a passenger name
string Passenger::getName() {
    return m_name;
}

//Add a flight to the passenger's list of flights
void Passenger::addFlight(Flight *_flight) {
    m_flights->push_back(_flight);
}


//Remove a flight from the passenger's list of flights
void Passenger::removeFlight(Flight* _flight) {
     vector <Flight*>::iterator someIterator;
     someIterator = find(m_flights->begin(), m_flights->end(), _flight);   //if not found, returns last element.
     m_flights->erase(someIterator);
}

//Return all of the flights TODO: get waiting (and class?) status
vector<Flight*>* Passenger::getFlights() {
    return m_flights;
}

