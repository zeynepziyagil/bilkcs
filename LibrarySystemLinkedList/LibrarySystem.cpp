//
//  LibrarySystem.cpp
//  hw3_B
//
//  Created by Zeynep Büsra Ziyagil on 16.12.2020.
//


#include <stdio.h>
#include "LibrarySystem.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>
#include <sstream>
using namespace std;

LibrarySystem::LibrarySystem(): listsize(0), head(NULL), booklistsize(0),bookhead(NULL),Cbooklistsize(0),Cbookhead(NULL){}
LibrarySystem::~LibrarySystem()
{
    while(!isListEmpty())
    {
        removeit(1);
    }
    while(!isBookListEmpty())
    {
        bookremoveit(1);
    }
    while(!CisBookListEmpty())
    {
        Cbookremoveit(1);
    }
    

}


 

void LibrarySystem::addStudent(const int studentId, const string studentName){
    
    
    Node* current =head;
    bool exists = false;
    while(current != NULL && !exists)
    {
        if(current->item.getID() == studentId )
        {
           exists = true;
           cout<<"Student "<< studentId <<" already exists \n";
            break;
           
        }
        current = current->next;
    }
   
    bool positive = true;
    if(studentId <= 0)
    {positive = false;}
        
    if(!exists && positive)
    {
        
        //create Student with given info
        Student stu(studentId,studentName);
        bool done = insertit(getListLength()+1,stu);
        if(done)
        cout<< "Student "<<studentId<<" has been added\n";
    }
     
}




void LibrarySystem::deleteStudent(const int studentId){
    
    //traverse
     Node*current = head;
     bool exists = false;
    int indext = 1;
     while(current != NULL && !exists)
     {
         
         if((current->item).getID() == studentId )
         {
            exists =true;
             
             break;
         }
         current = current->next;
         indext++;
     }
    
    if(exists)
    {
        int lgt = find(indext)->item.bgetListLength();
        for(int i = 1;i<=lgt;i++)
        {
            int rtrid= find(indext)->item.getBookId(1);
            returnBook(rtrid);

            
        }
        removeit(indext);
        
        cout<< "Student "<< studentId <<" has been deleted \n";
    }
    else
    {
            cout<<"Student "<< studentId <<" does not exist \n";
            
            
    }
    
}


void LibrarySystem::showStudent(const int studentId) const
{
    //traverse
     Node*current =head;
     bool exists = false;
    int indext = 1;
     while(current != NULL && !exists)
     {
         if(current->item.getID() == studentId )
         {
            exists =true;
             break;
         }
         indext++;
         current = current->next;
     }
    if(exists)
    {
        cout<<"Student id: "<<find(indext)->item.getID()<<" student name: "<<find(indext)->item.getName()<<"\n";
        
        find(indext)->item.getBooks();
    }
    else{
        cout<< "Student "<<studentId<<" does not exist\n";
    }
}
    ///
 
void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear){
    
    
    BookNode* current =bookhead;
    bool exists = false;
    while(current != NULL && !exists)
    {
        if(current->item.getID() == bookId )
        {
           exists = true;
           cout<<"Book "<< bookId <<" already exists \n";
            break;
           
        }
        current = current->next;
    }
   
    bool positive = true;
    if(bookId <= 0)
    {positive = false;}
        
    if(!exists && positive)
    {
        
        //create Student with given info
        Book bo(bookId,bookName,bookYear);
        bool done = bookinsertit(getBookListLength()+1,bo);
        Cbookinsertit(CgetBookListLength()+1, bo);
        if(done)
        cout<< "Book "<<bookId<<" has been added\n";
    }
    
}


