/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Zeynep Büşra Ziyagil
 * ID: 21802646
 * Section: 3
 * Assignment: 1
 * Description: Code to implement and analyse sorting algorithms
 */

#include <stdio.h>
#include "sorting.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
using namespace std;
/*
 (a) [40 points] Implement the selection sort, merge sort, quick sort, and radix sort algorithms. Your functions should take an array of integers and the size of that array and then sort it in ascending order. Add two counters to count and return the number of key comparisons and the number of data moves for all sorting algorithms except the radix sort. For the quick sort algorithm, you are supposed to take the first element of the array as pivot. Your functions should have the following prototypes (all prototypes should be in sorting.h):
 
 For key comparisons, you should count each comparison like k1 < k2 as one comparison, where k1 and k2 correspond to the value of an array entry (that is, they are either an array entry like arr[i] or a local variable that temporarily keeps the value of an array entry).
 For data moves, you should count each assignment as one move, where either the right-hand side of this assignment or its left-hand side or both of its sides correspond to the value of an array entry (e.g., a swap function has three data moves).

 
 */
void selectionSort(int *arr, const int size, int &compCount, int &moveCount){
    for (int lastone = size-1; lastone >= 1; --lastone) {
        
        int largestone = largestIndex(arr, lastone+1,compCount);
        
        
        moveCount = moveCount + 3;
        swap(arr[largestone], arr[lastone]);
      }
   
}


void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    mergesort (arr,  0, size-1, size, compCount, moveCount);
    //i have created a new funtion in which i can control the first and last elements
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    int first = 0,last = size-1;
    quicksort(arr, first, last,compCount, moveCount);
    //i have created a new funtion in which i can control the first and last elements
}
void radixSort(int *arr, const int size){
  int max =arr[0];
  for(int i=0; i < size;i++)
    {if (arr[i] > max)
        max = arr[i];
        
    }
    for (int up = 1; max / up > 0; up *= 10)
        {
            int lastarr[size];
            int i, count[10] = { 0 };
            for (i = 0; i < size; i++)
                count[(arr[i] / up) % 10]++;
            for (i = 1; i < 10; i++)
                count[i] += count[i - 1];
            for (i = size - 1; i >= 0; i--) {
                lastarr[count[(arr[i] / up) % 10] - 1] = arr[i];
                count[(arr[i] / up) % 10]--;
            }
            for (i = 0; i < size; i++)
                arr[i] = lastarr[i];
            
        }
     
}

/////////////////////selectionsort
int largestIndex(const int *arr, int size,int &compCount) {
  int indexuntil = 0;
  for (int rnIndex=1; rnIndex<size;++rnIndex)
  {
    compCount++;
    if (arr[rnIndex] > arr[indexuntil])
        indexuntil = rnIndex;
  }
  return indexuntil;
}

void swap(int &x, int &y) {
   int temp = x;
   x = y;
   y = temp;
}
////mergesort
void mergesort(int *arr, int first, int last,int size, int &compCount, int &moveCount){
   
     if (first < last){
         int mid = (first + last)/2;
        mergesort(arr,  first, mid,size, compCount, moveCount);
        mergesort(arr, mid+1, last,size, compCount, moveCount);
        merge(arr, size, first, mid, last, compCount,  moveCount);
     }
}


