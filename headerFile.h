// File Name: Player.h
//
// Author: Jared Murphy, Austin Gray
// Date: 10/23/2018
// Assignment Number: 4
// CS 2308.003 Fall 2018
// Instructor: Jill Seaman
//
// This program uses classes to upload songs information to a device.
// Using the classes the device saves and displays the songs entered.

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>

using namespace std;

#include "TimeStamp.h"

const int SIZE = 1000; // max size of the array of Songs

class Player
{
private:
        struct Song
    {
        string band; // band name
        string title; // title of song
        string length; // length of the song in "mm:ss" format
        float size; // size of the song in Mb
    };

    string name; // name of the device
    float capacity; // max capacity of the song in Mb

    Song song[SIZE]; // array of Songs with size SIZE
    int count; // current amount that the array is filled
    TimeStamp totalLength; // total length of the song of type TimeStamp
    float currentMemory; //amount of memory already filled with songs

public:
    Player(string n, float cap);

    bool addSong(string b, string t, string l, float s);
    bool songPresence(string b, string t);
    void displaySongInfo(string b, string t);
    void displaySongsByLength();
    void deviceInfo();
    bool removeSong(string, string t);

};


#endif
