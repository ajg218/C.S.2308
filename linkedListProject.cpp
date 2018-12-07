// File Name: assign5_jam676.cpp
//
// Author: Jared Murphy, Austin Gray
// Date: 11/12/2018
// Assignment Number: 5
// CS 2308.003 Fall 2018
// Instructor: Jill Seaman
//
// Makes a class of linked lists of strings.  Makes
//functions to add, remove,reverse, copy, and search
//the lists
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "StringList.h"

//***********************************************************
// StringList: Constructs a StringList object and sets head to NULL
//
// returns: description of what function returns (if not void)
//***********************************************************

StringList::StringList()
{
  head = NULL;
}

//***********************************************************
// add: adds a string to the end of the list
//
// string str
//
// returns: nothing
//***********************************************************

void StringList::add(string str)
{
  StringNode *newNode = new StringNode; //new node to append to list
  newNode -> data = str;
  newNode -> next = NULL;

  if(!head) {
        head = newNode;
        return;
    }
  else {
      StringNode *last = head; //variable to find last node
        while(last->next)
          last = last->next;
        last->next = newNode;
    }
}

//***********************************************************
// findFirst: finds the first iteration of the string matching the input
// string
// string str
// returns: the index of the target string
//***********************************************************

int StringList::findFirst(string str)
{
  int count = 0; //index
  StringNode *p = head; //variable to traverse list

  while(p && p->data!=str)
  {
    count++;
    p = p->next;
  }
  if (!p)
    return -1;
  else
    return count;
}

///***********************************************************
// findFirst: finds the last iteration of the string matching the input
// string
// string str
// returns: the index of the target string
//***********************************************************

int StringList::findLast(string str)
{
  int count = 0; // index
  int found = 0; //int to hold index of last known iteration of target value
  bool flag = false; // flag to determine if a value was found in the list
  StringNode *p = head; //variable to traverse list

  while(p)
  {
    if(p->data == str)
    {
      found = count;
      flag = true;
    }
    count ++;
    p = p->next;
  }
  if (!flag)
    return -1;
  else
    return found;
}

//***********************************************************
// remove: removes the string at the target position
//
// int position
//
// returns: true if it has been removed, false otherwise
//***********************************************************

bool StringList::remove(int position)
{
  int count = 0; //index
  StringNode *p = head; //variable to traverse the list
  StringNode *n = NULL; //varible to change what the node is pointing to

  while(p)
  {
    if(count == position && count == 0)
    {
      head = p->next;
      delete p;

      return true;
    }
    else if (count == position)
    {
      n->next = p->next;
      delete p;

      return true;
    }
    else
    {
       n = p;
      p = p->next;
    }
    count ++;
  }

  return false;
}

//***********************************************************
// display: displays the list
//
// returns: nothing
//***********************************************************

void StringList::display()
{
  StringNode *p = head; //variable to traverse list
  while(p){
    cout << p->data << endl;
    p = p->next;
  }
}

//***********************************************************
// copy: makes a new object of StringList that is an exact copy of original one
//
// returns: the new object)
//***********************************************************

StringList StringList::copy(){
  StringList *newlist = new StringList(); //new object to hold the copied list
  StringNode *p = head; // variable to traverse list

  while(p) {
    newlist->add(p->data);
    p = p->next;
  }

  return *newlist;
}

//***********************************************************
// reverse: reverses the string list
//
// returns:nothing
//***********************************************************

void StringList::reverse()
{
  StringNode *p = head;//variable to traverse list
  StringNode *n = NULL; //p and q are variables to temporarily hold values
  StringNode *q = NULL;

  while(p)
  {
    q = p->next;
    p->next = n;
    n = p;
    p = q;
  }

  head = n;
}

//***********************************************************
// equal: takes a StringList and tests to see if it is equal to the called        // StringList
//
// StringList &other
//
// returns: true if equal, false otherwise
//***********************************************************

bool StringList::equal(StringList &other)
{
  StringNode *p = head; //variable to traverse list
  StringList *newList = &other; //new object to hold values to compare
  StringNode *n = newList->head; // variable to traverse newList

  while(p && n)
  {
    if (p->data != n->data)
    {
      return false;
    }
    else
    {
      p = p->next;
      n = n->next;
    }
  }
  if(n && !p)
  {
     return false;
  }
  else if(!n && p)
  {
    return false;
  }
  else
    return true;
}

StringList::~StringList() {
 StringNode *p;
 StringNode *n;
 p = head;

 while (p) {
    n = p->next;
    delete p;
    p = n;
    }
}
