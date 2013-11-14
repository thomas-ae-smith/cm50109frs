#include "passenger.h"

Passenger::Passenger(string _name)
{
    m_name = _name;
}

Passenger::~Passenger
{
}

void Passenger::setName(string _name)
{
    m_name = _name;
}

string Passenger::getName()
{
    return m_name;
}


void Passenger::addFlight(Flight *_flight)
{
    m_flights.push_back(_flight);
}


void Passenger::removeFlight(Flight* _flight)
{
     vector <Flight*>::iterator someIterator;
     someIterator = std::find(m_flights.begin(), m_flights.end(), _flight);   //if not found, returns last element.
     m_flights.erase(someIterator);
}


vector<Flight*> Passenger::getFlights()
{
    return m_flights;
}
