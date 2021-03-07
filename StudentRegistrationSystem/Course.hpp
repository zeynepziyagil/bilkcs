//
//  Course.hpp
//  srs201
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//

#ifndef Course_hpp
#define Course_hpp

#include <stdio.h>

#include <string>
//ZEYNEP_ZIYAGIL_CS201_HW1

using namespace std;
class Course {

private:
    int id;
    string title;

public:
    Course();
    Course(int id, string title);
    void setID(int theid);
    void setTitle(string thetitle);
    int getID();
    string getTitle();

};


#endif /* Course_hpp */
