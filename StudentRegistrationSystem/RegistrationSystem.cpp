#include <iostream>
#include "RegistrationSystem.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include <iomanip>
#include <locale>

RegistrationSystem::RegistrationSystem() {
    studentlist = NULL;
    courselist = NULL;

    studentsize = 0;
    coursesize = 0;
}


RegistrationSystem::~RegistrationSystem()
{
    if (courselist != NULL)
    {
        delete[]courselist;
    }
    if(studentlist != NULL)
    {delete[]studentlist; }
}


/*Add a student: The registration system will allow to add a new student indicating her/his student
id, rst name, and last name. Since the student ids are unique positive integers, the system should check
whether or not the specied student id already exists (i.e., whether or not it is the id of an existing
student), and if the student id exists, it should not allow the operation and display a warning message.
Moreover, if the rst name or the last name are empty, it should not allow the operation and display a
warning message. The array must remain sorted by student id after this operation.
*/
void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
    bool exist = false;
    for (int i = 0; i < studentsize; i++)
    {
        
        if (studentlist[i].getID() == studentId)
        {
            exist = true;
            cout << "Student " << studentId << " already exists" << "\n";
            break;
        }

    }
    
    if (firstName == "" || lastName == "") {
        exist = true;

        cout << "Student has to have a full name!" << "\n";

    }
    
    if (!exist)
    {
        studentsize += 1;

        Student* arr = new Student[studentsize];
        for (int i = 0; i < studentsize - 1; i++) {
            arr[i] = studentlist[i];
        }
        

        delete[] studentlist;
        
        studentlist = new Student[studentsize+1];
        
        for (int i = 0; i < studentsize - 1; i++)
        {
            studentlist[i] = arr[i];
        }
        
        delete[] arr;
        
        //sortList(studentlist);
        studentlist[studentsize - 1] = Student(studentId, firstName, lastName);
        cout << "Student " << studentId << " has been added\n";
        sortList(studentlist);
    }


}

/*Delete a student: The registration system will allow to delete an existing student indicating her/his
student id. If the student does not exist (i.e., if there is no student with the specied id), the system
should display a warning message. Note that this operation will also drop all courses in which the student
was enrolled.*/
void RegistrationSystem::deleteStudent(const int studentId)
{

    bool exist = false;
    int deletepoint = 0;
    if (studentsize == 0)
    {
        cout << "Student list is empty!" << "\n";

    }
    else
    {
        for (int i = 0; i < studentsize; i++)
        {
            if (studentlist[i].getID() == studentId)
            {
                exist = true;
                deletepoint = i;
                break;
            }

        }

        
        if (!exist) {
            cout << "Student " << studentId << " does not exist" << "\n";
        }
        else
        {
            
            
            Student* arrs = new Student[studentsize];
            int j = 0;
            while(j < studentsize )
            {
                
                if (j == deletepoint)
                {
                    

                }
                if (j < deletepoint)
                {
                    arrs[j] = studentlist[j];
                    
                }
                
                if(j > deletepoint){
                    arrs[j-1] = studentlist[j];
                    
                }
                
                
                j++;
            }
            studentsize--;
            
            delete[] studentlist;
            
            
            studentlist = new Student[studentsize];
            
            for (int i = 0; i < studentsize ; i++)
            {
                studentlist[i] = arrs[i];
            }
            
            delete[] arrs;
            
            
            cout << "Student " << studentId << " has been deleted" << "\n";

        }
    }
}
/*Add a course for a student: The registration system will allow to add a new course for a particular
student. For that, the student id, the course id, and the course name have to be specied. The system
should check whether or not this student exists; if she/he does not, it should prevent to add a course and
display a warning message. If the student exists and the student is not already enrolled in this course,
the given course is added to student's course array. If the student is already enrolled in this course, it
should display an appropriate message and the given course should not be added again. The courses are
stored unsorted.*/
void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName) {
    bool stdexist = false;
    int studentindex = 0;
    for (int i = 0; i < studentsize; i++)
    {
        if (studentlist[i].getID() == studentId)
        {
            stdexist = true;
            studentindex = i;
            break;
        }

    }
    if (stdexist) {
        bool courseexist = false;
        for (int i = 0; i < coursesize; i++)
        {
            if (courselist[i].getID() == courseId)
            {
                courseexist = true;
                break;
            }
        }
        if (!courseexist)
        {
            

            coursesize += 1;

            Course* arr = new Course[coursesize];
            for (int i = 0; i < coursesize - 1; i++) {
                arr[i] = courselist[i];
            }


            delete[] courselist;
            courselist = new Course[coursesize + 1];

            for (int i = 0; i < coursesize - 1; i++)
            {
                courselist[i] = arr[i];
            }
            delete[] arr;


            courselist[coursesize - 1] = Course(courseId, courseName);
            if (studentlist[studentindex].addStudentCourse(courseId, courseName))
            {
                cout << "Course " << courseId << " has been added to student " << studentId << "\n";
            }
            else {
                cout << "Student " << studentId << " is already enrolled in course " << courseId << "\n";
            }


        }
        else {
            if (studentlist[studentindex].addStudentCourse(courseId, courseName))
            {
                cout << "Course " << courseId << " has been added to student " << studentId << "\n";
            }
            else {
                cout << "Student " << studentId << " is already enrolled in course " << courseId << "\n";
            }


        }

    }
    else
    {
        cout << "Student " << studentId << " does not exist, system cannot add course!\n";

    }

}

