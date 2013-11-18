//
//  main.cpp
//  cw2
//
//  Created by Lang Yaping on 11/11/2013.
//  Copyright (c) 2013 Lang Yaping. All rights reserved.
//

#include <string>

//this is the class for storing data of passenger and flight using map and multimap
class Model {
	private:
        Model();
        Model(String);
		map<String,Passenger*> m_passengers;
		map<String,Flight*> m_flightByCode;
		multimap<String,Flight*> m_flightByDate;
		static model* s_model;
        static String s_filename="FCGDATA";

	public:
        static Model* getModel();
		Passenger* getPassengerByName(string _passenger);
		Flight* getFlightByCode(string _code);
		vector<Flight*> getFlightsByDate(string _date);

};

