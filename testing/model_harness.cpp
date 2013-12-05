#include "Flight.h"
#include "Passenger.h"
#include "Model.h"
#include <iostream>

//Testing the flight class and its methods

int main()
{
    Model();
    map<string,Passenger*> m_passengers;
    map<string,Flight*> m_flightByCode;
    multimap<string,Flight*> m_flightByDate;
    
    
    //Construct a flight
    Flight* flight1 = new Flight("Code1", "0900", "25102012", 10);
    Flight* flight2 = new Flight("Code2", "1000","25112013",10);
    Flight* flight3 = new Flight("Code3","1100","25112013",10);
    Flight* flight4 = new Flight("Code4","1200","25112013",10);
    
    
    //Construct a passenger
    Model* my_model = Model::getModel();
    my_model->addFlight(flight1);
    my_model->addFlight(flight2);
    my_model->addFlight(flight3);
    my_model->addFlight(flight4);
    
    for(map<string,Flight*>::iterator it=m_flightByCode.begin();it!=m_flightByCode.end();++it){
        cout<< "checking the flight by code database."<<endl;
        cout<< it->first << (it->second)->getDate() << (it->second)->getCode() <<endl;
        cout<< "Succeed!. "<< endl;
    }
    
    
    //Get a pointer to a vector of flights on the same date
    vector<Flight*>* t_dateflight =my_model->getFlightsByDate("25122013");
    if (t_dateflight!=nullptr) {
        cout<<"Going into the loop."<<endl;
        for(vector<Flight*>::iterator it=(*t_dateflight).begin();it!=(*t_dateflight).end();++it)
            cout<< (*it)->getCode()<<endl;
    }
    
    
    my_model->addPassenger("Emily");
    my_model->addPassenger("LILY");
    my_model->addPassenger("TOM");
    my_model->addPassenger("Anamaria");
    
    
    
    //Adds a new reservation to the data base
    // void addReservation(string _name, string _code, Flight::SeatClass _class);
    my_model->addReservation("Emily", "Code1", Flight::First);
    my_model->addReservation("Tom", "Code1", Flight::First);
    
    //Returns a flight by its code
    Flight* cflight=my_model->getFlightByCode("Code1");
    cout<<cflight->getDate()<<"  "<<cflight->getCode()<<endl;
    cout<<cflight->getSeatAvailability(Flight::First)<<endl;
    cout<<cflight->Booked<<endl;
    //Returns a passenger by name
    Passenger* passenger1 = my_model->getPassengerByName("Emily");
    cout<< passenger1->getName()<<endl;
    Passenger* passenger2 =my_model->getPassengerByName("Julian");
    if (passenger2!=nullptr) {
        cout<<"This is a bad pointer to somewhere.\n"<<endl;
    }
    else
        cout<<"No passenger in this name!!!\n"<<endl;
    
    
    
    
    
    
    
    //Given a string, returns the class it corresponds to
    
    //Makes a passenger inquiry and returns the flights a passenger is currently on
    vector<Flight*>* t_passengerinquiry=my_model->makePassengerInquiry("Emily");
    for (vector<Flight*>::iterator it =(*t_passengerinquiry).begin(); it!=(*t_passengerinquiry).end(); ++it)
    {
        cout<< (*it)->getCode()<<endl;
    }
    
}