/*The registration system will allow to delete an existing course
indicating its course id from a student's course enrollment array. If the student does not exist (i.e., if
there is no student with the specied id) or the student is not enrolled in this course (i.e., if there is no
course with the specied id), the system should display a warning message.*/
void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {

    bool courseexist = false;
    for (int i = 0; i < coursesize; i++)
    {
        if (courselist[i].getID() == courseId)
        {
            courseexist = true;
            break;
        }

    }


    int stdindex = 0;
    bool stexist = false;
    for (int i = 0; i < studentsize; i++)
    {

        if (studentlist[i].getID() == studentId)
        {
            stdindex = i;
            stexist = true;
            break;
        }

    }
    if (stexist)
    {
        bool message = false;
        bool a = false;
        int b = studentlist[stdindex].getstudentCourseSize();
        bool ifx = false;
        for (int j = 0; j < b; j++)
        {

            if (studentlist[stdindex].getStudentCourses()[j].getID() == courseId)
            {
                ifx = true;
                
            }

        }
        if (ifx) {
        Course* arrc = new Course[b - 1];
        for (int j = 0; j < b; j++)
        {
            
            if (studentlist[stdindex].getStudentCourses()[j].getID() == courseId)
            {
                a = true;
                message = true;
                int newsize = studentlist[stdindex].getstudentCourseSize() - 1;;
                studentlist[stdindex].setStudentCourseSize(newsize);


            }
            else {
                if (a)
                {

                    arrc[j - 1] = studentlist[stdindex].getStudentCourses()[j];
                }
                else
                {
                    arrc[j] = studentlist[stdindex].getStudentCourses()[j];
                }
            }
        }
        

            studentlist[stdindex].setStudentCourses(b - 1, arrc);

            delete[] arrc;
        }



        if (message)
        {
            cout << "Student " << studentlist[stdindex].getID() << " has been withdrawn from course " << courseId << "\n";

            if (courseexist) {
                bool isCourseStillEnrolled = false;
                for (int i = 0; i < studentsize; i++)
                {

                    for (int j = 0; j < studentlist[i].getstudentCourseSize(); j++)
                    {
                        if (studentlist[i].getStudentCourses()[j].getID() == courseId)
                        {
                            isCourseStillEnrolled = true;
                            break;
                        }

                    }
                }
                if (!isCourseStillEnrolled)
                {
                    coursesize--;
                    Course* arra = new Course[coursesize];
                    bool n = false;
                    for (int i = 0; i <= coursesize; i++)
                    {

                        if (n)
                        {
                            arra[i - 1] = courselist[i];
                        }
                        else
                        {
                            arra[i] = courselist[i];
                        }

                        if (courselist[i].getID() == courseId)
                        {
                            n = true;

                        }


                    }
                    delete[] courselist;
                    courselist = new Course[coursesize];

                    for (int i = 0; i < coursesize; i++)
                    {
                        courselist[i] = arra[i];
                    }
                    delete[] arra;


                }
            }
        }
        else
        {
            cout << "Student " << studentlist[stdindex].getID() << " is not enrolled in course " << courseId << "\n";
        }




    }
    else
    {
        cout << "Student " << studentId << " does not exist, system cannot withdraw course!\n";
    }



}

