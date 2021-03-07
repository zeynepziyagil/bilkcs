#ifndef REGISTRATIONSYSTEM
#define REGISTRATIONSYSTEM

#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"


using namespace std;

class RegistrationSystem {

public:
    RegistrationSystem();
    ~RegistrationSystem();
    void addStudent(const int studentId, const string firstName, const string lastName);
    void deleteStudent(const int studentId);
    void addCourse(const int studentId, const int courseId, const string courseName);
    void withdrawCourse(const int studentId, const int courseId);
    void cancelCourse(const int courseId);
    void showStudent(const int studentId);
    void showCourse(const int courseId);
    void showAllStudents();
    void sortList(Student*&list);


private:
    int studentsize;
    int coursesize;
    Student* studentlist;
    Course* courselist;
    
};
#endif
