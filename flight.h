/* Flight.h
 */

#include <string>

class Flight
{
	public:
		Flight(string _number, string _time, string _date, int _seatTotal);
		~Flight()
		void addPassenger(Passenger* _passenger, SeatClass _class);
		void removePassnger(Passenger* _passenger);
		bool passengerOnFlight(Passenger* _passenger);
		int getSeatAvailability(SeatClass _class);
		vector<Passenger*> getPassengers(SeatClass _class);
		vector<Passenger*> getWaiting(SeatClass _class);
		
	private:
		string m_number;
		string m_date;
		string m_time;
		int[] m_seatnumbers;
		vector<passenger*>[] m_seatlist;

}