void merge(int *arr,int size,  int first, int mid,  int last, int &compCount, int &moveCount){
     
     int temporary[size];

     int first1 = first;
     int last1 = mid;
     int first2 = mid + 1;
     int last2 = last;
     int theindex = first;
    
     for ( ; (first1 <= last1)&& (first2 <= last2); theindex++){
         compCount++;
         moveCount++;
         if ( arr[first1] < arr[first2] ) {
             temporary[theindex] = arr[first1];
            first1++;
         }
         else {
             temporary[theindex] = arr[first2];
              first2++;
         }
     }
     
     for ( ; first1 <= last1; first1++, theindex++){
         moveCount++;
         temporary[theindex] = arr[first1];
     }
     
     for ( ; first2 <= last2; first2++, theindex++) {
         moveCount++;
         temporary[theindex] = arr[first2];
     }
     
     
     for (theindex = first; theindex <= last; theindex++) {
         moveCount++;
         arr[theindex] = temporary[theindex];
     }
}
//////quicksort
void partition(int *arr,int &indexpivot, int first, int last,int &compCount, int &moveCount){
     int thepivot = arr[first];
     moveCount++;
     int lastS1 = first;
     int firstUnknown = first+1;
     for (; firstUnknown <= last; firstUnknown++) {
         compCount++;
         if (arr[firstUnknown] < thepivot){
        
            lastS1++;
            moveCount = moveCount + 3;
            swap(arr[firstUnknown], arr[lastS1]);
             
         }
     }
     
     moveCount = moveCount + 3;
     swap(arr[first], arr[lastS1]);
     indexpivot = lastS1;
  
}
void quicksort(int *arr, int first, int last,int &compCount, int &moveCount){
     int indexpivot ;
     
     if (first < last) {
        
        partition(arr,indexpivot,first,last,compCount, moveCount);
        
        quicksort(arr, first, indexpivot-1,compCount,moveCount);///-1 ??
        quicksort(arr, indexpivot+1, last,compCount, moveCount);
      
     }
}





/*  The other ones are to create four identical arrays that will be used for testing the sorting algorithms with random numbers (generated using the random number generator function rand), numbers in ascending order, and numbers in descending order, respectively.*/

void displayArray(const int *arr, const int size){
    for (int i = 0 ; i < size; i++) {
          cout<<arr[i]<<" ";
      }
      cout<<"\n";
    
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    int num ;
  
    for(int i =0;i<size;i++)
    {
        num = rand();
        arr1[i]= num;
        arr2[i]= num;
        arr3[i]= num;
        arr4[i]= num;
        
    }
    
}

void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    int x =  2147483647-size;
    int num = rand()%x  ;//integer upper bound
    for(int i =0;i<size;i++)
    {
        
        arr1[i]= num;
        arr2[i]= num;
        arr3[i]= num;
        arr4[i]= num;
        num++;
       
    }
}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    
    int num = rand() + size ;//integer upper bound
    for(int i =0;i<size;i++)
    {
        
        arr1[i]= num;
        arr2[i]= num;
        arr3[i]= num;
        arr4[i]= num;
        num--;
       
    }
}

/*  For each scenario (random, ascending, descending), use the following sizes for the arrays: 6000, 10000, 14000, 18000, 22000, 26000, 30000. Run each of the sorting algorithms with each scenario and output the elapsed time in milliseconds, the number of key comparisons and the number of data moves.
 */
