//
//  Course.cpp
//  srs201
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//

#include "Course.hpp"

#include <iostream>
//ZEYNEP_ZIYAGIL_CS201_HW1
using namespace std;
Course::Course(int id,string title) {
    setID(id);
    setTitle(title);
    }

Course::Course() {
    setID(0);
    setTitle("");
}



void Course::setID(int theid) {
        id = theid;
    }
void Course::setTitle(string thetitle){
    title = thetitle;
}
int Course::getID() {
    return id;
}
string Course::getTitle() {
    return title;
}




