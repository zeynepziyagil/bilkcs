//
//  ReservationSystem.cpp
//  cs201prj
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//21802646

#include <stdio.h>
#include "ReservationSystem.h"
#include "Reservation.h"
#include "Flight.h"
#include <iomanip>
#include <locale>
#include <iostream>
#include<sstream>
using namespace std;
ReservationSystem::ReservationSystem(){
    flightlist= NULL;
    reservationlist = NULL;
    reservationlistsize=0;
    flightlistsize =0;
    
    
}
ReservationSystem::~ReservationSystem(){
    if (flightlist != NULL)
    {
        delete[]flightlist;
    }
    if (reservationlist != NULL)
    {
        delete[]reservationlist;
    }
    
    
}

/*Add a flight: The reservation system will allow the user to add a new flight indicating its flight number, the number of rows in its aircraft, and the number of seats in its rows. Since the flight numbers should be unique within the system, you should check whether a flight with the same number exists. If it does, you should not allow the operation and display a warning message. You should also check if the number of rows in its aircraft, and the number of seats are positive. Otherwise, you should add the flight and display a message. At the time of adding a flight, you should allocate its seats all of which should be available for reservation. (Please see the code given below and its output for the format of the output.)
*/ 
void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo )
{
    bool exist = false;
    for (int i = 0; i < flightlistsize; i++)
    {
        
        if (flightlist[i].getFlightNo() == flightNo)
        {
            exist = true;
            cout << "Flight" << flightNo << " already exists" << "\n";
            break;
        }

    }
    bool positivecheck = true;
    if(rowNo<1 || seatNo<1)
    {
        cout<<"At the time of adding a flight, you should allocate its seats all of which should be available for reservation."<< "\n";
        positivecheck =false;
    }
    
    if (!exist && positivecheck )
    {
        flightlistsize += 1;

        Flight* arr = new Flight[flightlistsize];
        for (int i = 0; i < flightlistsize - 1; i++) {
            arr[i] = flightlist[i];
        }
        

        delete[] flightlist;
        //fligthsize + - maybe
        flightlist = new Flight[flightlistsize];
        
        for (int i = 0; i < flightlistsize-1 ; i++)
        {
            flightlist[i] = arr[i];
        }
        
        delete[] arr;
        flightlist[flightlistsize-1] = Flight(flightNo, rowNo, seatNo);
        cout<<"Flight "<<flightNo<<" has been added"<< "\n";
    
    }

    
    
}


void ReservationSystem::cancelFlight( const int flightNo ){
    bool exist =false;
    int deletefrom =0;
    for(int i =0;i<flightlistsize;i++)
    {
        if(flightlist[i].getFlightNo() == flightNo)
        {exist=true;
        deletefrom=i;
        break;
        }
    }
   
    if(!exist)
    {
        cout<<"Flight "<< flightNo <<" does not exist"<< "\n";
    }
    else
    {
        for(int m = 0;m<flightlist[deletefrom].getreservationcodenum();m++)
        {
            int resCode = flightlist[deletefrom].getreservationflight()[m].getreservationcode();
            //cancelReservation(resCode);
            bool exist = false;
            int cancelpoint=0;
            for(int x =0;x<reservationlistsize;x++)
            {
                if(reservationlist[x].getreservationcode()== resCode)
                {
                    exist = true;
                    cancelpoint = x;
                    break;
                }
            }
            if(exist)
            {
                string seatstoprint =reservationlist[cancelpoint].seatstring();
                int fltnum =reservationlist[cancelpoint].getflightno();
                for(int f =0;f<flightlistsize;f++)
                {
                    if(flightlist[f].getFlightNo() == fltnum)
                    {
                        flightlist[f].deletereservationflight(resCode);
                    }
                }
                
                
                Reservation* arrs = new Reservation[reservationlistsize];
                int j = 0;
                while(j < reservationlistsize )
                {
                    
                    if (j == cancelpoint)
                    {
                        

                    }
                    if (j < cancelpoint)
                    {
                        arrs[j] = reservationlist[j];
                        
                    }
                    
                    if(j > cancelpoint){
                        arrs[j-1] = reservationlist[j];
                        
                    }
                    
                    
                    j++;
                }
                reservationlistsize--;
                
                delete[] reservationlist;
                
                
                reservationlist = new Reservation[reservationlistsize];
                
                for (int i = 0; i < reservationlistsize ; i++)
                {
                    reservationlist[i] = arrs[i];
                }
                
                delete[] arrs;
                
                
            }
            
            
        }
        
        
        Flight* arrs = new Flight[flightlistsize];
        int j = 0;
        while(j < flightlistsize )
        {
            
            if (j == deletefrom)
            {
                

            }
            if (j < deletefrom)
            {
                arrs[j] = flightlist[j];
                
            }
            
            if(j > deletefrom){
                arrs[j-1] = flightlist[j];
                
            }
            
            
            j++;
        }
        flightlistsize--;
        
        delete[] flightlist;
        
        
        flightlist = new Flight[flightlistsize];
        
        for (int i = 0; i < flightlistsize ; i++)
        {
            flightlist[i] = arrs[i];
        }
        
        delete[] arrs;
        
        
        cout<<"Flight " <<flightNo<<" and all of its reservations are canceled"<< "\n";
        
    }
    
    
}

