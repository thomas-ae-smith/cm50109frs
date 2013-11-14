//Passenger header file
#include <string>
#include <vector>
#include "Flight.h"


class Passenger{

private:
//Data
string m_name;
vector<Flight*> m_flights;

public:
//Methods
Passenger (string _name);
~Passenger();
void setName(string _name);
string getName();
void addFlight (Flight* _flight);
void removeFlight(Flight* _flight);
vector<Flight*> getFlights();
};
