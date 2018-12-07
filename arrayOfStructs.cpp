// File Name: assign1_ajg218.cpp
//
// Author: Austin Gray
// Date: 9/12/2018
// Assignment Number: 1
// CS 2308.003 Fall 2018
// Instructor: Jill Seaman
//
// This Program keeps track of the users monthly budget using
// an array of structs. The program will display the table followed
// by asking the user to input which category they would like to add
// to, display the table again, or quit the program printing the
// amount the user is over or under the monthly budget.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Category
{
    string name;
    double allocated;
    double spent;
};

const int SIZE = 6; //Size of the array of structs

//***********************************************************
// remainingBidget: determines the remaining budget when the
// user is done entering the spent data
// bill - the array of structs for bill types
// location - takes the location in which to submit user entry
// returns: returns the Over/Under for each bill type
//***********************************************************
double remainingBudget( Category bill[], int location )
{
    return bill[location].allocated - bill[location].spent;
}

//***********************************************************
// displayTable: creates and displays the budget table
// billType - the array of structs for bill types
//***********************************************************
void displayTable( Category billType[])
{
    cout << "   Category         Allocated    Spent    over/under" << endl
         << "----------------------------------------------------" << endl;
         for( int i = 0; i < SIZE; ++i )
         {
             cout << " " << i + 1 << ". " << billType[i].name << setw(9)
                  <<  billType[i].allocated << setw(9) << billType[i].spent
                  << setw(14) << remainingBudget(billType, i) << endl;
         }
}

//***********************************************************
// promptUser: displays the prompt asking for which category
// to access
//***********************************************************
void promptUser()
{
    cout << endl << "Enter the number of a category to record money spent or"
         << endl << "7 to display the table or" << endl << "8 to quit." << endl;
}

//***********************************************************
// userEntry: takes the users entry and asks for the amount
// spent, displays the table, or displays the Over/Under
// bills - the array of structs for bill type
//***********************************************************
void userEntry(Category bills[])
{
    int entry; //used to saved user entry
    double cash; //used to saved the amount entered by user
    bool test = true; //used to turn off switch when '8' is entered

    while(test)
    {
        cin >> entry;
        switch(entry)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                cout << "Please enter the amount spent on that category: ";
                cin >> cash;
                bills[entry - 1].spent += cash;
                promptUser();
                break;
            case 7:
                displayTable(bills);
                promptUser();
                break;
            case 8:
                test = false;
        }
    }
}

//***********************************************************
// monthlyRemaining: tests and displays the amount of money
// the user has over or under spent for each category
// bills - the array of structs for each bill type
//***********************************************************
void monthlyRemaining(Category bills[])
{
    double monthlyBudget; //saves the amount of monet over/under budget

    for(int i = 0; i < SIZE; ++i)
    {
        monthlyBudget += (bills[i].allocated - bills[i].spent);
    }

    if ( monthlyBudget > 0 )
        cout << "For the month you are under budget by $"
             << monthlyBudget;

    else if ( monthlyBudget < 0 )
        {
        cout << "For the month you are over budget by $"
             << abs(monthlyBudget);
        }
    else
        cout << "You have $0 remaining for this months budget." << endl;
}

int main()
{
    // array of bill types
    Category billType[SIZE] = {{"Housing         ", 500.00, 0.00},
                               {"Utilities       ", 150.00, 0.00},
                               {"Transportation  ", 50.00, 0.00},
                               {"Food            ", 250.00, 0.00},
                               {"Entertainment   ", 150.00, 0.00},
                               {"Miscellaneous   ", 50.00, 0.00}};

    cout << fixed << setprecision(2);

    displayTable(billType);
    promptUser();
    userEntry(billType);
    monthlyRemaining(billType);

    return 0;
}
