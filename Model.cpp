#include "Model.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//Use model to store the data of passengers and flights
//Using Singlteton pattern here to keep only one instance of Model
Model::Model getModel(){
    if(s_model == nullptr){
        s_model = Model();
    }
    return s_model;
}

Model::Model(){
    string line;
    int seats;
    string flightCode, flightTime, flightDate;
    //ofstream constructor opens file
    ifstream inFlightFile;
    inFlightFile.open(s_filename, ios::in);
    if (!inFlightFile) {
        cerr << "Failed to open file, please check" << endl;
        exit(1);
    }//end if
    else {
        while(getline(inFlightFile, line))
        {
            if (fscanf(line, "%s %d %s %s", &flightCode, &seatNumber, &flightTime, &flightDate) !=4){
                cerr << "Found problem on line: \'" << line << "\', skipping." << endl;
                continue;
            }
            Flight* flightPTR = new Flight(flightCode, flightTime, flightDate, seats);
            m_flightByCode.insert(flightCode, flightPTR);
            m_flightByDate.insert(flightDate, flightPTR);
        }
        inFlightFile.close();
    }
    
}

//Get flight from the map using fight code as the key
Flight* Model::getFlightByCode(string _code){
    return m_flightByCode[_code];
}

//Get passenger from the map using passenger name as the key
Passenger* Model::getPassengerByName(string _passenger){
    //TODO create passenger if not extant
    return m_passenger[_passenger];
}

//Creates a new passenger from the given name, and adds it to the map
Passenger* Model::addPassenger(string _name) {
    return m_passenger.insert(_name, new Passenger(_name));
}

void Model::addReservation(string _name, string _code, Flight::SeatClass _class) {
    Flight* flight = getFlightByCode(_code);
    Passenger* passenger = getPassengerByName(_name);
    if (passenger == nullptr) {
        passenger = addPassenger(_name);
    }
    flight->addPassenger(passenger, _class);
    passenger->addFlight(flight);
}

//Get all the flights on the given date
vector<Flight*> Model::getFlightByDate(string _date){
    //Pair structure of iterators, which will represent the first and the last occurences of the date
    pair<multimap<string,Flight*>::iterator,multimap<string,Flight*>::iterator> dateRange;

//Returns the pair of iterators representing the range of all flights on the date
    dateRange=m_flightByDate.equal_range(_date);

//Constructs a vector from the range, of all the flights found on that date    
    return vector<Flight*>(dateRange.first, dateRange.second);
}
