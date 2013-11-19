//
//  main.cpp
//  cw2
//
//  Created by Lang Yaping on 11/11/2013.
//  Copyright (c) 2013 Lang Yaping. All rights reserved.
//

#include <string>
#include <vector>
#include <map>
#include "Passenger.h"
#include "Flight.h"
using namespace std;
//this is the class for storing data of passenger and flight using map and multimap
class Model {
	private:
        Model();
        Model(string _filename);
		map<string,Passenger*> m_passengers;
		map<string,Flight*> m_flightByCode;
		multimap<string,Flight*> m_flightByDate;
		static Model* s_model;
        static string s_filename="FCGDATA";

	public:
        static Model* getModel();
		Passenger* getPassengerByName(string _passenger);
		Flight* getFlightByCode(string _code);
		vector<Flight*> getFlightsByDate(string _date);

};

