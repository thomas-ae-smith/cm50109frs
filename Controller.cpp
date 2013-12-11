#include "Controller.h"
#include <iostream>
#include <assert.h>


//OBSERVATION - Design!
//When adding data to the model, more bahaviours need to be tested -> Controller is responsible
//When getting information from the model, data validity needs to be tested -> Model is responsible
//TODO: makeReservation method needs to be simplified

//Constructor - takes in pointers to the model and the view
Controller::Controller(Model *_model, AbstractView *_view)
{
    m_model = _model;
    m_view = _view;
}

//Destructor
Controller::~Controller()
{
    //No space was allocated
}


//Checks if a passenger is trying to book a flight on the same day as another flight he's already on
bool Controller::hasSameDayFlights(string _name, Flight* _flight)
{
    if(_flight!=NULL)
    {
        vector<Flight*>* auxFlights = this->makePassengerInquiry(_name);

        if(auxFlights!=NULL)
        {
            vector<Flight*>::iterator it = auxFlights->begin();

            while(it!=auxFlights->end())
            {
                if((*it)->getDate() == _flight->getDate())
                {
                    return true;
                }
                it++;
            }
        }
    }
    return false;
}

//Checks if the passenger is on that flight
bool Controller::passengerHasFlight(string _name, string _code)
{
    //Get the flight
    Flight *auxFlight = m_model->getFlightByCode(_code);
    //Get the passenge
    Passenger *auxPassenger = m_model->getPassengerByName(_name);


    if((auxPassenger!=NULL) && (auxFlight!=NULL))
    {
        vector<Flight*>* auxFlightList = auxPassenger->getFlights();

        if(auxFlightList!=NULL)
        {
            vector<Flight*>::iterator it = auxFlightList->begin();

            while(it!=auxFlightList->end())
            {
                if(*it == auxFlight)
                {
                    return true;
                }
                ++it;
            }
        }
    }
    return false;
}

//Adds a reservation to the model and refreshes the view
void Controller::addReservation(string _name, string _code, Flight::SeatClass _class)
{
    m_model->addReservation(_name, _code, _class);
    m_view->refresh();
    m_view->dialogMessage("Success, you were added on the flight! \n");
}

//Makes a cancellation, by accessing the model's cancellation method
void Controller::addCancellation(string _name, string _code)
{
    m_model->addCancellation(_name, _code);
    m_view->refresh();
    m_view->dialogMessage("Success, you were removed from the flight!");
}

//Makes a reservation: Adds a person on a flight and a flight to a person
void Controller::makeReservation(string _name, string _code, string _class)
{
    //Get the flight and the seat class
    Flight *auxFlight = m_model->getFlightByCode(_code);
    Flight::SeatClass auxClass = m_model->getClass(_class);

    //Check
    if (!hasSameDayFlights(_name, auxFlight))
    {	
        //checks the flight options and puts the passenger on a waiting list if needed
        int check = auxFlight->getSeatAvailability(auxClass);

        if(check>0) //There are seats left, we add the passenger
        {            
            addReservation(_name, _code, auxClass);
        }

        else //There aren't any seats left in that class
        {            
            if(auxClass == Flight::First) //If the class is first, we offer the economy option
            {                
                m_view->dialogMessage("There are no more seats left in the first class.");
	
                check = auxFlight->getSeatAvailability(Flight::Economy);

                if(check>0)
                {
                 //There are seats available in the economy class
                    if(m_view->yesNoDialog("Would you like a seat in the economy class? y/n"))
                    {
                        addReservation(_name, _code, Flight::Economy);
                    }
                    else
                    {
                        if(m_view->yesNoDialog("Would you like to be added on the First class waiting list? y/n"))
                        {
                            addReservation(_name, _code, Flight::First);
                        }
                        else
                        {
                           m_view->dialogMessage("You were not added to the " + _code + ", thank you!");
                        }
                    }
                }
                else //There are no seats in either first or economy classes
                {
                    m_view->dialogMessage("There are no seats in either first or economy classes. ");
 
                    if(m_view->yesNoDialog("Would you like to be added on the First class waiting list? y/n"))
                    {
                       addReservation(_name, _code, Flight::First);
                    }
                    else
                    {

                       if(m_view->yesNoDialog("Would you like to be added on the Economy class waiting list? y/n"))
                       {
                          m_model->addReservation(_name, _code, Flight::Economy);
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
                     addReservation(_name, _code, auxClass);
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
        //TODO: Think of a way of logging errors and exceptions
        m_view->dialogMessage("The flight is on the same day as another flight you are booked on or it doesn't exist .\n");
    }
}


//Removes a person from the flight
void Controller::makeCancellation(string _name, string _code)
{      
    if(passengerHasFlight(_name, _code))
    {
        this->addCancellation(_name, _code);
    }
    else
    {
        m_view->dialogMessage("The flight was not found in the passengers flight list.\n");
    }
}

//Gets the flights the passenger is on
vector<Flight*>* Controller::makePassengerInquiry(string _name)
{
    return m_model->makePassengerInquiry(_name);
}

//Gets the booked/waiting passengers from a certain flight
pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>* Controller::makeFlightInquiry(string _code, Flight::SeatClass _class, Flight::SeatStatus _status)
{
    return m_model->makeFlightInquiry(_code, _class, _status);
}



//Setters and getters
Model* Controller::getModel() {
 return m_model;
}

AbstractView* Controller::getView() {
  return m_view;
}


