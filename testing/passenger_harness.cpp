#include "../Flight.h"
#include "../Passenger.h"

//Testing the flight class and its methods

void main()
{

//Construct a flight 			
    Flight* flight1 = new Flight("Code1", "0900", "25102012", 250);

//Construct a passenger
	Passenger* passenger1 = new Passenger("Nick Johnson");

//Adds the passenger to the flight
    flight1->addPassenger(passenger1, Flight::First);


/*
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

//Destroy the flight		
	~Flight();
*/
}
