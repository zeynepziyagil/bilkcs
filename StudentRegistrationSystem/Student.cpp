//
//  Student.cpp
//  srs201
//
//  Created by Zeynep Büsra Ziyagil on 4.11.2020.
//

#include "Student.hpp"

#include "Course.hpp"
#include <iostream>
//ZEYNEP_ZIYAGIL_CS201_HW1
using namespace std;


Student::Student(int id, string firstname, string lastname) {
    setID(id);
    setfirstname(firstname);
    setlastname(lastname);
    studentcourses = NULL;
    setStudentCourseSize(0);
}


Student::Student() {
    setID(0);
    studentcourses = NULL;
    setStudentCourseSize(0);

}
Student::~Student() {

    if(studentcourses != NULL)
    delete[] studentcourses;


}

Student& Student::operator=(const Student& std) {


        if (&std != this) {
            setID(std.id);
            setfirstname(std.firstname);
            setlastname(std.lastname);
            setStudentCourseSize(std.studentCourseSize);


            if (std.studentcourses != NULL)
            {
                studentcourses = new Course[std.studentCourseSize];
                for (int i = 0; i < studentCourseSize; i++)
                {
                    studentcourses[i] = std.studentcourses[i];
                }
            }
            else
            {
                studentcourses = NULL;
            }

        }
        return *this;

}



void Student::setID(int theid) {
    id = theid;

}
void Student::setfirstname(string thefirstname) {
    firstname = thefirstname;
}
void Student::setlastname(string thelastname) {
    lastname = thelastname;
}
int Student::getID() {
    return id;
}
string Student::getfirstname() {
    return firstname;
}
string Student::getlastname() {
    return lastname;
}
void Student::setStudentCourseSize(int thesize) {
    studentCourseSize = thesize;
}
int Student::getstudentCourseSize() {
    return studentCourseSize;
}
Course* Student::getStudentCourses()
{
    return studentcourses;
}
void Student::setStudentCourses(int size, Course*arr)
{
    Course* arry = new Course[size];
    for (int i = 0; i < size; i++)
    {
        arry[i] = arr[i];
    }

     delete[] studentcourses;

     studentcourses = new Course[size];
     for (int i = 0; i < size; i++)
     {
         studentcourses[i] = arry[i];
     }

     delete[] arry;

}

bool Student::addStudentCourse(int courseId, string courseName) {
    bool exist = false;
    if (getstudentCourseSize() != 0)
    {
        for (int i = 0; i < getstudentCourseSize(); i++)
        {
            if (studentcourses[i].getID() == courseId)
                exist = true;
            break;
        }
    }


    if (!exist)
    {
        setStudentCourseSize(getstudentCourseSize() + 1);

        Course* arr = new Course[getstudentCourseSize()];
        for (int i = 0; i < getstudentCourseSize() - 1; i++) {
            arr[i] = getStudentCourses()[i];
        }
        arr[getstudentCourseSize() - 1] = Course(courseId, courseName);

        delete [] studentcourses;
        studentcourses = new Course[getstudentCourseSize() + 1];

        for (int i = 0; i < getstudentCourseSize(); i++)
        {
            studentcourses[i] = arr[i];
        }
        delete[] arr;

        return true;
    }
    else
    {
        return false;

    }
}
