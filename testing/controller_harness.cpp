#include "../Controller.h"
#include "../CLIView.h"
#include <iostream>


void test_makeReservation(Controller *_controller)
{
  cout<<"Controller, I am in the test_makeReservation method!"<<endl;
  _controller->makeReservation("John Atkinson", "AA321", "First");

}

void test(Controller *_controller)
{
//Test each method in thye controller class
 cout<<"Controller, I am in the test method!"<<endl;
 test_makeReservation(_controller);
}


//Testing the flight class and its methods

int main()
{
AbstractView* view = new CLIView();
Model* model = Model::getModel();

Controller* controller = new Controller(model, view);

test(controller);

return 0;
}
