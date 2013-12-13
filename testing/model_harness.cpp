#include "Flight.h"
#include "Passenger.h"
#include "Model.h"
#include <iostream>
using namespace std;

//Testing the model class and its methods

int main()
{
        //Constrctor
        Model();
        //Map of all passengers, sorted by name
        map<string,Passenger*> m_passengers;
        
        //Map of all flights, sorted by code
        map<string,Flight*> m_flightByCode;
        
        //Multimap of all flights, sorted by date
        multimap<string,Flight*> m_flightByDate;
        
        //construct a flight
        Flight* flight1 = new Flight("Code1", "0900", "25102012", 10);
        Flight* flight2 = new Flight("Code2", "1000","25112013",10);
        Flight* flight3 = new Flight("Code3","1100","25112013",10);
        Flight* flight4 = new Flight("Code4","1200","25112013",10);
        
        Model* my_model = Model::getModel();
        
        //Adds a flight to the database
        //test adding flight to map
        cout<< "Adding flights to flight map"<< endl;
        my_model->addFlight(flight1);
        my_model->addFlight(flight2);
        my_model->addFlight(flight3);
        my_model->addFlight(flight4);
        
        //Add a new passeger to the passenger map
        //test adding passenger to map
        
        my_model->addReservation("Tom","Code1",Flight::First);
        my_model->addReservation("Tom","Code2",Flight::First);
        my_model->addReservation("John","Code1",Flight::First);
        my_model->addReservation("Raj","Code1", Flight::Economy);
        
        //Returns a flight by its code
        cout<< "testing getFlightByCode.Code1 0900 25102012 10seats"<<endl;
        Flight* t_flightByCode=my_model->getFlightByCode("Code1");
        cout<<"The returned flight is"<<endl;
        cout<<t_flightByCode->getCode()<<"  "<<t_flightByCode->getDate()<<endl;
        cout<<t_flightByCode->getSeatAvailability(Flight::First)<<endl;
        
        //Get a pointer to a vector of flights on the same date
        cout<< "testing getFlightByDate,there are 3 flights on the date 25112013,"<<endl;
        vector<Flight*>* t_flightByDate = my_model->getFlightsByDate("25112013");
        if(t_flightByDate!= nullptr）){
            cout<<"Return valueis not nullptr.Going into the loop now.\n"<<endl;
            for(vector<Flight*>::iterator it1 = (*t_flightByDate).begin(); it1 != (*t_flightByDate).end(); ++it1) {
                cout<< "Code: "<<(*it1)->getCode()<<" "<<"Date "<<(*it1)->getDate()<<endl;
            }
        }
        
        //Returns a passenger by name
        cout<<"Testing getPassengerByName"<<endl;
        Passenger* t_passengerByName = my_model->getPassengerByName("Tom");
        cout<< t_passengerByName->getName()<<endl;
        
        
        //Adds a new reservation to the data base
        cout<<"addReservation can ba tested By flightinquiry and passenger inquiry"<<endl;
        
        //Removes a flight from the passeger and vice versa
        cout<<"addCancellation can be tested by testing flightinquiry and passengerinquiry"<<endl;
        
        //Makes a passenger inquiry and returns the flights a passenger is currently on
        cout<< "Testing makePassengerInquiry"<<endl;
        vector<Flight*>* t_pInquiry=my_model->makePassengerInquiry("Tom");
        
        for (vector<Flight*>::iterator it2= (*t_pInquiry).begin();it2!=(*t_pInquiry).end();++it2){
            cout<<"Flights Tom's on "<<(*it2)->getCode()<<endl;
        }
            //Make a flight inquiry and return a pointer to a pair of iterators, delimiting a list of booked/waiting passengers
            
            cout<<"Testing makeFlightInquiry"<<endl;
            pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>* t_fInquiry=my_model->makeFlightInquiry("Code1", Flight::Economy, Flight::Booked);
            cout<<"Passengers on flighe Code1.."<<endl;
            multimap<string, Flight*>::iterator it3= (*t_fInquiry).first;
            vector<Flight*>* flights = new vector<Flight*>();
    
            while (it3 != (*t_fInquiry).second) {
                cout<< it3->second->getName()<< endl;
                ++it3;
              }

            
}
