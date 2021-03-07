//
//  Student.hpp
//  srs201
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>

#include <string>
#include "Course.hpp"
#include <string>
//ZEYNEP_ZIYAGIL_CS201_HW1

using namespace std;

class Student {

public:
    Student(int id, string firstname, string lastname);
    Student();
    ~Student();
    Student& operator=(const Student& std);
    void setID(int theid);
    void setfirstname(string thefirstname);
    void setlastname(string thelastname);
    int getID();
    string getfirstname();
    string getlastname();
    void setStudentCourseSize(int thesize);
    int getstudentCourseSize();
    Course* getStudentCourses();
    bool addStudentCourse(int courseId, string courseName);
    void setStudentCourses(int size, Course* arr);

private:

    int id;
    string firstname;
    string lastname;
    Course* studentcourses;
    int studentCourseSize;
};

#endif /* Student_hpp */
