//
//  Student.cpp
//  hw3_B
//
//  Created by Zeynep Büsra Ziyagil on 16.12.2020.
//

//
//  SimpleStudent.cpp
//  hw3
//
//  Created by Zeynep Büsra Ziyagil on 15.12.2020.
//


#include "Student.h"
#include <iostream>
#include <iomanip>

#include <string>
using namespace std;


Student::Student(const int theid, const string name): blistsize(0), bhead(NULL)
{
    setName(name);
    setId(theid);
}
Student::~Student()
{
    while(!bisListEmpty())
    {
        bremoveit(1);
    }

}

int Student::getID() const
{
    return sid;
}

string Student::getName() const
{
    return name;
}

void Student::setId(const int theid)
{
    sid = theid;
}

void Student::setName(const string stuName)
{
    name = stuName;
}


void Student::getBooks(){
    
    BNode* current =bhead;
    if(current ==NULL)
    {
        cout<<"Student"<<sid<<" has no books\n";
    }
    else{
        cout<<"Student 21000000 has checked out the following books:\n";
    cout<<setw(10)<<"Book Id "<<setw(23)<<"Book Name"<< setw(6)<<"Year"<<"\n";
    while(current != NULL )
    {
        
        cout<< setw(10)<< current->item.getID() <<setw(23)<<current->item.getTitle()<< setw(6)<<current->item.getYear()<<"\n";
        
        current = current->next;
    }
   
    
    }}
void Student::sAddBook(const int bookId, const string bookName, const int bookYear){
    
    BNode* current =bhead;
    bool exists = false;
    while(current != NULL && !exists)
    {
        if(current->item.getID() == bookId )
        {
           exists = true;
           
            break;
           
        }
        current = current->next;
    }
   
    
    if(!exists )
    {
        
        //create Student with given info
        Book bo(bookId,bookName,bookYear);
        bool done = binsertit(bgetListLength()+1,bo);
        if(done){}
//        cout<< "Student "<<sid<<" checked "<<bookId<<"\n";
    }
     
    
}
void Student::sDeleteBook(const int bookId){
    
    BNode* current = bhead;
    bool exists = false;
   int indext = 1;
    while(current != NULL && !exists)
    {
        
        if((current->item).getID() == bookId )
        {
           exists =true;
            
            break;
        }
        current = current->next;
        indext++;
    }
   
   if(exists)
   {
       bremoveit(indext);
     
   }
   else
   {
          
           
           
   }
}
int Student::getBookId(int index)
{
   
    
    int ID= -1;
  
    BNode*current = bhead;
    int a = 1;
    while(current != NULL)
    {
        if(a==index)
        {
            ID = current->item.getID();
            
        }
        current = current->next;
        a++;
    }
    return ID;
   
   
    
}

Student::BNode *Student::bfind(int theindex) const{
    
    if ( (theindex < 1) || (theindex > bgetListLength()) )
       return NULL;
    
    else{ // count from the beginning of the list
       BNode *current = bhead;
       for (int i = 1; i < theindex; ++i)
          current = current->next;
       return current;
    }
    
}

void Student::bsetListSize(int x){
    blistsize= x;
}
bool Student::bisListEmpty() const{
    return blistsize == 0;
}
int Student::bgetListLength() const{
    return blistsize;
}
bool Student::bretrievefrom(int theindex,bitemtype& itemdata) const{
    if ((theindex < 1) || (theindex > bgetListLength()))
       return false;
    
    // get pointer to node, then data in node
    BNode *current = bfind(theindex);
    itemdata = current->item;

    return true;
}
bool Student::binsertit(int theindex, bitemtype itemnew){
    
     
     int newLength = bgetListLength() + 1;

     if ((theindex < 1) || (theindex > newLength))
        return false;
     
     BNode* newPtr = new BNode;
     bsetListSize(newLength);
     newPtr->item = itemnew;
     if (theindex == 1){
        newPtr->next = bhead;
        bhead = newPtr;
     }
     else{
        BNode *prev = bfind(theindex-1);
        newPtr->next = prev->next;
        prev->next = newPtr;
     }
     return true;
}
bool Student::bremoveit(int theindex){
    
    BNode *current;

    if ((theindex < 1) || (theindex > bgetListLength()))
       return false;

    bsetListSize(bgetListLength()-1);
    
    if (theindex == 1){
       current = bhead;
       bhead = bhead->next;
    }
    else{
       BNode *prev = bfind(theindex-1);
       current = prev->next;
       prev->next = current->next;
    }
    current->next = NULL;
    delete current;
    current = NULL;
    
    return true;
    
}
