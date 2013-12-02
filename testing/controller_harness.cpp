#include "../Controller.h"
#include "../CLIView.h"
#include <iostream>


void test(Controller *_controller)
{
//Test each method in thye controller class

 
}


//Testing the flight class and its methods

int main()
{
AbstractView* view = new CLIView();
Model* model = Model::getModel();

Controller* controller = new Controller(model, view);
cout<<"Hello Controller harness!";

test(controller);

return 0;
}
