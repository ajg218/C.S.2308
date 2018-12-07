// File Name: assign3_ajg218.cpp
//
// Author: Austin Gray and Charles Luther
// Date: 10/8/2018
// Assignment Number: 3
// CS 2308.004 Fall 2018
// Instructor: Jill Seaman
//
// This Program implements and tests functions using pointers and
// dynamic memory allocation.

#include <iostream>
#include <iomanip>

using namespace std;

void leftCircularShift(int *, int);
double litersForKm(double, double, double *);
int *subArray(int* , int* );
string **arrayOfPtrs(string [], int);
int *duplicateArray(int*, int);
void outputArray(string **, int);

int main()
{
    int size1 = 8, //size of first array
        size2 = 3, //size of second array
        size3 = 5; //size of third array

    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 3}, //array for shift function
        testArr[] = {1, 2, 3, 4, 5, 6, 7, 8}; //array for duplicate array func

    //array for arrayOfPtrs
    string strArr[] = {"echo", "charlie", "delta", "bravo", "alpha"};

    double mpg, //miles per gallon
           km, //kilometer
           ltrNeed, //liters needed to travel distance
           lp100km; //liters per 100 kilometers

    cout << "Testing leftCircularShift:" << endl
         << "test data array 1: 1 2 3 4 5 6 7 8" << endl
         << "Expected result: 2 3 4 5 6 7 8 1" << endl;

    leftCircularShift(testArr, size1);

    cout << "Actual result:   ";

    for (int i = 0; i < size1; i++)
        cout << *(testArr+i) << " ";

        cout << endl << "shift again: " << endl
             << "Expected result: 3 4 5 6 7 8 1 2" << endl
             << "Actual result:   ";

    leftCircularShift(testArr, size1);

    for (int i = 0; i < size1; i++)
        cout << *(testArr+i) << " ";

    cout << endl << endl
         << "Testing litersForKm:" << endl
         << "testing for 25.0mpg and 10.0km" << endl
         << "Expected result: 9.41 Lp100Km and 0.94 liters" << endl
         << "Actual results : ";

    mpg = 25.0;
    km = 10.0;
    ltrNeed = litersForKm(mpg, km, &lp100km);

    cout << fixed << setprecision(2)
         << lp100km << " and " << ltrNeed << " liters" <<  endl;

    mpg = 33.60;
    km = 700.0;

    cout << "testing for 33.60mpg and 700.0km" << endl
         << "Expected result: 7.00 Lp100Km and 49.00 liters" << endl
         << "Actual results : ";

    ltrNeed = litersForKm(mpg, km, &lp100km);

    cout << fixed << setprecision(2)
         << lp100km << " and " << ltrNeed << " liters" <<  endl;

   cout << endl << "testing subArray: " << endl
        << "test data: 1 2 3 4 5 6 7 8 3" << endl
        << "start: index 3 finish: index 5" << endl
        << "Expected result: 4 5 6" << endl
        << "Actual results:  ";

   int *result =  subArray(&array1[3], &array1[5]);

   for (int i = 0; i < size2; i++)
        cout << result[i] << " ";

   cout << endl << endl
        << "testing arrayOfPtr:" << endl
        << "test data: echo charlie delta bravo alpha" << endl
        << "Expected result: echo charlie delta bravo alpha" << endl
        << "Actual result:   ";

   string **test = arrayOfPtrs(strArr, size3);
   outputArray(test, size3);

   cout << endl;

   delete test;

    return 0;
}
//***********************************************************
// leftCircularShift: Shifts the elements in the array to the left
// *arr - array of elements
// test - size of the array
//***********************************************************
void leftCircularShift( int *arr, int test )
{
    int temp;

    temp = *arr;

    for (int i = 0; i < test; i++)
        *(arr + i) = *(arr + (i + 1));

    *(arr + (test - 1)) = temp;
}

double litersForKm(double mpg, double km, double *lp100km)
{
    *lp100km = (100 * 3.785411784)/(1.609344 * mpg);

    return ( *lp100km / 100 * km );
}
//***********************************************************
// subArray: Creates an array withing the bounds passed in
// begin - the element the sub array starts at
// end - the element the sub array ends at
// returns the resulting sub array
//***********************************************************
int *subArray(int *begin, int *end)
{
    int *result = duplicateArray( begin, end - begin + 1 );

    return result;
}
//***********************************************************
// arrayOfPtrs: creates and array of pointers
// strArr - array of strings
// size - size of the array
// returns an array of addresses to the new array
//***********************************************************

string** arrayOfPtrs(string strArr[], int size)
{
    string **tempStrArr = new string*[size];

    for (int i = 0; i < size; i++)
    {
        tempStrArr[i] = &strArr[i];
    }

  return tempStrArr;
}
//***********************************************************
// duplicateArray: Duplicates the array
// arr - points to the elements in the area
// size - size of the array
// returns returns the duplicated array
//***********************************************************

int *duplicateArray( int *arr, int size)
{
   int *newArray;

   newArray = new int[size];

   for (int index = 0; index < size; index++)
      newArray[index] = arr[index];

   return newArray;
}
//***********************************************************
// outputArray: outputs array
// **arrayOfPtr - passes the pointers to the array of strings
// size - size of the array
//***********************************************************
void outputArray(string **arrayOfPtrs, int size)
{
    for(int i = 0; i < size; ++i)
        cout <<  *arrayOfPtrs[i] << " ";
}
