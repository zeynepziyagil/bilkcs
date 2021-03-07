//
//  ReservationSystem.h
//  cs201prj
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//21802646

#ifndef ReservationSystem_h
#define ReservationSystem_h
#include "Flight.h"
#include "Reservation.h"
#include <iostream>
#include<sstream>
using namespace std;
class ReservationSystem {
 
    
    
public:
    ReservationSystem();
    ~ReservationSystem();
void addFlight( const int flightNo, const int rowNo, const int seatNo );
void cancelFlight( const int flightNo );
void showAllFlights();
void showFlight( const int flightNo );
int makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol );
void cancelReservation( const int resCode );
void showReservation( const int resCode );

private:
    Flight* flightlist;
    Reservation* reservationlist;
    int reservationlistsize;
    int flightlistsize;
    
    
};

#endif /* ReservationSystem_h */
