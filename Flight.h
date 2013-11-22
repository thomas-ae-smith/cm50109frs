#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>

class Flight {
//Stores data relating to an individual flight

	public:
//Constructor: code of the flight, time, date and total number of seats		
		Flight(string _code, string _time, string _date, int _seatTotal);

//Destructor		
		~Flight();

//Adds a passenger to the flight, on the desired class		
		void addPassenger(Passenger* _passenger, SeatClass _class);

//Removes a passenger from the flight		
		void removePassenger(Passenger* _passenger);

//Checks if a passenger is on the flight and returns a boolean (yes,no)		
		bool passengerOnFlight(Passenger* _passenger);

//Gets the numbers of seats left, with negative value if there are no more 		
//seats left, but there are people on the waiting list.
		int getSeatAvailability(SeatClass _class);

//Gets a list of passengers either waiting or booked on the flight
		vector<Passenger*> getPassengers(SeatClass _class, SeatStatus _status);

//Enum structure with the possible flight classes
		enum SeatClass { 
			First,
			Economy,
			TOTAL
		};

//Enum structure with the possible status of a passenger
		enum SeatStatus {
			Booked,
			Waiting,
			TOTAL
		};
		
	private:
		string m_code; //Code of flight
		string m_date; //Date of flight as DDMMYYYY
		string m_time; //Time of flight as HHMM (24)
		int[SeatClass.TOTAL] m_seatnumbers; //Array of seats available per class
		vector<Passenger*>[SeatClass.TOTAL] m_seatlist; //Array of vectors for passengers per class

};
#endif // FLIGHT_H