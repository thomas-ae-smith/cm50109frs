#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "Flight.h"
#include <vector>
#include <string>
#include <iostream>

Controller::Controller(Model *_model, AbstractView *_view)
{
    m_model = _model;
    m_view = _view;
}

Controller::~Controller()
{
    //No space was allocated
}



void Controller::makeReservation(string _name, string _code, SeatClass _class)
{
    //Adds a person on a flight

    //Get the flight
    Flight *auxFlight = m_model->getFlightByCode(_code);
    //Get the passenge
    Passenger *auxPassenger = m_model->getPassengerByName(_name);


    //Check for availability of flight and existence of passenger
    if ((auxFlight != NULL) && (auxPassenger != NULL))
    {

	//CHECK! - if person is trying to book a flight on the same day as another flight he is booked on!!!

        //checks the flight options and puts the passenger on a waiting list if needed
        int check = auxFlight->getSeatAvailability(_class);
        char option;

        if(check>0)
        {
            //There are seats left, we add the passenger
            auxFlight->addPassenger(auxPassenger, _class);
	    m_view->dialogMessage("Success, you were added on the flight!");
        }
        else
        {
            //There aren't any seats left in that class
            if(_class == Flight.SeatClass.First)
            {
                //If the class is first, we offer the economy option
                m_view->dialogMessage("There are no more seats left in the first class.");
	
                check = auxFlight->getSeatAvailability(Flight.SeatClass.Economy);
                if(check>0)
                {

                    if(m_view->yesNoDialog("Would you like a seat in the economy class? y/n"))
                    {
                        auxFlight->addPassenger(auxPassenger, Flight.SeatClass.Economy);
                    }
                    else
                    {
                        if(m_view->yesNoDialog("Would you like to be added on the First class waiting list? y/n"))
                        {
                            auxFlight->addPassenger(auxPassenger, Flight.SeatClass.First);
                        }
                        else
                        {
                           m_view->dialogMessage("You were not added to the " + auxFlight->getCode() + ", thank you!");
                        }
                    }
                }
                else //There are no seats in either first or economy classes
                {
                    m_view->dialogMessage("There are no seats in either first or economy classes. ");
 
                    if(m_view->yesNoDialog("Would you like to be added on the First class waiting list? y/n"))
                    {
                       auxFlight->addPassenger(auxPassenger, Flight.SeatClass.First);
                    }
                    else
                    {

                       if(m_view->yesNoDialog("Would you like to be added on the Economy class waiting list? y/n"))
                       {
                         auxFlight->addPassenger(auxPassenger, Flight.SeatClass.Economy);
                       }
                       else
                       {
                           m_view->dialogMessage("You were not added to either waiting list.");
                       }
                    }
                }
            }

            else //The class of unavailable seats is economy
            {
                if(m_view->yesNoDialog("There are no seats available.  Would you like to be put on the waiting list? y/n"))
                {
                     auxFlight->addPassenger(auxPassenger, Flight.SeatClass.Economy);
                }

                else
                {
                    m_view->dialogMessage("You were not added to the list. Thank you.");
                }


            }
        }
    }
    else
    {
        //Think of a way of logging errors and exceptions
        cerr<<"makeReservation: The flight and/or passenger do not exist."<<endl;
    }
}


void Controller::makeCancellation(string _name, string _code)
{
    //Removes a person from the flight
    //Get the flight
    Flight *auxFlight = m_model->getFlightByCode(_code);
    //Get the passenge
    Passenger *auxPassenger = m_model->getPassengerByName(_name);


    if ((auxFlight != NULL) && (auxPassenger != NULL))
    {
        //Remove passenger from flight
        auxFlight->removePassenger(auxPassenger);

        //Remove flight from passenger
        auxPassenger->removeFlight(auxFlight);
	m_view->dialogMessage("Success, you were removed from the flight!");
    }
    else
    {
        cerr<<"makeCancellation: The flight and/or passenger do not exist. "<<endl;
    }
}

vector<Flight*> Controller::makePassengerInquiry(string _name)
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

vector<Passenger*>* Controller::makeFlightInquiry(string _code, SeatClass _class)
{
  //Gets the passengers on a flight

    Flight *auxFlight = m_model->getFlightByCode(_code);

    if(auxFlight)
    {
        return &(auxFlight->getPassengers(_class));
    }
    else
    {
        cerr<<"makeFlightEnquiry: The flight requested does not exist."<<endl;
        return NULL;
    }
}

vector<Passenger*>* Controller::makeFlightWaitingInquiry(string _code, SeatClass _class)
{
    //Gets the passengers on a flight

      Flight *auxFlight = m_model->getFlightByCode(_code);

      if(auxFlight)
      {
          return &(auxFlight->getWaiting(_class));
      }
      else
      {
          cerr<<"makeFlightWaitingEnquiry: The flight requested does not exist."<<endl;
          return NULL;
      }
}

//Display the passengers (either waiting or on the booking list
    void Controller::refreshPassengers(vector<Passenger*>* _passengers)
	{
	 m_view->displayPassengers(_passengers);
	}

//Display the flights (of a passenger)
    void Controller::refreshFlights(vector<Flight*>* _flights)
	{
	 m_view->displayFlights(_flights);	
	}

//Setters and getters
    Model* getModel()
   {
     return m_model;
   }

    AbstractView* getView()
   {
      return m_view;
   }


