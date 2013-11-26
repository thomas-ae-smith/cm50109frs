#include "Model.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const string Model::s_filename = "FCGDATA";
Model* Model::s_model = NULL;

//Use model to store the data of passengers and flights
//Using Singlteton pattern here to keep only one instance of Model
Model* Model::getModel() {
    if(s_model == NULL){
        s_model = new Model();
    }
    return s_model;
}


Model::Model(){
    string line;
    int seats;
    string flightCode, flightTime, flightDate;
    char auxCode[16], auxTime[16], auxDate[16];

    //ifstream constructor opens file
    ifstream inFlightFile;

    inFlightFile.open(s_filename.c_str(), ios::in);

    if (!inFlightFile.is_open()) {
        cerr << "Failed to open file, please check" << endl;
        exit(1);
    } //end if
    else
    {
        while(getline(inFlightFile, line))
        {
           //The sscanf needs char* instead of strings
            if (sscanf(line.c_str(), "%s %d %s %s", auxCode, &seats, auxTime, auxDate) !=4)
            {
              cerr << "Found problem on line: \'" << line << "\', skipping." << endl;
              continue;
            }

            //Copying the char* info into string to then pass on to the Flight contructor
            flightCode = auxCode;
            flightTime = auxTime;
            flightDate = auxDate;

            Flight* flightPTR = new Flight(flightCode, flightTime, flightDate, seats);
            m_flightByCode.insert(pair<string,Flight*>(flightCode, flightPTR));
            m_flightByDate.insert(pair<string,Flight*>(flightDate, flightPTR));
        }

        inFlightFile.close();
   }
    
}

Model::~Model()
{
    //Nothing here, deallocation will happen in cleanup
}

void Model::cleanUp()
{
    delete s_model;
    s_model = NULL;
}

//Get flight from the map using fight code as the key
Flight* Model::getFlightByCode(string _code){
    return m_flightByCode[_code];
}

//Get passenger from the map using passenger name as the key
Passenger* Model::getPassengerByName(string _passenger){
    //TODO create passenger if not extant
    return m_passengers[_passenger];
}

//Creates a new passenger from the given name, and adds it to the map
Passenger* Model::addPassenger(string _name) {
    Passenger* added = new Passenger(_name);
    m_passengers.insert(pair<string,Passenger*>(_name, added));
    return added;
}

//Adds a new reservation to the data base
void Model::addReservation(string _name, string _code, Flight::SeatClass _class) {
    Flight* flight = getFlightByCode(_code);
    Passenger* passenger = getPassengerByName(_name);
    if (passenger == NULL) {
        passenger = addPassenger(_name);
    }
    flight->addPassenger(passenger, _class);
    passenger->addFlight(flight);
}

 //Given a string, returns the class it corresponds to - TODO: CHECK for invalid strings
 Flight::SeatClass Model::getClass(string _class)
 {
     if (_class=="First")
     {
         return Flight::First;
     }
     return Flight::Economy;
 }

 //Get a pointer to the vector of flights a passenger is currently on
vector<Flight*>* Model::makePassengerInquiry(string _name)
{
    //Get the passenger
    Passenger *auxPassenger = getPassengerByName(_name);

    if(auxPassenger)
    {
        return auxPassenger->getFlights();
    }
    else
    {
        cerr << "Model::makePassengerEnquiry: The passenger requested does not exist." << endl;
        return NULL;
    }
}


//Get a pointer to the vector of booked/waiting passengers for a certain flight and class
pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>*  Model::makeFlightInquiry(string _code, Flight::SeatClass _class, Flight::SeatStatus _status)
{
//Gets the passengers on a flight, either booked or waiting
  Flight *auxFlight = getFlightByCode(_code);

  if(auxFlight)
  {
      return auxFlight->getPassengers(_class, _status);
  }
  else
  {
      cerr << "Model::makeFlightEnquiry: The flight requested does not exist." << endl;
      return NULL;
  }
}

 //PROBLEM - CHECK!

//Get all the flights on the given date
vector<Flight*>*  Model::getFlightsByDate(string _date)
{
//Pair structure of iterators, which will represent the first and the last occurences of the date
    pair<multimap<string,Flight*>::iterator,multimap<string,Flight*>::iterator> dateRange;

//Returns the pair of iterators representing the range of all flights on the date
    dateRange=m_flightByDate.equal_range(_date);

//Constructs a vector from the range, of all the flights found on that date    
//TODO: Where to deallocate vector
    return new vector<Flight*>(dateRange.first, dateRange.second);

}

