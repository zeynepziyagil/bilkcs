/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Zeynep Büşra Ziyagil
 * ID: 21802646
 * Section: 3
 * Assignment: 1
 * Description: Code to implement and analyse sorting algorithms
 */

#ifndef sorting_h
#define sorting_h
#include <string>

void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void radixSort(int *arr, const int size);
    
    
int largestIndex(const int *arr, int size,int &compCount);
void swap(int &x, int &y);
void mergesort(int *arr, int first, int last,int size, int &compCount, int &moveCount);
void merge(int *arr,int size,  int first, int mid,  int last, int &compCount, int &moveCount);
void partition(int *arr,int &indexpivot, int first, int last, int &compCount, int &moveCount);
void quicksort(int *arr, int first, int last,int &compCount, int &moveCount);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
    
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

void performanceAnalysis();
#endif /* sorting_h */
