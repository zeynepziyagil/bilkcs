//
//  Student.h
//  hw3_B
//
//  Created by Zeynep Büsra Ziyagil on 16.12.2020.
//

#include <string>
#ifndef _STUDENT_H
#define _STUDENT_H
#include "Book.h"
using namespace std;
typedef Book bitemtype;
class Student{
    public:
        Student( const int = 0, const string = "");
        ~Student();
        void setId(const int sid);
        void setName(const string name);
    int getID() const;
    string getName() const;

    void getBooks();
    void sAddBook(const int bookId, const string bookName, const int bookYear);
    void sDeleteBook(const int bookId);
    int bgetListLength() const;
    int getBookId(int index);
    private:
        int sid;
        string name;
    struct BNode{
          bitemtype item;
          BNode* next;
          
      };
      int blistsize;
      BNode *bhead;
      BNode *bfind(int theindex) const;
      void bsetListSize(int x);
      bool bisListEmpty() const;
      
      bool bretrievefrom(int theindex,bitemtype& itemdata) const;
      bool binsertit(int theindex, bitemtype itemnew);
      bool bremoveit(int theindex);
      
    
};

#endif
