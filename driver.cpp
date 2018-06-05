/*
    Members: Cody Morgan, Andrew Levandowski
    Accounts: cssc1211 (location of assignment), cssc1214
    Class: CS 570, Summer 2018
    Assignment: Assignment 1, Thread Management
    Filename: driver.cpp
*/

#include "Threads.hpp"
#include <fstream>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;

int main()
{
    ofstream outfile ("STACK.txt");     // create text file
    int pID = getpid();
    outfile << pID << "\n";     // write process ID to text file
    outfile.close();

    threadCreator();        // create and run threads

    return 0;
}
