#include "Flight.h"
#include "Passenger.h"
#include <iostream>

//Testing the passenger class and its methods.
// NOTE: Enabling the destructor test will crash the program.  That is the desired result.

using namespace std;


int main()
{

//Constructs a flight
    Flight* flight1 = new Flight("The Valiant", "0900", "25102012", 500);
    Flight* flight2 = new Flight("TARDIS", "Anytime", "26102012", 220);

//Constructs a passenger
	Passenger* passenger1 = new Passenger("The Master");
	Passenger* passenger2 = new Passenger("The Doctor");
    Passenger* passenger15 = new Passenger("The Doctor's Metacrisis Clone");


//Adds the passengers to the flights
    flight1->addPassenger(passenger1, Flight::First);
    flight2->addPassenger(passenger1, Flight::First);

    flight1->addPassenger(passenger2, Flight::Economy);
    flight2->addPassenger(passenger2, Flight::Economy);

    flight1->addPassenger(passenger15, Flight::Economy);
    flight2->addPassenger(passenger15, Flight::First);

// adds flight to passenger1
    passenger1->addFlight(flight1);
    passenger1->addFlight(flight2);

//adds flights to passenger2
    passenger2->addFlight(flight1);
    passenger2->addFlight(flight2);

//adds flights to passenger15
    passenger15->addFlight(flight1);
    passenger15->addFlight(flight2);

//Testing that the passengers' name was created correctly, and that the getName method works
    cout << "The name of passenger 1 should be The Master. " << endl << "The name is " << passenger1->getName() << endl;
    cout << "The name of passenger 2 should be The Doctor. " << endl << "The name is " << passenger2->getName() << endl;
    cout << "The name of passenger 1.5 should be The Doctor's Metacrisis Clone. " << endl << "The name is " << passenger15->getName() << endl << endl;

//Testing setName
  passenger1->setName("Professor Yana");
  cout << "NOW the name of passenger 1 should be Professor Yana. " << endl << "The name is " << passenger1->getName() << endl<<endl;
  cout<< "--------------------------------------------------------------------- \n\n";

//want to test getFlights with passenger1 & first class.
     vector <Flight*>::iterator it;
     vector <Flight*>* fList = passenger1->getFlights();
     cout << "List of flights for passenger 1: " << endl;
     for(it = fList->begin(); it != fList->end(); it++){
     cout << (*it)->getCode() << endl;
     cout << "seats still available in First Class for this flight: " <<  (*it)->getSeatAvailability(Flight::First) << endl << endl ;
  }

//Want to test removeFlight
   passenger1->removeFlight(flight1);

//Did remove flight work?
     for(it = fList->begin(); it != fList->end(); it++) {
     cout <<"Updated list of flights for passenger 1: \n" << (*it)->getCode() << endl;
     cout << "seats still available in First Class for this flight: " <<  (*it)->getSeatAvailability(Flight::First) << endl << endl ;
     }
     cout<< "--------------------------------------------------------------------- \n\n";

//testing getFlights with passenger2 and economy class

     vector <Flight*>::iterator it2;
     vector <Flight*>* fList2 = passenger2->getFlights();
     cout << "List of flights for passenger 2: " << endl;
     for(it2 = fList2->begin(); it2 != fList2->end(); it2++){
     cout << (*it2)->getCode() << endl;
     cout << "seats still available in Economy Class for this flight: " <<  (*it2)->getSeatAvailability(Flight::Economy) << endl <<endl;
    }
    cout<< "--------------------------------------------------------------------- \n\n";

//testing getFlights with passenger15 and both classes

     vector <Flight*>::iterator it15;
     vector <Flight*>* fList15 = passenger15->getFlights();
     cout << "List of flights for passenger 1.5: " << endl;
     for(it15 = fList15->begin(); it15 != fList15->end(); it15++){
     cout << (*it15)->getCode() << endl;
     cout << "seats still available in First Class for this flight: " <<  (*it15)->getSeatAvailability(Flight::First) <<endl;
     cout << "seats still available in Economy Class for this flight: " <<  (*it15)->getSeatAvailability(Flight::Economy) << endl <<endl;
    }
    cout<< "--------------------------------------------------------------------- \n\n";

//New passenger in economy on flight2
   cout<< "Adding a new passenger to Economy Class on flight 2.\n";
   Passenger* passenger3 = new Passenger("Donna Noble");

   flight2->addPassenger(passenger3, Flight::Economy);
   passenger3->addFlight(flight2);
   cout << "The name of passenger 3 should be Donna Noble. " << endl << "The name is " << passenger3->getName() << endl<< endl;

   vector <Flight*>::iterator it3;
     vector <Flight*>* fList3 = passenger3->getFlights();
     cout << "List of flights for passenger 3: " << endl;
     for(it3 = fList3->begin(); it3 != fList3->end(); it3++){
     cout << (*it3)->getCode() << endl;
     cout << "seats still available in Economy Class for this flight: " <<  (*it3)->getSeatAvailability(Flight::Economy) << endl <<endl;
    }


//re-testing flight list for passenger 2 and economy to make sure it reflects the addition of passenger 3
     vector <Flight*>::iterator it4;
     vector <Flight*>* fList4 = passenger2->getFlights();
     cout << "Now re-testing passenger 2 to confirm seats available \n\n" << "List of flights for passenger 2: " << endl;
     for(it4 = fList2->begin(); it4 != fList4->end(); it4++){
     cout << (*it4)->getCode() << endl;
     cout << "seats still available in Economy Class for this flight: " <<  (*it4)->getSeatAvailability(Flight::Economy) << endl <<endl;
    }
cout<< "--------------------------------------------------------------------- \n\n";
cout<<"(To enable testing of the deconstructor, you must delete the comment markers \n at the end of the program code.) \n";

//Testing the deconstructor on passenger 3
//THIS SHOULD PRINT GARBAGE AND CRASH THE PROGRAM

/*
delete passenger3;
cout<< "Passenger 3 deleted: Checking if memory for passenger3 was deallocated. \n";
cout<< "If memory was deallocated, rubbish will be printed beneath the lines. \nThe program will also crash. \n\n";
cout<< "--------------------------------------------------------------------- \n";
cout<< "--------------------------------------------------------------------- \n\n";

 for(it3 = fList3->begin(); it3 != fList3->end(); it3++){
     cout << (*it3)->getCode() << endl;
     cout << "seats still available in Economy Class: " <<  (*it3)->getSeatAvailability(Flight::Economy) << endl <<endl;
    }

*/

return 0;
}