void LibrarySystem::deleteBook(const int bookId){
    
    //traverse
     BookNode*current =bookhead;
     bool boexists = false;
    int indext = 1;
     while(current != NULL && !boexists)
     {
         if(current->item.getID() == bookId )
         {
            boexists =true;
             break;
         }
         indext++;
         current = current->next;
     }
    CBookNode* Ccurrent =Cbookhead;
    bool Cboexists = false;
   int Cindext = 1;
    while(Ccurrent != NULL && !Cboexists)
    {
        if(Ccurrent->item.getID() == bookId )
        {
           Cboexists =true;
            break;
        }
        Cindext++;
        Ccurrent = Ccurrent->next;
    }
    
    if(boexists){

        if(Cboexists)
        {Cbookremoveit(Cindext);}
        returnBook(bookId);
        bookremoveit(indext);
        
        
        cout<<"Book "<<bookId<<" has been deleted\n";
        
        
    }
    else{
        cout<<"Book "<<bookId<<" does not exist\n";
    }
    
    
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId){
    
    
    BookNode* current =bookhead;
    bool bexists = false;
    int bookindex=1;
    while(current != NULL && !bexists)
    {
        if(current->item.getID() == bookId )
        {
            bexists = true;
            
            break;
           
        }
        bookindex++;
        current = current->next;
    }
  
    Node* acurrent =head;
    bool stexist = false;
    int stdindex =1;
    while(acurrent != NULL && !stexist)
    {
        if(acurrent->item.getID() == studentId )
        {
           stexist = true;
            
            break;
           
        }
        stdindex++;
        acurrent = acurrent->next;
    }
    if(!bexists)
    {
        cout<<"Book "<<bookId<<" does not exist for checkout\n";
    
    }
    else if(!stexist)
    { cout<<"Student "<<studentId<<" does not exist for checkout\n";}
    bool isavailable=false;
    if(bexists && stexist)
    {
        if( findbook(bookindex)->item.getStdID()== 0)
        {
            isavailable=true;
        }
 
        else{
            cout<<"Book "<<bookId<<" has been already checked out by another student\n";
        }
        
        
    }
    CBookNode* Ccurrent =Cbookhead;
    bool Cboexists = false;
   int Cindext = 1;
    while(Ccurrent != NULL && !Cboexists)
    {
        if(Ccurrent->item.getID() == bookId )
        {
           Cboexists =true;
            break;
        }
        Cindext++;
        Ccurrent = Ccurrent->next;
    }
    
    
    if( isavailable && stexist )
    {
        int byear= findbook(bookindex)->item.getYear();
        string btitle =  findbook(bookindex)->item.getTitle();
        find(stdindex)->item.sAddBook(bookId, btitle, byear);
        findbook(bookindex)->item.setStdId(studentId);
        if(Cboexists)
        {Cbookremoveit(Cindext);}//now its checked and out of the list
        cout<<"Book "<<bookId<<" has been checked out by student "<<studentId<<"\n";
    }
   
    
    
}

void LibrarySystem::returnBook(const int bookId){
    
    BookNode* current =bookhead;
    bool bexists = false;
    int bookindex=1;
    while(current != NULL && !bexists)
    {
        if(current->item.getID() == bookId )
        {
            bexists = true;
           
            break;
           
        }
        bookindex++;
        current = current->next;
    }
    if(bexists){
        CBookNode* Ccurrent =Cbookhead;
        bool Cboexists = false;
       int Cindext = 1;
        while(Ccurrent != NULL && !Cboexists)
        {
            if(Ccurrent->item.getID() == bookId )
            {
               Cboexists =true;
                break;
            }
            Cindext++;
            Ccurrent = Ccurrent->next;
        }
        
        if( findbook(bookindex)->item.getStdID()== 0)
        {
            cout<<"Book "<<bookId<<" has not been checked out\n";
        }
 
        else{
            int stID=findbook(bookindex)->item.getStdID();
            Node* scurrent = head;
           int indext = 1;
            while(scurrent != NULL )
            {
                
                if((scurrent->item).getID() == stID )
                {
                    
                    break;
                }
                scurrent = scurrent->next;
                indext++;
            }
            find(indext)->item.sDeleteBook( bookId);
            findbook(bookindex)->item.setStdId(0);
            
            Cbookinsertit(Cindext,Book(bookId,            findbook(bookindex)->item.getTitle(),findbook(bookindex)->item.getYear()) );
            cout<<"Book "<<bookId<<" has been returned\n";
             
            
        }
       
    }
      else{        cout<<"Book "<<bookId<<" does not exist\n";
}
    
}


