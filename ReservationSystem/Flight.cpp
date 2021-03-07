//
//  Flight.cpp
//  cs201prj
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//21802646

#include <stdio.h>
#include "Reservation.h"
#include "Flight.h"
#include <iomanip>
#include <locale>
#include <string>
#include <iostream>
#include<sstream>
using namespace std;
/*
    int flightNo;
    int rowNo;
    int seatNo;
    int pnumber=seatNo * rowNo;
    int availableseats;
    Reservation * reservationcodes;
    int reservationcodenum;
    string * seatplans;
*/
  
    Flight::Flight(  int flightNo,  int rowNo,  int seatNo ){
        setFlightNo(flightNo);
        setRowNo(rowNo);
        setSeatNo(seatNo);
        pnumber = seatNo * rowNo;
        setavailableseats(pnumber);
        reservationcodenum = 0;
        reservationflight =NULL;
        seatplans = new string[pnumber];
        for(int i =0; i<pnumber;i++)
        {seatplans[i] = "o";}
    }
    Flight::Flight(){
        setFlightNo(0);
        setRowNo(0);
        setSeatNo(0);
        pnumber = 0;
        setavailableseats(0);
        reservationcodenum = 0;
        reservationflight =NULL;
        seatplans = NULL;
        
    }
    Flight::~Flight(){
     if(reservationflight != NULL)
        {
            delete[] reservationflight;
            
        }
       if(seatplans != NULL)
        {delete[] seatplans;}
      
    }

Flight& Flight::operator=( const Flight& flt)
{
  
  if (&flt != this){
  setFlightNo(flt.flightNo);
  setRowNo(flt.rowNo);
  setSeatNo(flt.seatNo);
  pnumber = flt.seatNo * flt.rowNo;
  setavailableseats(flt.availableseats);
  reservationcodenum = flt.reservationcodenum;
  if(flt.reservationflight != NULL)
      {
         reservationflight = new Reservation[flt.reservationcodenum];
          for (int i = 0; i < flt.reservationcodenum; i++)
          {
              reservationflight[i] = flt.reservationflight[i];
          }
      }
      else
      {
          reservationflight = NULL;
      }
      
      
  if(flt.seatplans != NULL)
  {
     seatplans = new string[flt.pnumber];
      for (int i = 0; i < flt.pnumber; i++)
      {
          seatplans[i] = flt.seatplans[i];
      }
  }
  else
  {
      seatplans = NULL;
  }
 
  }
    return *this;
 }
    int Flight::getFlightNo(){  
        return flightNo;
    }
    void Flight::setFlightNo(int a){
        flightNo=a;
    }
    int Flight::getRowNo(){
        return rowNo;
    }
    void Flight::setRowNo(int a){
        rowNo =a;
    }
    int Flight::getSeatNo(){
        return seatNo;
    }
    void Flight::setSeatNo(int a){
        seatNo=a;
    }
    int Flight::getpnumber(){
        return pnumber;
    }
    void Flight::setpnumber(int n){
        pnumber=pnumber +n;
    }
    void Flight::setavailableseats(int num){
        availableseats =num;
    }
    int Flight::getavailableseats(){
        
        return availableseats;
    }
    int Flight::getreservationcodenum(){
        return reservationcodenum;
    }
    void Flight::setreservationcodenum(int n){
        reservationcodenum=reservationcodenum+n;
    }
    Reservation* Flight::getreservationflight(){
        return reservationflight;
    }
    void Flight::addreservationflight(int thereservationcode,int thereservationsize,int theflightno,const int* row,const char* column){
        bool exist = false;
        string existingseats;
        int isare=0;
        if (getpnumber() > 0)
        {
            for (int i = 0; i < pnumber; i++)
            {
                for(int j=0;j<thereservationsize;j++)
                {
                	
               	string s(1,column[j]); //convert char to string
				stringstream ss;//convert int to string
				ss<<row[j];
				string name = ss.str() +s ;//create name	
                 string x = name;
                
                    if(getseatplans()[i]== x){
                    
                        exist = true;
                        existingseats += x + " ";
                        isare++;
                    }
                }
               
            }
        }
    


        if (!exist )
        {
            reservationcodenum ++;

            Reservation* arr = new Reservation[reservationcodenum];
            for (int i = 0; i < reservationcodenum - 1; i++) {
                arr[i] = reservationflight[i];
            }
            arr[reservationcodenum - 1] = Reservation( thereservationcode, thereservationsize,theflightno, row, column);
            ////////////////////////////////////
          
            modifyseatings(thereservationsize, row, column);
/////////////////////////////////////
            delete [] reservationflight;
            reservationflight = new Reservation[reservationcodenum ];

            for (int i = 0; i < reservationcodenum; i++)
            {
                reservationflight[i] = arr[i];
            }
            delete[] arr;
        }
        else
        {
            if(isare ==1)
            cout<< existingseats <<"is not available"<< "\n";
            else{
                cout<< existingseats <<"are not available"<< "\n";
            }
            
        }
        
        
    }
void Flight::deletereservationflight(int code){
        bool exist =false;
        int deletepoint = 0;
        for(int i =0;i<reservationcodenum;i++)
        {
            if(getreservationflight()[i].getreservationcode()==code)
            {
                exist = true;
                deletepoint = i;
                break;
            }
                
        }
        if(exist){
            setavailableseats(getavailableseats() +reservationflight[deletepoint].getreservationsize());
            for(int x =0;x<reservationflight[deletepoint].getreservationsize();x++)
            {
            
            for(int i =0;i<pnumber;i++)
            {
                if(seatplans[i]  == reservationflight[deletepoint].getseats()[x])
                {
                    seatplans[i]= "o";
                }
                    
            }
                
            }
         
            Reservation* arrs = new Reservation[reservationcodenum];
            int j = 0;
            while(j < reservationcodenum )
            {
                
                if (j == deletepoint)
                {
                    

                }
                if (j < deletepoint)
                {
                    arrs[j] = reservationflight[j];
                    
                }
                
                if(j > deletepoint){
                    arrs[j-1] = reservationflight[j];
                    
                }
                
                
                j++;
            }
            reservationcodenum--;
            
            delete[] reservationflight;
            
            
            reservationflight = new Reservation[reservationcodenum];
            
            for (int i = 0; i < reservationcodenum ; i++)
            {
                reservationflight[i] = arrs[i];
            }
            
            delete[] arrs;
            
        
           
            
        }
        else
        {
            cout<< "Reservation "<< code<<" does not exist in flight "<< getFlightNo()<< "\n";
            
        }
        
    }

    void Flight::modifyseatings( int numPassengers,const int *seatRow, const char *seatCol){
 
        setavailableseats(getavailableseats()-numPassengers);
        int seatindex = 0;
        char* alphabet = new char[26];
        for (char c = 'A'; c <= 'Z'; c++) {
            alphabet[c - 'A'] = c;
        }
            
        for(int j =0;j<numPassengers;j++)
        {
            for(int a = 0; a< 26;a++)
            {
               if( alphabet[a] == seatCol[j])
               {
                   seatindex= a;
               }
                
            }
        		string s(1,seatCol[j]); //convert char to string
				stringstream ss;//convert int to string
				ss<< seatRow[j];
				string name = ss.str() +s ;//create name	
		   		 
        
           seatplans[(seatRow[j]-1)*getSeatNo()+seatindex] = name;
        }
        
        
        delete[] alphabet;
    }

    string* Flight::getseatplans(){
        return seatplans;
    }
 

