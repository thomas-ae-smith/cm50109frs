//I put a main function so that I could test it.
//Takes a string of date numbers and checks the validity -- ddMMyyyy

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


bool checkDate (string date)
{
  int daysPerMonth[12] = {31, 29, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
  int dayNum, monthNum;

  string day = date.substr (0,2);
  string month = date.substr (2,2);

  istringstream ( day ) >> dayNum;
  istringstream ( month ) >> monthNum;

  if ( monthNum > 12 || monthNum < 1){
     cout<<"Invalid";
     return false;
  }
  else {
     if (daysPerMonth[monthNum - 1] >= dayNum){
      cout << "Valid.";
      return true;
     }
     else{
      cout << "Invalid.";
      return false;
     }
  }

}


int main(){

string date;
bool answer;

cin >> date;
answer = checkDate(date);
cout<<endl<< answer;

return 0;
}
