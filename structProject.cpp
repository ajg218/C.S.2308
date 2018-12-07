// File Name: assign2_ajg218.cpp
//
// Author: Austin Gray and Charles Luther
// Date: 9/26/2018
// Assignment Number: 2
// CS 2308.004 Fall 2018
// Instructor: Jill Seaman
//
// This program allows a Lab Supervisor to track access to a lab by members
// that are identified by an ID number as well as track entry and exit times.
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Category{
    int id;
    string name;
    string time;
};

const int MAX_SIZE = 100; //Max size of the array

void bubbleSortId(Category array[], int);
void showArray( Category array[], int);
void searchId(Category array[], int value, int);
void labPresence(const Category array[], int value);
int adjustTime(string);
void bubbleSortTime(Category array[], int);

int main()
{
    int choice, //Records user menu choice
        num = 0, //Tracks amount of entries from input file
        entry; //Records user choice for ID searches

    ifstream inputFile("dataset.txt");

    if (!inputFile)
    {
      cout << "Input file failed to open. Terminating program." << endl;

      return 1;
    }

    Category member[MAX_SIZE] = {0, "", ""}; //Array of structs

    while (inputFile >> member[num].id >> member[num].name >> member[num].time)
            ++num;

    cout << fixed << showpoint << setprecision(2);

    do
    {
      cout << endl << "Menu" << endl <<endl
           << "1. Display events sorted by ID" << endl
           << "2. Display events sorted by time" << endl
           << "3. Lookup a person by ID" << endl
           << "4. Lookup the presence of the person by ID" << endl
           << "5. Quit the program" << endl << endl
           << "Enter your choice: ";

	  cin >> choice;

      if (choice != 5)
      {

         switch (choice)
         {
            case 1:
                bubbleSortId(member, num);
                showArray(member, num);
                break;
            case 2:
                bubbleSortTime(member, num);
                showArray(member, num);
                bubbleSortId(member, num);
                break;
            case 3:
                cout << endl << "What ID would you like to search for: ";
                cin >> entry;
                searchId(member, entry, num);
                break;
            case 4:
                cout << endl << "What ID would you like to search for: ";
                cin >> entry;
                labPresence(member, entry);
                break;
			default:
				cout << endl << "Please enter a valid menu choice: ";
				cin >> choice;
         }
      }
    } while (choice != 5);

    cout << endl << "Exiting program..." << endl;

    inputFile.close();

    return 0;
}

//***********************************************************
// bubbleSortId: Uses a bubble sort to sort list in ascending
//               id number
// array - the array of structs for memebers
// num - number of members from input file
//***********************************************************

void bubbleSortId(Category array[], int num)
{
   bool swapped; //Tracks if list is done being sorted

   do
   {
      swapped = false;
      for (int count = 0; count < (num - 1); count++)
      {
         if (array[count].id > array[count + 1].id)
         {
            swap(array[count], array[count + 1]);
            swapped = true;
         }
      }
   } while (swapped);
}

//***********************************************************
// showArray: displays the list of memebers
// array - the array of structs for memebers
// num - number of members from input file
//***********************************************************

void showArray(Category array[], int num)
{
   cout << endl;

   for (int count = 0; count < num; count++)
      cout << right << setw(5) << array[count].id << setw(14)
           << array[count].name << setw(9) << array[count].time << endl;

   cout << endl;
}

//***********************************************************
// searchId: Uses binary search to search for ID number entered
//           by user and displays results of that search.
// array - the array of structs for memebers
// num - number of members from input file
// value - ID user wants to search for
//***********************************************************

void searchId(Category array[], int value, int num)
{
   int first = 0,             // First array element
       last = num - 1,        // Last array element of input file data
       middle,                // Mid point of search
       position = -1;         // Position of search value
   bool found = false;        // Flag

   while (!found && first <= last)
   {
      middle = (first + last) / 2;
      if (array[middle].id == value)
      {
         found = true;
         position = middle;
      }
      else if (array[middle].id > value)
         last = middle - 1;
      else
         first = middle + 1;
   }
    if (position == -1)
    {
        cout << endl << "No person found with ID: " << value << endl;
    }
    else
        cout << endl << "The name of the person with ID " << value << " is: "
             << array[position].name << endl;
}

//***********************************************************
// labPresence: Checks for number of instances users search
//              appears in array of structs in order to
//              determine if member is still in the lab.
// array - the array of structs for memebers
// value - ID user wants to search for
//***********************************************************

void labPresence(const Category array[], int value)
{
    int count = 0; //counts how many times member entered/exited lab

    if(value != 0)
    {
       for (int i = 0; i < MAX_SIZE; i++)
       {
           if (array[i].id == value)
               ++count;
       }
        if (count%2 == 1)
            cout << endl << "The student with ID: " << value
                 << " is present in the lab" << endl;
        else if (count == 0)
            cout << endl << "No person found with ID: " << value << endl;
        else
            cout << endl << "The student with ID: " << value
                 << " is not present in the lab" << endl;
    }
    else
        cout << "No person found with ID: " << value << endl;
}

//***********************************************************
// adjustTime: Adjusts time string to int in order to sort
//             properly
// time - time element in member array
// returns: The int value in minutes of the time strings
//***********************************************************

int adjustTime(string time)
{
	int min = 0; //Used to calculate time of day in minutes

	if((time[0]-'0') == 1 && (time[1]-'0') == 2)
	{
		time[0] = '0';
		time[1] = '0';
	}

	if(time[5] == 'P')
		min += 720;

	min += (time[0]- '0') * 600;
	min += (time[1]-'0') * 60;
    min += (time[3]-'0') * 10;
    min += (time[4]-'0');

    return min;
}

//***********************************************************
// bubbleSortTime: Uses a bubble sort to sort list in ascending
//                 time values
// array - the array of structs for memebers
// num - number of members from input file
//***********************************************************

void bubbleSortTime(Category array[], int num)
{
   bool swapped;  //Tracks if list is done being sorted

   do
   {
      swapped = false;
      for (int count = 0; count < (num - 1); count++)
      {
         if (adjustTime(array[count].time) >
                adjustTime(array[count+1].time))
         {
            swap(array[count], array[count + 1]);
            swapped = true;
         }
      }
   } while (swapped);
}
