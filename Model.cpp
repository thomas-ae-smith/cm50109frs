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
	bool checker = false;

    //ifstream constructor opens file
    ifstream inFlightFile;

    inFlightFile.open(s_filename.c_str(), ios::in);

    if (!inFlightFile.is_open()) {
        cerr << "Failed to open file, please check\n" << endl;
        exit(1);
    } //end if
    else
    {
        while(getline(inFlightFile, line))
        {
           //Obs! The sscanf needs char* instead of strings
			checker = sscanf(line.c_str(), "%s %d %s %s", auxCode, &seats, auxTime, auxDate) !=4 ? true : false;

            if (checker && !checkDate(auxDate))
            {
              cerr << "Found problem on line: \'" << line << "\', skipping." << endl;
              continue;
            }

            //Copying the char* info into string to then pass on to the Flight contructor
            flightCode = auxCode;
            flightTime = auxTime;
            flightDate = auxDate;

            Flight* flightPTR = new Flight(flightCode, flightTime, flightDate, seats);
            addFlight(flightPTR);
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

//Check if the date is a valid one 
bool Model::checkDate (string date)
{
  int daysPerMonth[12] = {31, 29, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
  int dayNum, monthNum;

  string day = date.substr (0,2);
  string month = date.substr (2,2);

  istringstream ( day ) >> dayNum;
  istringstream ( month ) >> monthNum;

  if ( monthNum > 12 || monthNum < 1){
     cerr<<"Invalid date";
     return false;
  }
  else {
     if (daysPerMonth[monthNum - 1] >= dayNum && dayNum > 0){
      return true;
     }
     else{
      cerr << "Invalid date.";
      return false;
     }
  }
}

//Get flight from the map using fight code as the key
Flight* Model::getFlightByCode(string _code){
    return m_flightByCode[_code];
}

//Adds a flight to the database
void Model::addFlight(Flight* _flight)
{
    m_flightByCode.insert(pair<string,Flight*>(_flight->getCode(), _flight));
    m_flightByDate.insert(pair<string,Flight*>(_flight->getDate(), _flight));
}

//Get passenger from the map using passenger name as the key
Passenger* Model::getPassengerByName(string _passenger){
    return m_passengers[_passenger];
}


//Creates a new passenger from the given name, and adds it to the map
Passenger* Model::addPassenger(string _name) {
    return m_passengers[_name] = new Passenger(_name);
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

//Removes a flight from the passeger and vice versa
void Model::addCancellation(string _name, string _code)
{
    //Get the flight
    Flight *auxFlight = getFlightByCode(_code);
    //Get the passenge
    Passenger *auxPassenger = getPassengerByName(_name);

    //Remove passenger from flight
    auxFlight->removePassenger(auxPassenger);

    //Remove flight from passenger
    auxPassenger->removeFlight(auxFlight);
}

 //Given a string, returns the class it corresponds to - TODO: CHECK for invalid strings
 Flight::SeatClass Model::getClass(string _class)
 {
     if ('f' == tolower(_class[0]) || '1' == tolower(_class[0])) {
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


//Get all the flights on the given date
vector<Flight*>*  Model::getFlightsByDate(string _date)
{
//Pair structure of iterators, which will represent the first and the last occurences of the date
    pair<multimap<string,Flight*>::iterator,multimap<string,Flight*>::iterator> dateRange;

//Returns the pair of iterators representing the range of all flights on the date
    dateRange=m_flightByDate.equal_range(_date);
    
//Constructs a vector from the range, of all the flights found on that date
//TODO: Where to deallocate vector
    multimap<string, Flight*>::iterator it = dateRange.first;
    vector<Flight*>* flights = new vector<Flight*>();
    
    while (it != dateRange.second) {
        flights->push_back(it->second);
        ++it;
    }
    return flights;

}

//TODO: Should we have pointers to maps instead?

//Get a pointer to all the passengers
map<string, Passenger*>* Model::getPassengers()
{
    return &(this->m_passengers);
}

//Get a pointer to all the flights
map<string, Flight *>* Model::getFlights()
{
    return &(this->m_flightByCode);
}



