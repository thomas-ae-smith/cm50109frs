/* Flight.cpp
 */

#include <string>
#include <Flight.h>

using namespace std;

Flight::Flight(string _number, string _time, string _date, int _seatTotal) {
	this.m_number = _number;
	this.m_time = _time;
	this.m_date = _date;
	this.m_seatnumbers[SeatClass.First] = 0.1 * _seatTotal;
	this.m_seatnumbers[SeatClass.Economy] = 0.9 * _seatTotal;
	this.m_seatlist[SeatClass.First] = new vector<passenger*>();
	this.m_seatlist[SeatClass.Economy] = new vector<passenger*>();
}

Flight::~Flight() {
	this.m_seatlist[SeatClass.First] = new vector<passenger*>();
	this.m_seatlist[SeatClass.Economy] = new vector<passenger*>();
}

void Flight::addPassenger(Passenger* _passenger, SeatClass _class) {
	m_seatlist[_class].push_back(_passenger);
}

void Flight::removePassenger(Passenger* _passenger) {
	int index = -1;

	if ((index = find(first->begin(), first->end(), _passenger)) >0 )
	{
		/* code */
	}
}

bool Flight::passengerOnFlight(Passenger* _passenger) {
	vector<Passenger*> *first = &m_seatlist[SeatClass.First];
	vector<Passenger*> *economy = &m_seatlist[SeatClass.Economy];

	return find(first->begin(), first->end(), _passenger) 
		|| find(economy->begin(), economy->end(), _passenger);
}

int Flight::getSeatAvailability(SeatClass _class) {
	return m_seatnumbers[_class] - m_seatlist[_class].size();
}

vector<Passenger*> Flight::getPassengers(SeatClass _class) {
	return vector<Passenger*> seatedPassengers(m_seatlist[_class].begin(), m_seatlist[_class].begin() + m_seatnumbers[_class]);
}

vector<Passenger*> Flight::getWaiting(SeatClass _class) {
	return vector<Passenger*> seatedPassengers(m_seatlist[_class].begin() + m_seatnumbers[_class], m_seatlist[_class].end());
}


// string m_number;
// string m_date;
// string m_time;
// int[] m_seatnumbers;
// vector<passenger*>[] m_seatlist;
