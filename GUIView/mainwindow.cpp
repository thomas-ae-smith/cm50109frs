#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->economyRadio->setChecked(true);

    m_model = Model::getModel();
    m_view = new GUIView(ui);
    m_controller = new Controller(m_model, m_view);
    m_view->setController(m_controller);

    m_view->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_view;
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


void MainWindow::on_refreshButton_clicked()
{
    m_view->refresh();
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
    string auxClass;


//CHECK! The lists are empty
    QList<QListWidgetItem*> auxPassengerItemList = ui->passengerList->selectedItems();
    QListWidgetItem* auxPassenger;
    QList<QListWidgetItem*> auxFlightItemList = ui->flightList->selectedItems();
    QListWidgetItem* auxFlight;

//Getting the passenger information-----------------------------------------------------
    if(auxPassengerItemList.isEmpty())
    {
        //No passengers were selected - check the text box
        line = ui->passengerNameBox->toPlainText();

        //CHECK name - if no name written show message
        if(line.isEmpty())
        {
            m_view->dialogMessage("No name was selected! Please write a name in the text box provided!");
            return;
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

//Getting the flight information----------------------------------------------------

    if(auxFlightItemList.isEmpty())
    {
        m_view->dialogMessage("No flight was selected. Please select a flight for your passenger and try again.");
        return;
    }
    else
    {
        auxFlight = auxFlightItemList.last();

        //Gets the first string from the flight string info, which corresponds to the code of the flight
        auxCode = (((auxFlight->text()).split(QRegExp(" "))).first()).toStdString();
    }


//Getting class information--------------------------------------------------------------

    if(ui->firstRadio->isChecked())
    {
        auxClass = Flight::First;
    }
    else
    {
        //CHECK - can both radio buttons be active or unactive?
        auxClass = Flight::Economy;
    }


//With all the information gathered, we call the view method, which will call the controller's method

    m_view->makeReservationEvent(auxName, auxCode, auxClass);
}


void MainWindow::on_cancellationButton_clicked()
{
    //OBS! No one actually checks if the flight IS in the passenger's list and viceversa - if a passenger is selected
    //OBS! REUSE some code from reservation method
    //TODO: When a passenger has no more flight - delete him from the list?

    string auxName;
    string auxCode;


//CHECK! The lists are empty
    QList<QListWidgetItem*> auxPassengerItemList = ui->passengerList->selectedItems();
    QListWidgetItem* auxPassenger;
    QList<QListWidgetItem*> auxFlightItemList = ui->flightList->selectedItems();
    QListWidgetItem* auxFlight;

//Getting the passenger information------------------------------------------------
    if(auxPassengerItemList.isEmpty())
    {
     //No passengers were selected
      m_view->dialogMessage("No passenger was selected! Please select a passenger from the list. \n");
      return;
    }
    else
    {
        //Get the last selected passenger, and get his name
        auxPassenger = auxPassengerItemList.last();
        auxName = (auxPassenger->text()).toStdString();
    }

//Getting flight information - CODE REUSE METHOD HERE might be useful---------------------
    if(auxFlightItemList.isEmpty())
    {
        m_view->dialogMessage("No flight was selected. Please select a flight for your passenger and try again.");
        return;
    }
    else
    {
        auxFlight = auxFlightItemList.last();

        //Gets the first string from the flight string info, which corresponds to the code of the flight
        auxCode = (((auxFlight->text()).split(QRegExp(" "))).first()).toStdString();
    }

 m_view->makeCancellationEvent(auxName, auxCode);
 }



void MainWindow::on_flightInquiry_clicked()
{
    QList<QListWidgetItem*> auxFlightItemList = ui->flightList->selectedItems();
    QListWidgetItem* auxFlightItem;

    if(!auxFlightItemList.isEmpty())
    {
        auxFlightItem = auxFlightItemList.last();
        QString text = auxFlightItem->text();
        text = text.split(QRegExp(" ")).first();
        ui->passengerList->clear();
        ui->flightList->clear();
        m_view->makeFlightInquiryEvent(text.toStdString());
    }
    else
    {
        m_view->dialogMessage("Please select a flight to make the inquiry on! \n");
    }
}



void MainWindow::on_passengerInquiry_clicked()
{
    QList<QListWidgetItem*> auxPassengerItemList = ui->passengerList->selectedItems();
    QListWidgetItem* auxPassengerItem;

    if(!auxPassengerItemList.isEmpty())
    {
        auxPassengerItem = auxPassengerItemList.last();
        QString text = auxPassengerItem->text();
        ui->passengerList->clear();
        ui->flightList->clear();
        m_view->makePassengerInquiryEvent(text.toStdString());
    }
    else
    {
        m_view->dialogMessage("Please select a passenger to make the inquiry on! \n");
    }
}
