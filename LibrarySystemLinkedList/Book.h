//
//  Book.h
//  hw3_B
//
//  Created by Zeynep Büsra Ziyagil on 16.12.2020.
//
#include <string>
#ifndef Book_h
#define Book_h
/* • In addition, implement a class named Book. Each book is represented by its id, title, and year.
 Do not forget to implement all necessary functions (for example, the constructor and set/get
 functions) for this class. The interface for this class must be written in a file named Book.h and
 its implementation must be written in a file named Book.cpp. This class must be used in your
 implementation of the LibrarySystem class.*/
using namespace std;

class Book{
    public:
        Book( const int = 0, const string = "",const int=0);
        
        void setId(const int sid);
        void setTitle(const string title);
    void setYear(const int year);
    int getID() const;
    string getTitle() const;
    int getYear()const;
    void setStdId(const int stid);
    int getStdID() const;
    private:
        int sid;
        int year;
        string title;
        int stdID;
};

#endif /* Book_h */
