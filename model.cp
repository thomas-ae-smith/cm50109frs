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

<vector>Flight* Model:getFlightByDate(string _date){
    m_flightByDate::iterator it;
    it=m_flightByDate.equal_range(_date);
    for(it=m_flightByDate.begin();it!=m_flightByDate.end();it.next())
    {
        return m_flightBydate;
 
}
}