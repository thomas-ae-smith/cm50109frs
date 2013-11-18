//
//  model.cpp
//  cw2
//
//  Created by Lang Yaping on 14/11/2013.
//  Copyright (c) 2013 Lang Yaping. All rights reserved.
//

#include “model.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//Use model to store the data of passengers and flights
//Using Singlteton pattern here to keep only one instance of Model
Model::Model getModel(){
    if(s_model==nullptr){
        s_model=Model();
    }
    return s_model;
}

//get flight from the map using fight number the key
Flight* Model::getFlightByCode(string _code){
    return m_flightByCode[_code];
}
//get passenger from the map using passenger name as the kay
Passenger* Model::getPassengerByName(string _passenger){
    return m_passenger[_passenger];
}

//get all the flights on the given data
vector<Flight*> Model::getFlightByDate(string _date){
    pair<multimap<string,Flight*>::iterator,multimap<string,Flight*>::iterator> dateRange;
    dateRange=m_flightByDate.equal_range(_date);
    for(multimap<string,Flight*>::iterator it=dateRange.first;it!=dateRange.second;++it)
    {
     m_flightByDate.push_back(dataRange.second);
    }
    return m_flightByDate;
}
