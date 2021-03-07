/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Zeynep Büşra Ziyagil
 * ID: 21802646
 * Section: 3
 * Assignment: 1
 * Description: Code to implement and analyse sorting algorithms
 */

#include <iostream>
#include "sorting.h"

using namespace std;
int main(){
    int arrayx [16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    
    int compCount = 0,moveCount = 0;
    selectionSort(arrayx, 16, compCount, moveCount);
    cout<<"Comparison count:"<<compCount<<" Movement count:"<< moveCount<<"\n";
    cout<<"Selection Sorted:";displayArray(arrayx, 16);
    
    
    int arrayy [16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    compCount = 0;
    moveCount = 0;
    mergeSort(arrayy, 16,compCount,moveCount);
    cout<<"Comparison count:"<<compCount<<" Movement count:"<< moveCount<<"\n";
    cout<<"Merge Sorted:"; displayArray(arrayy, 16);
    
    
    int arrayz [16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    compCount = 0;
    moveCount = 0;
    quickSort(arrayz, 16, compCount, moveCount);
    cout<<"Comparison count:"<<compCount<<" Movement count:"<< moveCount<<"\n";
    cout<<"Quick Sorted:";displayArray(arrayz, 16);
    
    
    int arrayt [16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    radixSort(arrayt,16);
    cout<<"Radix Sorted:"; displayArray(arrayt, 16);
    /*int *arr1=new int[asize],*arr2=new int[asize],*arr3=new int[asize],*arr4=new int[asize];
    createAscendingArrays(arr1, arr2, arr3,arr4, asize);
    displayArray(arr1,asize);
    displayArray(arr2,  asize);*/
    performanceAnalysis();
    
    return 0;
}