void ReservationSystem::showAllFlights(){
    if(flightlistsize ==0)
    { cout<<"No flights exist"<< "\n";}
    else
    {
        cout<< "Flights currently operated:\n";
        for (int a=0; a<flightlistsize; a++) {
            cout<< "Flight "<< flightlist[a].getFlightNo()  <<" (" << flightlist[a].getavailableseats() << " available seats)"<< "\n";
        }
                
    }
    
}/*The reservation system will allow the user to enter a flight number and see the availability of its seats. If there exists no flight with the
  
  specified number, you should display a warning message. If the flight exists, you should display the seats in the following format where “o” represents an available seat and “x” represents an occupied seat. Note that in the example below, the aircraft has 5 rows and 6 seats in each of its rows.*/
void ReservationSystem::showFlight( const int flightNo )
{
    ///char * col = new char[6]{'A','B','C','D','E','F'};
        /////
	//	int seatindex = 0;
        char* alphabet = new char[26];
        for (char c = 'A'; c <= 'Z'; c++) {
            alphabet[c - 'A'] = c;
        }

    
    ///////
    
    
    bool contain =false;
    int showp= 0;
    for(int  i=0;i<flightlistsize;i++)
    {
        if(flightlist[i].getFlightNo()== flightNo)
        {
            contain = true;
            showp = i;
            break;
        }
        
    }
    if(contain)
    {
        cout<< "Flight " <<flightNo<<" has "<< flightlist[showp].getavailableseats()<<" available seats"<< "\n";
        int pnumberfor = 0;
        for(int k =0;k< flightlist[showp].getSeatNo();k++)
        {cout<< alphabet[k]<<" ";}
        int fornum = flightlist[showp].getpnumber() /flightlist[showp].getSeatNo();
        for(int r =0;r<fornum;r++)
        {
            cout<<"\n"<<(r+1)<<" ";
            for(int t =0;t <flightlist[showp].getSeatNo();t++)
            {
                /*if(pnumberfor == flightlist[showp].getpnumber())
                {
                    break;
                }*/
                if(flightlist[showp].getseatplans()[pnumberfor] =="o")
                {cout<< "o ";}
                else{cout<<"x ";}
                pnumberfor++;
            }
            
        }
        
        cout<< "\n";
        
        
    }
    else
    {
        cout<< "Flight "<< flightNo <<" does not exist"<< "\n";
        
    }
    
      
        delete[] alphabet;
    
}

