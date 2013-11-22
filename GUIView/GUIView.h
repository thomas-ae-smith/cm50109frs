#ifndef GUIVIEW_H
#define GUIVIEW_H
#include "AbstractView.h"
#include <map>
#include "mainwindow.h"

class Controller;

namespace Ui {
class MainWindow;
}

class GUIView: public AbstractView
{
public:

    GUIView(Ui::MainWindow* _ui);
    ~GUIView();

    //Help
    void help();

    //Starting point
    void start();

    //Refresh
    void refresh();

    //Displaying Information
    //Display one passenger's information (name)
    void displayPassenger(Passenger* _passenger);

    //Display one flight's information (code, number of seats, time and date)
    void displayFlight(Flight* _flight);

    //Display all the passengers on a flight, either waiting or in one of the available classes (first, economy)
    void displayPassengers(vector<Passenger*>* _passengers);
    void displayPassengers(map<string, Passenger*>* _passengers);

    //Display all the flights a passenger's on
    void displayFlights(vector<Flight*>* _flights);
    void displayFlights(map<string, Flight*>* _flights);

    //Methods from interface
    //Takes info from interface and delivers it to controller which then updates model
    //Messages of the actions taken will then be sent from the controller to the view
    //Once updated the model will ask the view to update

    //Reservation
    void makeReservationEvent(string _name, string _code, SeatClass _class);
    //Cancellation
    void makeCancellationEvent(string _name, string _code);
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

private:
    Controller* m_controller;
    Ui::MainWindow* m_ui;
};


#endif // GUIVIEW_H
