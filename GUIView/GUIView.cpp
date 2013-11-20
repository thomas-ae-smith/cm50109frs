#include "GUIView.h"


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

//Display all the flights a passenger's on
void GUIView::displayFlights(vector<Flight*>* _flights)
{
 vector<Flight*>::iterator it;

 for (it = (*_flights).begin(); it != (*_flights).end(); it++)
 {
  displayFlight((*it));
 }
}


//Reservation
void GUIView::makeReservationEvent(string _name, string _code, SeatClass _class)
{
    m_controller->makeReservation(_name, _code, _class);
}

//Cancellation
void makeCancellationEvent(string _name, string _code)
{
    m_controller->makeCancellation(_name, _code);
}

//Passenger Inquiry
void makePassengerInquiryEvent(string _name);
//Flight Inquiry
void makeFlightInquiry(string _code);

//Auxiliary methods
bool checkAnswer(char _answer);
bool yesNoDialog(string _message);
void dialogMessage(string _message);

//Setters and getters
void setController(Controller* _controller);
Controller* getController();