void LibrarySystem::showAllBooks() const{
    /*
     BookNode* current = bookhead
     if (current != NULL){
     
     // display the linked list minus
     // its first item in reverse order
     displayReverseOrder(current->next);

     // display the first item
     cout << headPtr->item;
  }
*/
    BookNode* current = bookhead;
    cout<<setw(10)<<"Book Id"<<setw(23)<<"Book Name"<< setw(5)<<"Year"<<setw(10)<<"Status\n";
    while(current != NULL )
    {
        showBook(current->item.getID());
        current = current->next;
    }
    
}

void LibrarySystem::showBook(const int bookId) const{
    
    
    //traverse
     BookNode*current =bookhead;
     bool exists = false;
    int indext = 1;
     while(current != NULL && !exists)
     {
         if(current->item.getID() == bookId )
         {
            exists =true;
             break;
         }
         indext++;
         current = current->next;
     }
    if(exists)
    {
        string messagechecked;
        if(current->item.getStdID()== 0)
        {
            messagechecked="Not checked out";
        }
        else{
            stringstream ss;//convert int to string
            ss<< current->item.getStdID();
            string name = ss.str() ;//create name
            messagechecked="Checked out by student "  + name;
            
        }
        cout<< setw(10)<< current->item.getID() <<setw(23)<<current->item.getTitle()<< setw(6)<<current->item.getYear()<< " "<<messagechecked<<"\n";
        
            
    }
    else{
        cout<< "Book "<< bookId<<" does not exist\n";
    }
    
    
}




    void LibrarySystem::setListSize(int x){
        listsize=x;
    }
    bool LibrarySystem::isListEmpty() const{
        return listsize == 0;
    }
    int LibrarySystem::getListLength() const{
        return listsize;
    }
    bool LibrarySystem::retrievefrom(int index,listitemtype& dataItem) const{
        if ((index < 1) || (index > getListLength()))
           return false;
        
        // get pointer to node, then data in node
        Node *current = find(index);
        dataItem = current->item;

        return true;
    }
    bool LibrarySystem::insertit(int index, listitemtype newItem){
       
        
        int newLength = getListLength() + 1;

        if ((index < 1) || (index > newLength))
           return false;
        
        Node* newPtr = new Node;
        setListSize(newLength);
        newPtr->item = newItem;
        if (index == 1){
           newPtr->next = head;
           head = newPtr;
        }
        else{
           Node *prev = find(index-1);
           newPtr->next = prev->next;
           prev->next = newPtr;
        }
        return true;

    }
    bool LibrarySystem::removeit(int index){
        
        Node *current;

        if ((index < 1) || (index > getListLength()))
           return false;

        setListSize(getListLength()-1);
        
        if (index == 1){
           current = head;
           head = head->next;
        }
        else{
           Node *prev = find(index-1);
           current = prev->next;
           prev->next = current->next;
        }
        current->next = NULL;
        delete current;
        current = NULL;
        
        return true;
        
        
        
    }
 
LibrarySystem::Node* LibrarySystem::find(int index) const{
// Locates a specified node in a linked list.
// Precondition: index is the number of the
// desired node.
// Postcondition: Returns a pointer to the
// desired node. If index < 1 or index > the
// number of nodes in the list, returns NULL.

   if ( (index < 1) || (index > getListLength()) )
      return NULL;
   
   else{ // count from the beginning of the list
      Node *current = head;
      for (int i = 1; i < index; ++i)
         current = current->next;
      return current;
   }
}  // end find



