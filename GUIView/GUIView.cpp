#include "GUIView.h"
#include "Controller.h"
#include <ui_mainwindow.h>
#include <map>
#include <QMessageBox>
#include <iostream>

GUIView::GUIView(Ui::MainWindow* _ui)
{
    //Contructor - we start off with a null controller
    m_controller = NULL;
    m_ui = _ui;
}

GUIView::~GUIView()
{
    //Nothing to delete
}


void GUIView::help()
{
    //Help function will tell the user about the options of the program
}

void GUIView::start()
{
    //The initialisation of the program
    //Display passengers and flights - methods below
    //Need method from controller->model->getAllPassengers() and getAllFlight() that returns a vector of all flights and passengers

    //TODO: Fix double accessing issue...works for now
    map<string,Passenger*>* auxPassengers = m_controller->getModel()->getPassengers();
    map<string, Flight*>*  auxFlights = m_controller->getModel()->getFlights();


    //Clear lists and readd the information within them
    m_ui->passengerList->clear();
    m_ui->flightList->clear();
    this->displayPassengers(auxPassengers);
    this->displayFlights(auxFlights);
}

void GUIView::refresh()
{
    this->start();
}


//Display one passenger's information (name)
void GUIView::displayPassenger(Passenger* _passenger)
{
    if(_passenger!=NULL)
    {
        m_ui->passengerList->addItem(QString(_passenger->getName().c_str()));
    }
}

//Display one flight's information (code, number of seats, time and date)
void GUIView::displayFlight(Flight* _flight)
{
    if(_flight!=NULL)
    {
        m_ui->flightList->addItem(QString((_flight->getCode() + " "+ _flight->getDate()).c_str()));
    }
}

void GUIView::displayPassengers(pair<vector<Passenger*>::iterator,vector<Passenger*>::iterator>* _passengers)
{

    if(_passengers!=NULL)
    {
        vector<Passenger*>::iterator it;

        for (it = _passengers->first; it != _passengers->second && *it!= *(_passengers->second); it++)
        {
            displayPassenger(*it);
        }
    }
}

void GUIView::displayPassengers(map<string, Passenger*>* _passengers)
{

    if(_passengers!=NULL)
    {
        map<string, Passenger*>::iterator it;

        for(it = (* _passengers).begin(); it!=(*_passengers).end(); it++)
        {
            displayPassenger(it->second);
        }
    }
}



//Display all the flights a passenger's on, using a vector
void GUIView::displayFlights(vector<Flight*>* _flights)
{
    if(_flights!=NULL)
    {
        vector<Flight*>::iterator it;

        for (it = (*_flights).begin(); it != (*_flights).end(); it++)
        {
            displayFlight(*it);
        }
    }
}

//Display all the flights the passenger's on, using a map
void GUIView::displayFlights(map<string, Flight*>* _flights)
{
    if(_flights!=NULL)
    {
        map<string, Flight*>::iterator it;

        for (it = (*_flights).begin(); it != (*_flights).end(); it++)
        {
            displayFlight(it->second);
        }
    }
}

//OBS! When model updates, controller has to ask the view to refresh
//Reservation
void GUIView::makeReservationEvent(string _name, string _code, string _class)
{
    m_controller->makeReservation(_name, _code, _class);
}

//Cancellation
void GUIView::makeCancellationEvent(string _name, string _code)
{
    m_controller->makeCancellation(_name, _code);
}

//Passenger Inquiry
void GUIView::makePassengerInquiryEvent(string _name)
{
    //Get the passenger
    Passenger* auxPassenger = (m_controller->getModel())->getPassengerByName(_name);

    //Display the passenger
    this->displayPassenger(auxPassenger);

    //Display the flights he is on
    this->displayFlights(m_controller->makePassengerInquiry(_name));
}

//Flight Inquiry
void GUIView::makeFlightInquiryEvent(string _code)
{
    Flight* auxFlight = (m_controller->getModel())->getFlightByCode(_code);

    if(auxFlight!=NULL)
    {
    //Display the flight we're inquiring on
        this->displayFlight(auxFlight);

    //OBS! 4 lines that can be compacted into one function call
    //Display the passengers
        this->displayPassengers(m_controller->makeFlightInquiry(auxFlight->getCode(), Flight::First, Flight::Booked));
        this->displayPassengers(m_controller->makeFlightInquiry(auxFlight->getCode(), Flight::First, Flight::Waiting));
        this->displayPassengers(m_controller->makeFlightInquiry(auxFlight->getCode(), Flight::Economy, Flight::Booked));
        this->displayPassengers(m_controller->makeFlightInquiry(auxFlight->getCode(), Flight::Economy, Flight::Waiting));
    }
    else
    {
        std::cerr<<"Flight in GUIView::makeFlightInquiryEvent is null. \n";
    }
}

//Auxiliary methods
bool GUIView ::checkAnswer(char _answer)
{
    if(tolower(_answer)=='y' || _answer=='1')
       {
           return true;
       }
       else
       {
        return false;
       }
}

bool GUIView::yesNoDialog(string _message)
{

    return true;
}

void GUIView::dialogMessage(string _message)
{
    QMessageBox *auxPopup = new QMessageBox();

    auxPopup->setText(QString(_message.c_str()));
    auxPopup->adjustSize();
    auxPopup->show();
}

//Setters and getters
void GUIView::setController(Controller* _controller)
{
    m_controller = _controller;
}

Controller* GUIView::getController()
{
    return m_controller;
}

