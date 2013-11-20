#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_view = new GUIView(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_view;
}


void MainWindow::on_reservationButton_clicked()
{
    /* We need to select the passenger from the passenger list and the flight from the flight list, plus the class
     *and send the info to the controller.
     *Check passenger text box first for a valid name ... if no name is there, then see which passenger is selected in the list
     *and which flight is selected in the other list. A default selection can be the last passenger and the last flight.
    */

    QString line;
    string auxName;
    string auxCode;
    SeatClass auxClass;


//CHECK! The lists are empty
    QList<QListWidgetItem*> auxPassengerItemList = ui->passengerList->selectedItems();
    QListWidgetItem* auxPassenger;
    QList<QListWidgetItem*> auxFlightItemList = ui->flightList->selectedItems();
    QListWidgetItem* auxFlight;

//Getting the passenger information
    if(auxPassengerItemList.isEmpty())
    {
        //No passengers were selected - check the text box
        line = ui->passengerNameBox->toPlainText();

        //CHECK name - if no name written show message
        if(line.isEmpty())
        {
            m_view->dialogMessage("No name was selected! Please write a name in the text box provided!");
            break; //or exit?
        }
        else
        {
            auxName = line.toStdString();
        }
    }
    else
    {
        //Get the last selected passenger, and get his name
        auxPassenger = auxPassengerItemList.last();
        auxName = (auxPassenger->text()).toStdString();
    }

//Getting the flight information

    if(auxFlightItemList.isEmpty())
    {
        m_view->dialogMessage("No flight was selected. Please select a flight for your passenger and try again.");
        break;
    }
    else
    {
        auxFlight = auxFlightItemList.last();

        //Gets the first string from the flight string info, which corresponds to the code of the flight
        auxCode = (((auxFlight->text()).split(QRegExp(" "))).first()).toStdString();
    }


//Getting class information

    if(ui->firstRadio->isChecked())
    {
        auxClass = SeatClass.First;
    }
    else
    {
        //CHECK - can both radio buttons be active or unactive?
        auxClass = SeatClass.Economy;
    }


//With all the information gathered, we call the view method, which will call the controller's method

    m_view->makeReservationEvent(auxName, auxCode, auxClass);
}



void MainWindow::on_cancellationButton_clicked()
{
    //OBS! No one actually checks if the flight IS in the passenger's list and viceversa - if a passenger is selected
    //OBS! REUSE some code from reservation method

    string auxName;
    string auxCode;


//CHECK! The lists are empty
    QList<QListWidgetItem*> auxPassengerItemList = ui->passengerList->selectedItems();
    QListWidgetItem* auxPassenger;
    QList<QListWidgetItem*> auxFlightItemList = ui->flightList->selectedItems();
    QListWidgetItem* auxFlight;

//Getting the passenger information
    if(auxPassengerItemList.isEmpty())
    {
     //No passengers were selected
      m_view->dialogMessage("No name was selected! Please write a name in the text box provided!");
      break;
    }
    else
    {
        //Get the last selected passenger, and get his name
        auxPassenger = auxPassengerItemList.last();
        auxName = (auxPassenger->text()).toStdString();
    }

//Getting flight information - CODE REUSE METHOD HERE might be useful
    if(auxFlightItemList.isEmpty())
    {
        m_view->dialogMessage("No flight was selected. Please select a flight for your passenger and try again.");
        break;
    }
    else
    {
        auxFlight = auxFlightItemList.last();

        //Gets the first string from the flight string info, which corresponds to the code of the flight
        auxCode = (((auxFlight->text()).split(QRegExp(" "))).first()).toStdString();
    }



 m_view->makeCancellationEvent(auxName, auxCode);
 }





void MainWindow::on_firstRadio_clicked()
{
  ui->firstRadio->setChecked(true);
  ui->economyRadio->setChecked(false);
}



void MainWindow::on_economyRadio_clicked()
{
  ui->economyRadio->setChecked(true); //Is this necessary?
  ui->firstRadio->setChecked(false);
}


