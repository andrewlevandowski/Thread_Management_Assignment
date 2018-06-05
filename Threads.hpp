/*
    Members: Cody Morgan, Andrew Levandowski
    Accounts: cssc1211 (location of assignment), cssc1214
    Class: CS 570, Summer 2018
    Assignment: Assignment 1, Thread Management
    Filename: Threads.hpp
*/

#include <string>

using namespace std;

string currentCard(int i, int j);   // determines current card being processed
void* threadRunner(void* thr_ptr);  // runs threads
void threadCreator();               // creates threads
