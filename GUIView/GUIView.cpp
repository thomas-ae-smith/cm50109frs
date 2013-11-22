#include "GUIView.h"
#include <map>

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

    //VERY BAD, double accessing...works for now
    map<string,Passenger*> auxPassengers = m_controller->getModel()->getPassengers();
    map<string, Flight*> auxFlights = m_controller->getModel()->getFlights();


    //Clear lists and readd the information within them
    this->displayPassengers(auxPassengers);

    m_ui->flightList->clear();
    this->displayFlights(auxFlights);
}

void GUIView::refresh()
{
    this->start();
}


//Display one passenger's information (name)
void GUIView::displayPassenger(Passenger* _passenger)
{
  m_ui->passengerList->addItem(_passenger->getName());
}

//Display one flight's information (code, number of seats, time and date)
void GUIView::displayFlight(Flight* _flight)
{
  m_ui->flightList->addItem(_flight->getName());
}

//Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
void GUIView::displayPassengers(vector<Passenger*>* _passengers)
{    
  m_ui->passengerList->clear();

  vector<Passenger*>::iterator it;

  for (it = (*_passengers).begin(); it != (*_passengers).end(); it++)
  {
   displayPassenger((*it));
  }
}

void GUIView::displayPassengers(map<string, Passengers*>* _passengers)
{
  m_ui->passengerList->clear();

  map<Passenger*>::iterator it;

    for(it = (* _passengers).begin(); it!=(*_passengers).end(); it++)
    {
        displayPassenger((*it));
    }
}



//Display all the flights a passenger's on
void GUIView::displayFlights(vector<Flight*>* _flights)
{
 //m_ui->flightList->clear();

 vector<Flight*>::iterator it;

 for (it = (*_flights).begin(); it != (*_flights).end(); it++)
 {
  displayFlight((*it));
 }
}

void GUIView::displayFlights(map<string, Flight*>* _flights)
{
// m_ui->flightList->clear();

 map<string, Flight*>::iterator it;

 for (it = (*_flights).begin(); it != (*_flights).end(); it++)
 {
  displayFlight((*it));
 }
}

//OBS! When model updates, controller has to ask the view to refresh
//Reservation
void GUIView::makeReservationEvent(string _name, string _code, SeatClass _class)
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
    //OBS! Double object call, high coupling, but works for now

    //Display the passenger
    this->displayPassenger(m_controller->getModel()->getPassengerByName(_name));

    //Display the flights he is on
    //OBS! What if there are no flights he is on?
    //PROBLEM? Pointer to a local vector is returned

    m_ui->flightList->clear();
    this->displayFlights(m_controller->makePassengerInquiry(_name));
}

//Flight Inquiry
void GUIView::makeFlightInquiry(string _code)
{
    Flight* auxFlight = (m_controller->getModel())->getFlightByCode(_code);

    this->displayFlight(auxFlight);

//OBS! 4 lines that can be compacted into one function call
    this->displayPassengers(m_controller->makeFlightInquiry(auxFlight->getCode(), SeatClass.First));
    this->displayPassengers(m_controller->makeFlightInquiry(auxFlight->getCode(), SeatClass.Economy));
    this->displayPassengers(m_controller->makeFlightWaitingInquiry(auxFlight->getCode(), SeatClass.First));
    this->displayPassengers(m_controller->makeFlightWaitingInquiry(auxFlight->getCode(), SeatClass.Economy));

}

//Auxiliary methods
bool GUIView ::checkAnswer(char _answer)
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

bool GUIView::yesNoDialog(string _message)
{


}

void GUIView::dialogMessage(string _message)
{


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

