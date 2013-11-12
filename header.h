//MODEL


//DATA
map <string, Passenger*> m_passengers
map <string, Flight*> m_flightsByCode
multimap <string, Flight*> m_flightsByDate

//METHODS
Passenger* getPassenger(string _passenger);
Flight* getFlightByName (string _name);
Flight* getFlightByCode (string _code);
