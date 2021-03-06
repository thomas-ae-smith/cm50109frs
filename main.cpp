#include "Model.h"
#include "Controller.h"
#include "AbstractView.h"
#include "CLIView.h"


//TODO: Deallocate memory for model, view and controller

int main()
{

	Model* FRSModel = Model::getModel();
	AbstractView* FRSView = new CLIView();
	Controller* FRSController = new Controller(FRSModel, FRSView);
	FRSView->setController(FRSController);
	FRSView->start();


//Things to think about:

    //Create model - populate with flights (sorted by code and date)
    //Create view
    //View has pointer to model
    //Create Controller with pointer to model and view
    //or
    //Create Controller and instantiate model and views in Controller constructor
    //Deallocate memory in destructor


	//Reservation
	//Create/Select a passenger
	//Choose flight and class
	//Add passenger to flight and flight to passenger


	//Cancellation
	//Select a passenger
	//Select flight from passenger's list
	//Remove passenger from flight and flight from passenger
	

	//Passenger Inquiry
	//Select a passenger
	//Print out flights related to that passenger
	

	//Flight Inquiry
	//Select a flight
	//Print out passengers related to that flight


//Extras?
	//Remove a passenger from model
	//Remove a flight from model

}
