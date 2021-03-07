//
//  LibrarySystem.h
//  hw3_B
//
//  Created by Zeynep Büsra Ziyagil on 16.12.2020.
//
//
//  SimpleLibrarySystem.h
//  hw3
//
//  Created by Zeynep Büsra Ziyagil on 15.12.2020.
//

#ifndef _LIBRARYSYSTEM_H
#define _LIBRARYSYSTEM_H
#include "Student.h"
#include "Book.h"
#include <string>
#include <iostream>
#include <cstddef>
using namespace std;
typedef Student listitemtype;
typedef Book blistitemtype;
typedef Book Cblistitemtype;

class LibrarySystem {
public:
    LibrarySystem();
~LibrarySystem();
void addStudent(const int studentId, const string studentName);
void deleteStudent(const int studentId);
void showStudent(const int studentId) const;
//
//
    
    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);
    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);
    void showAllBooks() const;
    void showBook(const int bookId) const;
    void showAllCheckedBooks();
    
private:
  struct Node{
        listitemtype item;
        Node* next;
        
    };
    int listsize;
    Node *head;
    Node *find(int theindex) const;
    void setListSize(int x);
    bool isListEmpty() const;
    int getListLength() const;
    bool retrievefrom(int theindex,listitemtype& itemdata) const;
    bool insertit(int theindex, listitemtype itemnew);
    bool removeit(int theindex);
   
    struct BookNode{
          blistitemtype item;
          BookNode* next;
          
      };
      int booklistsize;
      BookNode *bookhead;
      BookNode *findbook(int theindex) const;
      void setBookListSize(int x);
      bool isBookListEmpty() const;
      int getBookListLength() const;
      bool retrieveBookfrom(int theindex,blistitemtype& itemdata) const;
      bool bookinsertit(int theindex, blistitemtype itemnew);
      bool bookremoveit(int theindex);
     
    struct CBookNode{
          Cblistitemtype item;
          CBookNode* next;
          
      };
      int Cbooklistsize;
      CBookNode* Cbookhead;
      CBookNode* Cfindbook(int theindex) const;
      void CsetBookListSize(int x);
      bool CisBookListEmpty() const;
      int CgetBookListLength() const;
      bool CretrieveBookfrom(int theindex,Cblistitemtype& itemdata) const;
      bool Cbookinsertit(int theindex, Cblistitemtype itemnew);
      bool Cbookremoveit(int theindex);
    
    
};


/*     struct studentNode
 {
     Student student;
     studentNode* next;
 };
 //data members
 int studentListSize;
 studentNode* studentListHead;
 //helper functions
 studentNode* find(const int index) const;
 bool isStudentListEmpty() const;
 int getStudentListLength() const;
 bool retrieveStudent(const int index, Student& s) const;
 bool insertStudent(const int index,Student newStudent);
 bool removeStudent(const int index);
 int findStudentIndex(const int id) const;
};*/

#endif /* SimpleLibrarySystem_h */
