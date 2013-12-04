#include "../Controller.h"
#include "../CLIView.h"
#include <iostream>
#include <assert.h>

bool test_makeReservation(Model *_model, AbstractView *_view, Controller *_controller)
{
//T1. Testing the existance of flights and passengers
//T1.1. Nonexisting flight, new passenger/existing passenger
//  _controller->makeReservation("Marius Iana", "ERT456", "Economy");
//Displays user error message -------------- ok

//T1.2. Existing flight, new passenger
// _controller->makeReservation("Johnny Atkinson", "AA321", "First");
//Passenger is added to flight and viceversa, user message is displayed---------ok

//T2. Seat availability
//T2.1. Existing flight, existing passenger, seats available
 _controller->makeReservation("John Smith", "AA321", "First");
 _controller->makeReservation("Annie Void", "AA321", "First");

//Passenger is added to flight and viceversa, user message is displayed----------ok

//T2.2. Existing flight, passenger, seats unavailable for first class
//    _controller->makeReservation("John Smith", "GFRTY", "First");
//    _controller->makeReservation("George Cauchy", "GFRTY", "First");
//Problem with View -> yesnodialog method ------------------------to check

//T.2.3. Existing flight, passenger, seats unavailable for economy class
// Problem idem T2.1. --------------------------------------------to check

//T.2.4. Existing flight, passenger, flight on the same day as another flight
// _controller->makeReservation("Annie Void", "TTTTT", "First");
//Displays user message------------------------------ok



//DISPLAY
//Display the flights
//_view->displayFlights(_model->makePassengerInquiry("John Atkinson"));
//Display the passengers


  return true;
}

bool test_makeCancellation(Model *_model, AbstractView *_view, Controller *_controller)
{
//T1. The passenger and flight exist
// _controller->makeCancellation("John Smith", "AA321");
//Removes passenger from the flight and flight from the passenger, displays user message--------ok

//T2. The passenger doesn't exist, flight exists
//  _controller->makeCancellation("George of the jungle", "AA321");
//Displays user message-----------------------------ok


//T3. The passenger exists, the flight doesn't exist
//  _controller->makeCancellation("John Smith", "TYDFX");
//Displays user message------------------ok

return true;
}

bool test_passengerInquiry(Model *_model, AbstractView *_view, Controller *_controller)
{
//T1. Passenger exists and has flights he's booked/waiting on
//TODO: Distinction between booked and waiting
//  _view->displayFlights(_controller->makePassengerInquiry("John Smith"));
//Displays the flights------------------ok

//T2. Passenger exists and doesn't have flights he is booked on
//Display nothing-------------------------ok
//TODO: Message for user?

//T3. Passenger doesn't exist
// _view->displayFlights(_controller->makePassengerInquiry("Manananana"));
//Display user message----------------ok

return true;
}

bool test_flightInquiry(Model *_model, AbstractView *_view, Controller *_controller)
{
//T1. Flight exists and has passengers on
//T1.1. The passengers are booked in the first class
 _view->displayPassengers(_controller->makeFlightInquiry("AA321", Flight::First, Flight::Booked));
//Displays passengers for flight----------ok
//TODO: Problem with diplay passenger pair of iterator function accesses a a last null passenger which gives SF

//T1.2. The passengers are booked in the economy class
 _view->displayPassengers(_controller->makeFlightInquiry("AA321", Flight::Economy, Flight::Booked))
         ;
//T1.3. The passengers are waiting in the first class
 _view->displayPassengers(_controller->makeFlightInquiry("AA321", Flight::First, Flight::Waiting));

//T1.4. The passengers are waiting in the economy class
 _view->displayPassengers(_controller->makeFlightInquiry("AA321", Flight::Economy, Flight::Waiting));

//T1.5. Flight exists and doesn't have passengers on
  _view->displayPassengers(_controller->makeFlightInquiry("TW098", Flight::First, Flight::Booked));

//T2. Flight doesn't exist
 _view->displayPassengers(_controller->makeFlightInquiry("FH321", Flight::First, Flight::Booked));

return true;
}



void test(Model *_model, AbstractView *_view, Controller *_controller)
{
//Test each method in thye controller class
 assert(test_makeReservation(_model, _view, _controller));
 assert(test_makeCancellation(_model, _view, _controller));
 assert(test_passengerInquiry(_model, _view, _controller));
 assert(test_flightInquiry(_model, _view, _controller));
}


//Testing the flight class and its methods

int main()
{
AbstractView* view = new CLIView();
Model* model = Model::getModel();
Controller* controller = new Controller(model, view);

//Adding passengers to the model
//model->addPassenger("Abraham Lincoln");
model->addPassenger("John Smith");
model->addPassenger("Annie Void");

test(model, view, controller);

return 0;
}
