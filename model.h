//
//  main.cpp
//  cw2
//
//  Created by Lang Yaping on 11/11/2013.
//  Copyright (c) 2013 Lang Yaping. All rights reserved.
//

#include <string>

class Model {
	private:
		map<String,Passenger*> m_passengers;
		map<String,Flight*> m_flightByCode;
		map<String,Flight*> m_flightByDate;
		model* m_model;

	public:
		Passenger* getPassengerByName(string _passenger);
		Flight* getFlightByCode(string _code);
		vector<Flight*> getFlightsByDate(string _date);
};