void performanceAnalysis(){
    int sizeofarrays[7]={ 6000, 10000, 14000, 18000, 22000, 26000, 30000};

    int** randomarrys2d28= new int*[28];
    int a=0;
    for(int i =0;i<7;i++){
        randomarrys2d28[a] = new int[sizeofarrays[i]];
        randomarrys2d28[a+1]= new int[sizeofarrays[i]];
        randomarrys2d28[a+2]= new int[sizeofarrays[i]];
        randomarrys2d28[a+3]= new int[sizeofarrays[i]];
        createRandomArrays(randomarrys2d28[a], randomarrys2d28[a+1], randomarrys2d28[a+2], randomarrys2d28[a+3], sizeofarrays[i]);
        a=a+4;
    }
  
    int** ascarrys2d28 = new int*[28];
    a=0;
    for(int i =0;i<7;i++){
        ascarrys2d28[a]= new int[sizeofarrays[i]];
        ascarrys2d28[a+1]= new int[sizeofarrays[i]];
        ascarrys2d28[a+2]= new int[sizeofarrays[i]];
        ascarrys2d28[a+3]= new int[sizeofarrays[i]];
        createAscendingArrays(ascarrys2d28[a], ascarrys2d28[a+1], ascarrys2d28[a+2], ascarrys2d28[a+3], sizeofarrays[i]);
        a=a+4;
    }
    int** descarrys2d28 = new int*[28];
    a=0;
    for(int i =0;i<7;i++){
        descarrys2d28[a]= new int[sizeofarrays[i]];
        descarrys2d28[a+1]= new int[sizeofarrays[i]];
        descarrys2d28[a+2]= new int[sizeofarrays[i]];
        descarrys2d28[a+3]= new int[sizeofarrays[i]];
        createDescendingArrays(descarrys2d28[a], descarrys2d28[a+1], descarrys2d28[a+2], descarrys2d28[a+3], sizeofarrays[i]);
        a=a+4;
    }

    
    clock_t beginned= clock();
    clock_t ended;
    int compCount = 0;
    int moveCount = 0;
    int timeelapsed = 0;
 
    cout<<"-----------------------------------------------------\n";
    cout<<"Analysis of Selection Sort\n";
    cout<<"Random arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
    int indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        selectionSort(randomarrys2d28[indexar4],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
    
    
    cout<<"Ascending arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
     indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        selectionSort(ascarrys2d28[indexar4],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
    
    
    cout<<"Descending arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
    
    indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        selectionSort(descarrys2d28[indexar4],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
    cout<<"-----------------------------------------------------\n";
    cout<<"Analysis of Merge Sort\n";
    cout<<"Random arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
    indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        mergeSort(randomarrys2d28[indexar4+1],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
   
    cout<<"Ascending arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
     indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        mergeSort(ascarrys2d28[indexar4+1],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
    
    
    cout<<"Descending arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
    
    indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        mergeSort(descarrys2d28[indexar4+1],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
    cout<<"-----------------------------------------------------\n";
    cout<<"Analysis of Quick Sort\n";
    cout<<"Random arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
    indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        quickSort(randomarrys2d28[indexar4+2],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
   
    cout<<"Ascending arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
     indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        quickSort(ascarrys2d28[indexar4+2],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
    
    
    cout<<"Descending arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<setw(25)<<" compCount"<<setw(25)<<" moveCount\n";
    
    indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        quickSort(descarrys2d28[indexar4+2],sizeofarrays[i] ,compCount,  moveCount);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<setw(25)<< compCount<<setw(25)<< moveCount<<"\n";
        compCount = 0; moveCount = 0; timeelapsed = 0;
    }
    
    cout<<"-----------------------------------------------------\n";
    cout<<"Analysis of Radix Sort\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time"<<"\n";
    cout<<"Random arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time\n";
    indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        radixSort(descarrys2d28[indexar4+3],sizeofarrays[i]);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<"\n";
    }
    
   
    cout<<"Ascending arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time\n";
     indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        radixSort(descarrys2d28[indexar4+3],sizeofarrays[i]);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<"\n";
    }
    
    
    
    cout<<"Descending arrays\n";
    cout<<setw(25)<<"Array Size"<<setw(25)<<"Elapsed time\n";
    
    indexar4=0;
    for(int i=0;i<7;i++)
    {
        beginned = clock();
        radixSort(descarrys2d28[indexar4+3],sizeofarrays[i]);
        ended = clock();
        timeelapsed = ended - beginned;
        indexar4 =indexar4+4;
        cout<<setw(25)<<sizeofarrays[i]<<setw(25)<<timeelapsed<<"\n";
    }
    
    
    
    
    
    
    for(int i = 0;i<28;i++)
    {
        delete[] randomarrys2d28[i];
        delete[] ascarrys2d28[i];
        delete[] descarrys2d28[i];
     
    }
    delete[] randomarrys2d28;
    delete[] ascarrys2d28;
    delete[] descarrys2d28;
    
}
