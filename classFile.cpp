// File Name: Player.cpp
//
// Author: Jared Murphy, Austin Gray
// Date: 10/23/2018
// Assignment Number: 4
// CS 2308.003 Fall 2018
// Instructor: Jill Seaman
//
// This program uses classes to upload songs information to a device.
// Using the classes the device saves and displays the songs entered.

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Player.h"

Player::Player(string n, float cap)
{
    name = n;
    capacity = cap;
    Song song[SIZE];
    count = 0;
}

//***********************************************************
// songPresence: Tests to see if the song being added is
// already present on the device
// b is the name of the band
// t is the title of the song
// returns true if the song is found, flase if not
//***********************************************************

bool Player::songPresence(string b, string t)
{
    for(int i = 0; i < count; i++)
    {
        if (b == song[i].band && t == song[i].title)
            return true;
    }
    return false;
}

//***********************************************************
// addSong: Adds songs to the device if song is not already on
// and does not exceed memory or song count
// b is the name of the band
// t is the title of the song
// l it the length of the song
// s is the size of the song in Mb
// returns true if song was added false for any reason it was not
//***********************************************************

bool Player::addSong(string b, string t, string l, float s)
{
    if (!songPresence(b, t))
    {
        if ((s+currentMemory) < capacity)
        {
            if(count < SIZE)
            {
                song[count].band = b;
                song[count].title = t;
                song[count].length = l;
                song[count].size = s;
                count++;

                currentMemory += s;
                totalLength.add(l);
            }
            else
            {
                cout << "Too many songs" << endl;
                return false;
            }
        }
        else
        {
            cout << "Not enough memory." << endl;
            return false;
        }
    }
    else
    {
        cout << "Song is already present." << endl;
        return false;
    }
    return true;

}

//***********************************************************
// displaySongInfo: searches for the song and displays the
// songs info if found
// b is the name of the band
// t is the title of the song
//***********************************************************

void Player::displaySongInfo(string b, string t)
{
    bool found = false; // flag for song detection
    int i = 0; // count to stop loop if song is not present
    while (!found && i < count)
    {
        if (song[i].band==b && song[i].title==t)
        {
            cout << fixed << setprecision(2) << "Song Info:" << endl << fixed
                 << right << "Band: " << left << song[i].band << endl
                 << right << "Title: " << left << song[i].title << endl
                 << right << "Length: " << left << song[i].length << endl
                 << right << "Size: " << left << song[i].size << " Mb"
                 << endl << endl;
            found = true;
        }
        i++;
    }
}

//***********************************************************
// displaySongsByLength: sorts and displays songs by length
//***********************************************************

void Player::displaySongsByLength()
{
   cout << "All songs sorted by length:" << endl;

   bool swap; // flag for swap
   Song tempSong; // temp Song for swap

   do
   {
      swap = false;
      for (int j = 0; j < (count - 1); j++)
      {
         TimeStamp temp(song[j].length);

         if (temp.greaterThan(song[j+1].length))
         {
            tempSong = song[j];
            song[j] = song[j + 1];
            song[j + 1] = tempSong;
            swap = true;
         }
      }
   } while (swap);

   for(int i = 0; i < count; ++i)
    cout << fixed << right
         << "Band: " << left << song[i].band << endl
         << right << "Title: " << left << song[i].title << endl
         << right << "Length: " << left << song[i].length << endl
         << right << "Size: " << left << song[i].size << " Mb" << endl
         << endl;
}

//***********************************************************
// deviceInfo: Displays the devices info whe called
//***********************************************************

void Player::deviceInfo(){
  cout << fixed << setprecision(2)
       << "Device info:" << endl
       << "Name: " << name <<  endl
       << "Songs: " << count << "/" << SIZE << endl
       << "Total length: " << totalLength.toString() << endl
       << "Free space Left: " << capacity - currentMemory << " Mb" << endl
       << endl;
}

//***********************************************************
// removeSong: checks for and removes the song requested
// from the device
// b is the name of the band
// t is the title of the song
// returns true if the song is found and deleted false if not
//***********************************************************

bool Player::removeSong(string b, string t){
  for(int i = 0; i < count; i++)
    {
        if (b == song[i].band && t == song[i].title){
          --count;
         totalLength.subtract(song[i].length);
         currentMemory -= song[i].size;
          for(int j = i; j < count; ++j)
            song[j] = song[j+1];

        return true;
        }
    }
    cout << "Song was not found!" << endl;

    return false;
}