LibrarySystem::BookNode * LibrarySystem::findbook(int theindex) const{
    
    if ( (theindex < 1) || (theindex > getBookListLength()) )
       return NULL;
    
    else{ // count from the beginning of the list
       BookNode *current = bookhead;
       for (int i = 1; i < theindex; ++i)
          current = current->next;
       return current;
    }
}
void LibrarySystem::setBookListSize(int x){
    booklistsize=x;
}
bool LibrarySystem::isBookListEmpty() const{
    return booklistsize==0;
}
int LibrarySystem::getBookListLength() const{
    return booklistsize;
}
bool LibrarySystem::retrieveBookfrom(int theindex,blistitemtype& itemdata) const{
    if ((theindex < 1) || (theindex > getBookListLength()))
       return false;
    
    // get pointer to node, then data in node
    BookNode *current = findbook(theindex);
    itemdata = current->item;
    return true;
}
bool LibrarySystem::bookinsertit(int theindex, blistitemtype itemnew){
    
    int newLength = getBookListLength() + 1;

    if ((theindex < 1) || (theindex > newLength))
       return false;
    
    BookNode* newPtr = new BookNode;
    setBookListSize(newLength);
    newPtr->item = itemnew;
    if (theindex == 1){
       newPtr->next = bookhead;
       bookhead = newPtr;
    }
    else{
       BookNode *prev = findbook(theindex-1);
       newPtr->next = prev->next;
       prev->next = newPtr;
    }
    return true;
}
bool LibrarySystem::bookremoveit(int theindex){
    BookNode *current;

    if ((theindex < 1) || (theindex > getBookListLength()))
       return false;

    setBookListSize(getBookListLength()-1);
    
    if (theindex == 1){
       current = bookhead;
       bookhead = bookhead->next;
    }
    else{
       BookNode *prev = findbook(theindex-1);
       current = prev->next;
       prev->next = current->next;
    }
    current->next = NULL;
    delete current;
    current = NULL;
    
    return true;

}
 

LibrarySystem::CBookNode* LibrarySystem::Cfindbook(int theindex) const{
    if ( (theindex < 1) || (theindex > CgetBookListLength()) )
       return NULL;
    
    else{ // count from the beginning of the list
       CBookNode *current = Cbookhead;
       for (int i = 1; i < theindex; ++i)
          current = current->next;
       return current;
    }
    
    
}
void LibrarySystem::CsetBookListSize(int x){
    Cbooklistsize=x;
}
bool LibrarySystem::CisBookListEmpty() const{
    return Cbooklistsize == 0;
}
int LibrarySystem::CgetBookListLength() const{
    return Cbooklistsize;
}
bool LibrarySystem::CretrieveBookfrom(int theindex,Cblistitemtype& itemdata) const{
    if ((theindex < 1) || (theindex > CgetBookListLength()))
       return false;
    
    // get pointer to node, then data in node
    CBookNode *current = Cfindbook(theindex);
    itemdata = current->item;
    return true;
    
    
}
bool LibrarySystem::Cbookinsertit(int theindex, Cblistitemtype itemnew){
    
    
    int newLength = CgetBookListLength() + 1;

    if ((theindex < 1) || (theindex > newLength))
       return false;
    
    CBookNode* newPtr = new CBookNode;
    CsetBookListSize(newLength);
    newPtr->item = itemnew;
    if (theindex == 1){
       newPtr->next = Cbookhead;
       Cbookhead = newPtr;
    }
    else{
       CBookNode *prev = Cfindbook(theindex-1);
       newPtr->next = prev->next;
       prev->next = newPtr;
    }
    return true;
}
bool LibrarySystem::Cbookremoveit(int theindex){
    CBookNode *current;

    if ((theindex < 1) || (theindex > CgetBookListLength()))
       return false;

    CsetBookListSize(CgetBookListLength()-1);
    
    if (theindex == 1){
       current = Cbookhead;
       Cbookhead = Cbookhead->next;
    }
    else{
       CBookNode *prev = Cfindbook(theindex-1);
       current = prev->next;
       prev->next = current->next;
    }
    current->next = NULL;
    delete current;
    current = NULL;
    
    return true;
    
    
}
void LibrarySystem::showAllCheckedBooks()
{
    
    CBookNode* current = Cbookhead;
    cout<<setw(10)<<"Book Id"<<setw(23)<<"Book Name"<< setw(5)<<"Year"<<setw(10)<<"Status\n";
    while(current != NULL )
    {
        showBook(current->item.getID());
        current = current->next;
    }
    
    
    
    
}


