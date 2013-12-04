#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
#include <vector>

class Passenger;

using namespace std;

#include "Passenger.h"
using namespace std;
class Flight {
//Stores data relating to an individual flight

public:
    
//Enum structure with the possible flight classes
        enum SeatClass {
            First,
            Economy,
            TOTAL_CLASSES
        };
    
//Enum structure with the possible status of a passenger
    enum SeatStatus {
        Booked,
        Waiting,
        TOTAL_STATES
    };
    
//Constructor: code of the flight, time, date and total number of seats		
    Flight(string _code, string _time, string _date, int _seatTotal);

//Destructor		
	~Flight();

//Adds a passenger to the flight, on the desired class		
	void addPassenger(Passenger* _passenger, enum SeatClass _class);

//Removes a passenger from the flight		
	void removePassenger(Passenger* _passenger);

//Checks if a passenger is on the flight and returns a boolean (yes,no)		
	bool passengerOnFlight(Passenger* _passenger);

//Gets the numbers of seats left, with negative value if there are no more 		
//seats left, but there are people on the waiting list.
	int getSeatAvailability(enum SeatClass _class);

//Gets a list of passengers either waiting or booked on the flight
	pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>* getPassengers(enum SeatClass _class, SeatStatus _status);
    
//Get the code of the flight
    string getCode() { return m_code; }

//Get date of flight
    string getDate() { return m_date; }

		
	private:
		string m_code; //Code of flight
		string m_date; //Date of flight as DDMMYYYY
		string m_time; //Time of flight as HHMM (24)
    int m_seatnumbers[2]; //Array of seats available per class
    vector<Passenger*>* m_seatlist[2]; //Array of vectors for passengers per class

};
#endif // FLIGHT_H
