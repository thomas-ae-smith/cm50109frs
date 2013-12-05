#include "Flight.h"
#include "Passenger.h"
#include "Model.h"
#include <iostream>

//Testing the flight class and its methods

int main()
{
    
    //Construct a flight
    Flight* flight1 = new Flight("Code1", "0900", "25102012", 250);
    Flight* flight2 = new Flight("Code2", "1000","25112013",260);
    Flight* flight3 = new Flight("Code3","1100","25112013",270);
    Flight* flight4 = new Flight("Code4","1200","25112013",280);
    
    
    //Construct a passenger
    Model* my_model = Model::getModel();
    my_model->addFlight(flight1);
    my_model->addFlight(flight2);
    my_model->addFlight(flight3);
    my_model->addFlight(flight4);
    
    my_model->addPassenger("Emily");
    my_model->addPassenger("LILY");
    my_model->addPassenger("TOM");
    my_model->addPassenger("Anamaria");
    
    
    
    //Returns a passenger by name
    Passenger* passenger1 = my_model->getPassengerByName("Emily");
    cout<< passenger1->getName()<<endl;
    Passenger* passenger2 =my_model->getPassengerByName("Julian");
    if (passenger2!=nullptr) {
        cout<<"This is a bad pointer to somewhere.\n"<<endl;
    }
    else
        cout<<"This is NUll!!!\n"<<endl;
    
    //Returns a flight by its code
    Flight* cflight=my_model->getFlightByCode("Code1");
    cout<<cflight->getDate()<<"  "<<cflight->getCode()<<endl;
    
    //Get a pointer to a vector of flights on the same date
    vector<Flight*>* t_dateflight =my_model->getFlightsByDate("25122013");
    if (t_dateflight!=nullptr) {
        cout<<"Going into the loop."<<endl;
        for(vector<Flight*>::iterator it=(*t_dateflight).begin();it!=(*t_dateflight).end();++it)
            cout<< (*it)->getCode()<<endl;
    }
    
    
    //Adds a new reservation to the data base
    void addReservation(string _name, string _code, Flight::SeatClass _class);
    my_model->addReservation("Alice", "Code1", First);
    
    
    //Adds a flight to the database
    
    //Given a string, returns the class it corresponds to
    Flight::SeatClass getClass(string _class);
    
    //Makes a passenger inquiry and returns the flights a passenger is currently on
    vector<Flight*>* t_passengerinquiry=my_model->makePassengerInquiry("Emily");
    
    //Make a flight inquiry and return a pointer to a pair of iterators, delimiting a list of booked/waiting passengers
    pair<vector<Passenger*>::iterator, vector<Passenger*>::iterator>*  t_fligthinquiry=my_model->makeFlightInquiry("Code1",First, booked);
    
	//private://
    //Map of all passengers, sorted by name
    map<string,Passenger*> m_passengers;
    
    //Map of all flights, sorted by code
    map<string,Flight*> m_flightByCode;
    
    //Multimap of all flights, sorted by date
    multimap<string,Flight*> m_flightByDate;
    
    
    //Private constructor and destructor for the singleton pattern
    Model();
}
