#include "Controller.h"
#include "Model.h"
#include "View.h"
#include <vector>
#include <string>
#include <iostream>

Controller::Controller(Model *_model, View *_view)
{
    m_model = _model;
    m_view = _view;
}

Controller::~Controller()
{
    //No space was allocated
}

string Controller::makeReservation(string _name, string _number, SeatClass _class)
{
    //Adds a person on a flight

    //Get the flight
    Flight *auxFlight = m_model->getFlightByCode(_number);
    //Get the passenge
    Passenger *auxPassenger = m_model->getPassengerByName(_name);


    //QUESTION: What class is resposible for checking up the flight availability? Flight?
    //Check for availability of flight and existence of passenger
    if ((auxFlight != NULL) && (auxPassenger != NULL))
    {
        //checks the flight options and puts the passenger on a waiting list if needed
         auxFlight->addPassenger(auxPassenger, _class);
    }
    else
    {
        //Think of a way of logging errors and exceptions
        cerr<<"makeReservation: The flight and/or passenger do not exist."<<endl;
    }
}


string Controller::makeCancellation(string _name, string _code)
{
    //Removes a person from the flight
    //Get the flight
    Flight *auxFlight = m_model->getFlightByCode(_code);
    //Get the passenge
    Passenger *auxPassenger = m_model->getPassengerByName(_name);


    if ((auxFlight != NULL) && (auxPassenger != NULL))
    {
        auxFlight->removePassenger(auxPassenger);
    }
    else
    {
        cerr<<"makeCancellation: The flight and/or passenger do not exist. "<<endl;
    }
}

vector<Flight*> Controller::makePassengerEnquiry(string _name)
{
  //Gets the flights the passenger is on

  //Get the passenger
  Passenger *auxPassenger = m_model->getPassengerByName(_name);

  if(auxPassenger)
  {
      return auxPassenger->getFlights();
  }
  else
  {
      cerr<<"makePassengerEnquiry: The passenger requested does not exist."<<endl;
      return NULL;
  }
}

vector<Passenger*> Controller::makeFlightEnquiry(string _code, SeatClass _class)
{
  //Gets the passengers on a flight

    Flight *auxFlight = m_model->getFlightByCode(_code);

    if(auxFlight)
    {
        return auxFlight->getPassengers(_class);
    }
    else
    {
        cerr<<"makeFlightEnquiry: The flight requested does not exist."<<endl;
        return NULL;
    }
}

vector<Passenger*> Controller::makeFlightWaitingEnquiry(string _code, SeatClass _class)
{
    //Gets the passengers on a flight

      Flight *auxFlight = m_model->getFlightByCode(_code);

      if(auxFlight)
      {
          return auxFlight->getWaiting(_class);
      }
      else
      {
          cerr<<"makeFlightWaitingEnquiry: The flight requested does not exist."<<endl;
          return NULL;
      }
}
