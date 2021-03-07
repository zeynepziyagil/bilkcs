//
//  Reservation.cpp
//  cs201prj
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//21802646

#include <stdio.h>
#include "Reservation.h"
#include <sstream>
#include <iostream>
#include <string>


using namespace std;

    Reservation:: Reservation(int thereservationcode,int thereservationsize,int theflightno,const int* row,const char* column){
        
        setreservationcode(thereservationcode);
        setreservationsize(thereservationsize);
        setflightno(theflightno);
        if(thereservationsize!=0)
        {  
        
        
           seats = new string[thereservationsize];
        for(int i=0;i<thereservationsize;i++)
            {
            	string s(1,column[i]); //convert char to string
				stringstream ss;//convert int to string
				ss<<row[i];
				string name = ss.str() +s ;//create name	
		   		seats[i] =  name ;
			}
        
        }
        else{seats=NULL;}
    }
    Reservation::Reservation(){
        setreservationcode(0);
        setreservationsize(0);
        setflightno(0);
        seats=NULL;
    }
    Reservation::~Reservation(){
      if(seats != NULL)
           delete[] seats;
    }
    Reservation&Reservation::operator=(const Reservation& rs)
    {
        setreservationcode(rs.reservationcode);
        setreservationsize(rs.reservationsize);
        setflightno(rs.flightno);
        if(rs.seats!=NULL)
        {
            seats = new string[rs.reservationsize];
             for (int i = 0; i < rs.reservationsize; i++)
             {
                 seats[i] = rs.seats[i];
             }
        }
        else{seats=NULL;}
       
        return *this;
    }


    int Reservation::getreservationcode(){
        return reservationcode;
        
    }
    void Reservation::setreservationcode(int thereservationcode){
        reservationcode=thereservationcode;
        
    }
    int Reservation::getreservationsize(){
        return reservationsize;
    }
    void Reservation::setreservationsize(int thereservationsize){
        reservationsize = thereservationsize;
    }
    int Reservation::getflightno(){
        return flightno;
    }
    void Reservation::setflightno(int theflightno){
        flightno=theflightno;
    }
    string* Reservation::getseats(){
        return seats;
    }
    string Reservation::seatstring()
    {
        string x;
        for(int i =0;i<getreservationsize();i++)
        {
            x += seats[i] +" ";
            
        }
        return x;
        
    }
  
    
    
