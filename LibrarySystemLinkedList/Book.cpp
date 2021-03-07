//
//  Book.cpp
//  hw3_B
//
//  Created by Zeynep Büsra Ziyagil on 16.12.2020.
//

#include <stdio.h>
#include "Book.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


Book::Book( const int theid, const string title,const int year){
    setId(theid);
    setTitle( title);
    setYear( year);
    setStdId(0);
    
}
        
void Book::setId(const int id){
    sid=id;
}
void Book::setTitle(const string thetitle){
    title=thetitle;
}
void Book::setYear(const int theyear){
    year=theyear;
}
void Book::setStdId(const int stid){
    stdID = stid;
    
}
int Book::getStdID() const{
    return stdID;
}
int Book::getID() const{
    return sid;
}
string Book::getTitle() const{
    return title;
}
int Book::getYear()const{
    return year;
}
    
