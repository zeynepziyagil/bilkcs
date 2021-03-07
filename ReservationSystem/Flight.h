//
//  Flight.h
//  cs201prj
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//21802646

#ifndef Flight_h
#define Flight_h
#include <stdio.h>
#include <string>
#include <iostream>
#include "Reservation.h"
#include<sstream>
using namespace std;
class Flight{
private:
    int flightNo;
    int rowNo;
    int seatNo;
    int pnumber;
    int availableseats;
    Reservation* reservationflight;
    int reservationcodenum;
    string* seatplans;

    
public:
    Flight(  int flightNo,  int rowNo,  int seatNo );
    Flight();
    ~Flight();// int * reservationcodes;string * seatplans;
    Flight&operator=(const Flight& flt);//assignment operator
    int getFlightNo();
    void setFlightNo(int a);
    int getRowNo();
    void setRowNo(int a);
    int getSeatNo();
    void setSeatNo(int a);
    int getpnumber();
    void setpnumber(int n);
    void setavailableseats(int num);
    int getavailableseats();
    int getreservationcodenum();
    void setreservationcodenum(int n);
    Reservation* getreservationflight();
    void addreservationflight(int thereservationcode,int thereservationsize,int theflightno,const int* row,const char* column);
    void deletereservationflight(int code);
    void modifyseatings( int numPassengers,const int *seatRow, const char *seatCol);
    string* getseatplans();
 
};





#endif /* Flight_h */


