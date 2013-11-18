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


<<<<<<< local
bool Controller::checkAnswer(char _answer)
{
    if(_answer=='y' || _answer=='Y' || _answer=='1')
    {
        return true;
    }
    else
    {
        return false;
    }
}
=======
>>>>>>> other

<<<<<<< local
string Controller::makeReservation(string _name, string _code, SeatClass _class)
=======
void Controller::makeReservation(string _name, string _code, SeatClass _class)
>>>>>>> other
{
    //Adds a person on a flight
    
    //Get the flight
    Flight *auxFlight = m_model->getFlightByCode(_code);
    //Get the passenge
    Passenger *auxPassenger = m_model->getPassengerByName(_name);
<<<<<<< local
    
    
    //QUESTION: What class is resposible for checking up the flight availability? Flight?
=======


>>>>>>> other
    //Check for availability of flight and existence of passenger
    if ((auxFlight != NULL) && (auxPassenger != NULL))
    {
        //checks the flight options and puts the passenger on a waiting list if needed
        int check = auxFlight->getSeatAvailability(_class);
        char option;
<<<<<<< local
        
=======

>>>>>>> other
        if(check>0)
        {
            //There are seats left, we add the passenger
            auxFlight->addPassenger(auxPassenger, _class);
<<<<<<< local
=======
	    m_view->popupMessage("Success, you were added on the flight!");
>>>>>>> other
        }
        else
        {
            //There aren't any seats left in that class
            if(_class == Flight.SeatClass.First)
            {
                //If the class is first, we offer the economy option
<<<<<<< local
                cout<<"There are no more seats left in the first class."<<endl;
                
=======
                m_view->popupMessage("There are no more seats left in the first class.");
	
>>>>>>> other
                check = auxFlight->getSeatAvailability(Flight.SeatClass.Economy);
                if(check>0)
                {
<<<<<<< local
                    cout<<"Would you like a seat in the economy class? y/n"<<endl;
                    cin>>option;
                    
                    if(checkAnswer(option))
=======

                    if(m_view->yesNoPopup("Would you like a seat in the economy class? y/n"))
>>>>>>> other
                    {
                        auxFlight->addPassenger(auxPassenger, Flight.SeatClass.Economy);
                    }
                    else
                    {
<<<<<<< local
                        cout<<"Would you like to be added on the First class waiting list? y/n"<<endl;
                        cin>>option;
                        
                        if(checkAnswer(option))
=======
                        if(m_view->yesNoPopup("Would you like to be added on the First class waiting list? y/n"))
>>>>>>> other
                        {
                            auxFlight->addPassenger(auxPassenger, Flight.SeatClass.First);
                        }
                        else
                        {
<<<<<<< local
                            cout<<"You were not added to the "<<auxFlight->getCode()<<", thank you!"<<endl;
=======
                           m_view->popupMessage("You were not added to the " + auxFlight->getCode() + ", thank you!");
>>>>>>> other
                        }
                    }
                }
                else //There are no seats in either first or economy classes
                {
<<<<<<< local
                    cout<<"There are no seats in either first or economy classes. "<<endl;
                    cout<<"Would you like to be added on the First class waiting list? y/n"<<endl;
                    cin>>option;
                    
                    if(checkAnswer(option))
=======
                    m_view->popupMessage("There are no seats in either first or economy classes. ");
 
                    if(m_view->yesNoPopup("Would you like to be added on the First class waiting list? y/n"))
>>>>>>> other
                    {
<<<<<<< local
                        auxFlight->addPassenger(auxPassenger, Flight.SeatClass.First);
=======
                       auxFlight->addPassenger(auxPassenger, Flight.SeatClass.First);
>>>>>>> other
                    }
                    else
                    {
<<<<<<< local
                        cout<<"Would you like to be added on the Economy class waiting list? y/n"<<endl;
                        cin>>option;
                        
                        if(checkAnswer(option))
                        {
                            auxFlight->addPassenger(auxPassenger, Flight.SeatClass.Economy);
                        }
                        else
                        {
                            cout<<"You were not added to either waiting list."<<endl;
                        }
=======

                       if(m_view->yesNoPopup("Would you like to be added on the Economy class waiting list? y/n"))
                       {
                         auxFlight->addPassenger(auxPassenger, Flight.SeatClass.Economy);
                       }
                       else
                       {
                           m_view->popupMessage("You were not added to either waiting list.");
                       }
>>>>>>> other
                    }
                }
            }
<<<<<<< local
            
=======

>>>>>>> other
            else //The class of unavailable seats is economy
            {
<<<<<<< local
                cout<<"There are no seats available.  Would you like to be put on the waiting list? y/n"<<endl;
                cin>>option;
                if(checkAnswer(option))
=======
                if(m_view->yesNoPopup("There are no seats available.  Would you like to be put on the waiting list? y/n"))
>>>>>>> other
                {
<<<<<<< local
                    auxFlight->addPassenger(auxPassenger, Flight.SeatClass.Economy);
=======
                     auxFlight->addPassenger(auxPassenger, Flight.SeatClass.Economy);
>>>>>>> other
                }
<<<<<<< local
                
=======

>>>>>>> other
                else
                {
<<<<<<< local
                    cout<<"You were not added to the list.  Thank you."<<endl;
=======
                    m_view->popupMessage("You were not added to the list. Thank you.");
>>>>>>> other
                }
<<<<<<< local
                
                
=======


>>>>>>> other
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
<<<<<<< local
        
=======

>>>>>>> other
        //Remove flight from passenger
        auxPassenger->removeFlight(auxFlight);
<<<<<<< local
=======
	m_view->popupMessage("Success, you were removed from the flight!");
>>>>>>> other
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
<<<<<<< local
    
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
=======

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
>>>>>>> other
}

//Display the passengers (either waiting or on the booking list
<<<<<<< local
void Controller::refreshPassengers(vector<Passenger*>* _passengers)
{
    m_view->displayPassengers(_passengers);
}
=======
    void Controller::refreshPassengers(vector<Passenger*>* _passengers)
	{
	 m_view->displayPassengers(_passengers);
	}
>>>>>>> other

//Display the flights (of a passenger)
<<<<<<< local
void Controller::refreshFlights(vector<Flight*>* _flights)
{
    m_view->displayFlights(_flights);	
}
=======
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


>>>>>>> other
