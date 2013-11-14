//
//  model.cpp
//  cw2
//
//  Created by Lang Yaping on 14/11/2013.
//  Copyright (c) 2013 Lang Yaping. All rights reserved.
//

#include "model.h"
#include <string>

Model::Model m_model= new Model();

Model::Flight getFlightByCode(std::string _code);

Model::Passenger getPassengerByName(std::string _passenger);

//m_model->map<std::string,Passenger> Pmap;

//Pmap.insert(pair<string,Passenger>)(..,getPassengerByname));

//m_model->map<std::string,Flight> Fmap;
//Fmap.insert(pair<string,Flight>);


Passenger* getPassengerByName(string _passenger){
    m_model->map<string,Passenger>.insert(pair<string,Passenger>,(_passenger,getPassengerByName(_passenge);
}



Flight* getFlightByCode(string _code);{
    m_model->map<string,Flight>.insert(pair<string,Flight>,(_code,getFlightByCode(_code)));

}

vector<Flight*> getFlightsByDate(string _date);{
    m_model->map<string,Flight>.insert(pair<string,Flight>,(_date),Flight));

}
