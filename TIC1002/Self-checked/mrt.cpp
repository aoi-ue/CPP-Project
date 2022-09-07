
int main()
{   
    // initialize tracks 
    LineNode* tanjongPagartoCityHall = new LineNode;
    LineNode* cityHalltoRafflesPlace = new LineNode;
    LineNode* RafflesPlacetoTanjongPagar= new LineNode; 

    // create station 
    Station* cityHall = new Station;
    Station* rafflesPlace = new Station;
    Station* tanjongPagar = new Station;

    // assign names to stations  
    cityHall->name = "cityhall"; 
    rafflesPlace->name = "rafflesplace"; 
    tanjongPagar->name = "tanjongpagar"; 

    // let rp point to cityhall and next to null first with Linked List 
    tanjongPagartoCityHall->station = tanjongPagar; 
    tanjongPagartoCityHall->next = cityHalltoRafflesPlace; 

    cityHalltoRafflesPlace->station = cityHall; 
    cityHalltoRafflesPlace->next = RafflesPlacetoTanjongPagar; 

    // create vector of LineNode 
    vector<LineNode* > tp;
    vector<LineNode* > ch;
    vector<LineNode* > rp;

    tp.push_back(tanjongPagartoCityHall); 
    ch.push_back(cityHalltoRafflesPlace); 
    rp.push_back(RafflesPlacetoTanjongPagar); 

    rafflesPlace->lines = rp; 
    cityHall->lines = ch;  

    cout << distance_between(cityHalltoRafflesPlace, *rafflesPlace); 
    cout << distance_between(RafflesPlacetoTanjongPagar, *cityHall); 

    // cout << cityHall->lines[0]->station->name << endl; 
    // cout << cityHall->lines[1]->station->name; 

    return 0;
}