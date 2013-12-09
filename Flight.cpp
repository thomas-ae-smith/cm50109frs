#include "Flight.h"
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


// create a flight with input parameters
Flight::Flight(string _code, string _time, string _date, int _seatTotal) {
	this->m_code = _code;
	this->m_time = _time;
	this->m_date = _date;
	this->m_seatnumbers[First] = (int)floor(0.1 * _seatTotal);
	this->m_seatnumbers[Economy] = _seatTotal - (int)floor(0.1 * _seatTotal);
	this->m_seatlist[First] = new vector<Passenger*>();
	this->m_seatlist[Economy] = new vector<Passenger*>();
}

// free the memory allocated for the new vectors
Flight::~Flight() {
	delete this->m_seatlist[First];
	delete this->m_seatlist[Economy];
}

// put a passenger into the queue for the appropriate flight
void Flight::addPassenger(Passenger* _passenger, SeatClass _class) {
	m_seatlist[_class]->push_back(_passenger);
}

// remove a passenger if they exist in the waiting lists
void Flight::removePassenger(Passenger* _passenger)
{
	vector<Passenger*> *first = m_seatlist[First];
	vector<Passenger*> *economy = m_seatlist[Economy];
	vector<Passenger*>::iterator index;

    if(first!=NULL)
    {
        if((index = find(first->begin(), first->end(), _passenger)) != first->end() )
        {
            first->erase(index);
            return;
        }
    }

    if(economy!=NULL)
    {
        if ((index = find(economy->begin(), economy->end(), _passenger)) != economy->end() )
        {
            economy->erase(index);
            return;
        }
    }
}

// find if a passenger exists on the passenger lists
bool Flight::passengerOnFlight(Passenger* _passenger) {
	vector<Passenger*> *first = m_seatlist[First];
	vector<Passenger*> *economy = m_seatlist[Economy];

	return (find(first->begin(), first->end(), _passenger) != first->end())
		|| (find(economy->begin(), economy->end(), _passenger) != economy->end());
}

int Flight::getSeatAvailability(SeatClass _class) {
	return m_seatnumbers[_class] - (int)m_seatlist[_class]->size();
}

pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>*  Flight::getPassengers(SeatClass _class, SeatStatus _status) {
    //TODO: Deallocation
    return (_status == Booked) ?
    new pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>(m_seatlist[_class]->begin(), m_seatlist[_class]->begin() + m_seatnumbers[_class])
    :
    new pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>(m_seatlist[_class]->begin() + m_seatnumbers[_class], m_seatlist[_class]->end());
}