/*
 This function makes a reservation only if the flight with a specified number exists and all of the selected seats are available. If there exists no flight with the specified number, you should display a warning message. Likewise, if even one of the selected seats is not available, you should display a warning message and return the error code -1.
 If the flight exists and all of the selected seats are available, you should make this reservation by creating a unique reservation code, and by reserving the selected seats under this code. The reservation code should be unique not only for the specified flight but also for the entire reservation system. Thus, by using only this reservation code, you should identify the flight as well as the seats reserved under this code.
*/
int ReservationSystem::makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol ){
    bool flightexist= false;
    int showp= 0;
    for(int  i=0;i<flightlistsize;i++)
    {
        if(flightlist[i].getFlightNo()== flightNo)
        {
            flightexist= true;
            showp = i;
            break;
        }
        
    }
    
    bool seatexist=false;
   
    
         for (int i = 0; i < flightlist[showp].getpnumber(); i++)
         {
             
             for(int j=0;j<numPassengers;j++)
             {
                 
            	string s(1,seatCol[j]); //convert char to string
				stringstream ss;//convert int to string
				ss<<seatRow[j];
				string name = ss.str() +s ;//create name	
                 string x = name;
                 if(flightlist[showp].getseatplans()[i]== x){
                    
                     seatexist = true;
     break;
                 }
             }
             
     if(seatexist)
     {break;}
         }
    
    if(!seatexist && flightexist)
    {
        reservationlistsize += 1;

        Reservation* arr = new Reservation[reservationlistsize];
        for (int i = 0; i < reservationlistsize - 1; i++) {
            arr[i] = reservationlist[i];
        }
        

        delete[] reservationlist;
        //fligthsize + - maybe
        reservationlist = new Reservation[reservationlistsize];
        
        for (int i = 0; i < reservationlistsize-1 ; i++)
        {
            reservationlist[i] = arr[i];
        }
        
        delete[] arr;
        int codet = reservationlistsize-1;
        reservationlist[reservationlistsize-1] = Reservation(codet, numPassengers, flightNo, seatRow, seatCol);
        flightlist[showp].addreservationflight(codet, numPassengers,flightNo,seatRow,seatCol);
    
        return codet;
        
        
    }
    
    
    else
    {
        if(!flightexist)
        {
            cout<<"Flight "<<flightNo<<" does not exist"<< "\n";
        }
        if(seatexist)
        {
    
            flightlist[showp].addreservationflight(reservationlistsize-1, numPassengers,flightNo,seatRow,seatCol);
        
        }
        return -1;
        
    }
   
}

void ReservationSystem::cancelReservation( const int resCode ){
    bool exist = false;
    int cancelpoint=0;
    for(int x =0;x<reservationlistsize;x++)
    {
        if(reservationlist[x].getreservationcode()== resCode)
        {
            exist = true;
            cancelpoint = x;
            break;
        }
    }
    if(exist)
    {
        string seatstoprint =reservationlist[cancelpoint].seatstring();
        int fltnum =reservationlist[cancelpoint].getflightno();
        for(int f =0;f<flightlistsize;f++)
        {
            if(flightlist[f].getFlightNo() == fltnum)
            {
                flightlist[f].deletereservationflight(resCode);
            }
        }
        
        
        Reservation* arrs = new Reservation[reservationlistsize];
        int j = 0;
        while(j < reservationlistsize )
        {
            
            if (j == cancelpoint)
            {
                

            }
            if (j < cancelpoint)
            {
                arrs[j] = reservationlist[j];
                
            }
            
            if(j > cancelpoint){
                arrs[j-1] = reservationlist[j];
                
            }
            
            
            j++;
        }
        reservationlistsize--;
        
        delete[] reservationlist;
        
        
        reservationlist = new Reservation[reservationlistsize];
        
        for (int i = 0; i < reservationlistsize ; i++)
        {
            reservationlist[i] = arrs[i];
        }
        
        delete[] arrs;
        
        
        
        
        
        
       cout<< "Reservation for the seats "<<seatstoprint<<" is canceled in Flight "<<fltnum<< "\n";
        
    }
    else
    {
        cout<< "No reservations are found under Code " <<resCode<< "\n";
    }
    
    
}


void ReservationSystem::showReservation( const int resCode )
{
    
    bool exist = false;
    int showpoint=0;
    
    for(int x =0;x<reservationlistsize;x++)
    {
        
        if(reservationlist[x].getreservationcode()== resCode)
        {
            exist = true;
            showpoint = x;
            break;
        }
    }
        
    if(exist)
    {   string x;
        for(int i =0;i<reservationlist[showpoint].getreservationsize();i++)
        {
            x += reservationlist[showpoint].getseats()[i] +" ";
            
        }
        
        cout<< "Reservations under Code "<< resCode<<
        " in Flight "<<reservationlist[showpoint].getflightno()<<
        ": "<<x<< "\n";

    }
    else
    {
        
        cout<< "No reservations under Code " <<resCode<< "\n";
    }
     
}
// ...

