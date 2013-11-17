//
//  model.cpp
//  cw2
//
//  Created by Lang Yaping on 14/11/2013.
//  Copyright (c) 2013 Lang Yaping. All rights reserved.
//

#include "model.h"
#include <string>
#include <iostream>

using namespace std;

Model::Model getModel(){
    if(s_model==nullptr){
        s_model=Model();
    }
    return s_model;
}


Flight* Model::getFlightByCode(string _code){
    return m_flightByCode[_code];
}

Passenger* Model::getPassengerByName(string _passenger){
    return m_passenger[_passenger];
}

vector<Flight*> Model::getFlightByDate(string _date){
    vector<Flight*> flightThisDate=nullptr;
    pair<multimap<string,Flight*>::iterator,multimap<string,Flight*>::iterator> dateRange;
    dateRange=m_flightByDate.equal_range(_date);
    for(multimap<string,Flight*>::iterator it=dateRange.first;it!=dateRange.second;++it)
    {
        flightThisDate.insert(m_flightByDate::it);
    }
    return flightThisDate;
}