/*Cancel a course: The registration system will allow to delete an existing course indicating its course
id. Note that this operation will remove the course from the course enrollment arrays for all students.
If the course does not exist (i.e., if there is no course with the specied id), the system should display a
warning message.*/
void RegistrationSystem::cancelCourse(const int courseId)
{
    bool courseexist = false;
    int a = coursesize;
    for (int i = 0; i < a; i++)
    {
        if (courselist[i].getID() == courseId)
        {
            courseexist = true;
            break;

        }
        
    }
    if (courseexist)
    {
        coursesize--;
        Course* arra = new Course[coursesize];
        bool n = false;
        for (int i = 0; i <= coursesize; i++)
        {

            if (n)
            {
                arra[i - 1] = courselist[i];
            }
            else
            {
                arra[i] = courselist[i];
            }

            if (courselist[i].getID() == courseId)
            {
                n = true;

            }


        }
        delete[] courselist;
        courselist = new Course[coursesize];

        for (int i = 0; i < coursesize; i++)
        {
            courselist[i] = arra[i];
        }
        delete[] arra;


    }


    if (courseexist)
    {
        for (int i = 0; i < studentsize; i++)
        {
            
            
            bool ifx = false;
            int b = studentlist[i].getstudentCourseSize();
            
            for (int j = 0; j < b; j++)
            {
                
                if (studentlist[i].getStudentCourses()[j].getID() == courseId)
                {
                    ifx = true;
                    break;
                }

            }
            if (ifx) {
                bool a = false;
                
                Course* arrc = new Course[b - 1];
                for (int j = 0; j < b; j++)
                {
                    
                    if (studentlist[i].getStudentCourses()[j].getID() == courseId)
                    {
                        a = true;
                        
                        int newsize = studentlist[i].getstudentCourseSize() - 1;;
                        studentlist[i].setStudentCourseSize(newsize);
                        

                    }
                    else {

                        if (a)
                        {

                            arrc[j - 1] = studentlist[i].getStudentCourses()[j];
                        }

                        else
                        {
                            arrc[j] = studentlist[i].getStudentCourses()[j];
                        }
                    }

                }

                studentlist[i].setStudentCourses(b - 1, arrc);

                delete[] arrc;
            }

        }
        cout << "Course " << courseId << " has been cancelled\n";
    }
    else
    {
        cout << "Course " << courseId << " does not exist!\n";

    }




}
/*Show detailed information about a particular student: The registration system will allow to
specify a student id and display detailed information about that particular student. This information
includes the student id, the student name, the list of courses enrolled by this student including the course
id and the course name for each course. If the student does not exist (i.e., if there is no student with the
specied student id), the system should display a warning message.*/
void RegistrationSystem::showStudent(const int studentId)
{
    int stdindex = 0;
    bool stexist = false;
    for (int i = 0; i < studentsize; i++)
    {
        if (studentlist[i].getID() == studentId)
        {
            stdindex = i;
            stexist = true;
            break;
        }
    }
    if (stexist)
    {
        cout << setw(10) << "Student ID" << setw(15) << "Student Name" << setw(19) << "Student Lastname\n";
        cout << setw(10) << studentlist[stdindex].getID() << setw(15) << studentlist[stdindex].getfirstname()
            << setw(19) << studentlist[stdindex].getlastname() << "\n";
        int sizec = studentlist[stdindex].getstudentCourseSize();
        if (sizec != 0)
        {
            cout << setw(19) << "Course Id" << setw(14) << "Course name\n";
            for (int j = 0; j < sizec; j++)
            {
                cout << setw(19) << studentlist[stdindex].getStudentCourses()[j].getID()
                    << setw(14) << studentlist[stdindex].getStudentCourses()[j].getTitle() << "\n";
            }

        }


    }
    else
    {
        cout << "Student " << studentId << " does not exist \n";
    }


}
/*Show detailed information about a particular course: The registration system will allow to
specify a course id and display detailed information about that particular course. This information
includes the course id, the course name, the list of students enrolled in this course including the student
id and the student name for each student. If the course does not exist (i.e., if there is no course with the
specied course id), the system should display a warning message.
*/
void RegistrationSystem::showCourse(const int courseId) {

    bool courseexist = false;
    int courseindex = 0;
    if (coursesize > 0) {
        for (int i = 0; i < coursesize; i++)
        {
            if (courselist[i].getID() == courseId)
            {
                courseexist = true;
                courseindex = i;
                break;
            }

        }
    }

    if (courseexist)
    {
        cout << setw(12) << "Course Id" << setw(12) << "Course name\n";
        cout << setw(12) << courseId << setw(12) << courselist[courseindex].getTitle() << "\n";

        bool ifprinted = false;
        for (int i = 0; i < studentsize; i++)
        {

            for (int j = 0; j < studentlist[i].getstudentCourseSize(); j++)
            {
                if (studentlist[i].getStudentCourses()[j].getID() == courseId)
                {
                    if (!ifprinted)
                    {
                        cout << setw(10) << "Student ID" << setw(15) << "Student Name" << setw(19) << "Student Lastname\n";
                        ifprinted = true;
                    }

                    cout << setw(10) << studentlist[i].getID() << setw(15) << studentlist[i].getfirstname()
                        << setw(19) << studentlist[i].getlastname() << "\n";
                }
            }
        }


    }

    else
    {
        cout << "Course " << courseId << " does not exist!\n";
    }


}
/*
Show the list of all students: The registration system will allow to display a list of all the students.
This list includes the student id, the student name, and the list of courses enrolled by each student.*/
void RegistrationSystem::showAllStudents()
{
    if (studentsize > 0)
    {
        cout << setw(10) << "Student ID" << setw(15) << "Student Name" << setw(19) << "Student Lastname\n";
        for (int i = 0; i < studentsize; i++)
        {
            cout << setw(10) << studentlist[i].getID() << setw(15) << studentlist[i].getfirstname()
                << setw(19) << studentlist[i].getlastname() << "\n";
            int sizec = studentlist[i].getstudentCourseSize();
            if (sizec != 0)
            {
                cout << setw(19) << "Course Id" << setw(14) << "Course name\n";
                for (int j = 0; j < sizec; j++)
                {
                    cout << setw(19) << studentlist[i].getStudentCourses()[j].getID()
                        << setw(14) << studentlist[i].getStudentCourses()[j].getTitle() << "\n";
                }

            }


        }


    }
    else
    {
        cout << "There are no students in the system\n";
    }
}


void RegistrationSystem::sortList(Student*& list)
{
    Student stemp;
    int min;

    for (int i = 0; i < studentsize; i++)
    {
        min = list[i].getID();
        for (int j = i; j < studentsize; j++)
        {
            if (list[j].getID() < min)
            {
                min = list[j].getID();
                stemp = list[i];
                list[i] = list[j];
                list[j] = stemp;
            }
        }


    }
}

