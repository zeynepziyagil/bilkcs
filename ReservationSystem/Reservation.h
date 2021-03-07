//
//  Reservaiton.h
//  cs201prj
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//21802646

#ifndef Reservation_h
#define Reservation_h
#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <locale>
#include<sstream>

using namespace std;
class Reservation{
private:
    int reservationcode;
    int reservationsize;
    int flightno;
    string* seats;
    
public:
    Reservation(int thereservationcode,int thereservationsize,int theflightno,const int* row,const char* column);
    Reservation();
    ~Reservation();
    Reservation&operator=(const Reservation& rs);//assignment operator
    int getreservationcode();
    void setreservationcode(int thereservationcode);
    int getreservationsize();
    void setreservationsize(int thereservationsize);
    int getflightno();
    void setflightno(int theflightno);
    string* getseats();
    string seatstring();
  
    
    
};

#endif /* Reservation_h */
