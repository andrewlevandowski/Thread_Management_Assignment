/*
    Members: Cody Morgan, Andrew Levandowski
    Accounts: cssc1211 (location of assignment), cssc1214
    Class: CS 570, Summer 2018
    Assignment: Assignment 1, Thread Management
    Filename: Threads.cpp
*/

#include "Threads.hpp"
#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <fstream>
#include <stdint.h>

using namespace std;

sem_t FLAG;     // declare semaphore


string currentCard(int i, int j)
{
    string suites [4] = {"Diamond", "Club", "Heart", "Spade"};
    string cardNum [13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string card = suites[i] + " " + cardNum[j];

    return card;    // returns current card for each thread execution
}

void* threadRunner(void* thr_ptr)
{
    int thrID = (intptr_t) thr_ptr;

    for(int j=0; j < 13; j++)
    {
        sem_wait(&FLAG);    // decrement semaphore, start of critical section

        ofstream outfile ("STACK.txt", ios::app);
        outfile << currentCard(thrID-1, j) << "\n";     // write current card to file
        outfile.close();
	printf("Thread %d is running\n", thrID);
        // cout << "Thread " << thrID << " is running" << endl;

        sem_post(&FLAG);    // increment semaphore, end of critical section

        if(thrID == 1)      // set thread execution timings based on prompt (microseconds)
            usleep(125000); // usleep is a POSIX function that takes in timings < a second
        else if(thrID == 2)
            usleep(250000);
        else if(thrID == 3)
            usleep(500000);
        else
            usleep(750000);
    }  
}

void threadCreator()
{
    sem_init(&FLAG, 0, 4);      // initialize semaphore

    int thr1_ID = 1;
    int thr2_ID = 2;
    int thr3_ID = 3;
    int thr4_ID = 4;

    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;

    pthread_create (&thread1, NULL, threadRunner, (void*)(intptr_t) thr1_ID);
    pthread_create (&thread2, NULL, threadRunner, (void*)(intptr_t) thr2_ID);
    pthread_create (&thread3, NULL, threadRunner, (void*)(intptr_t) thr3_ID);
    pthread_create (&thread4, NULL, threadRunner, (void*)(intptr_t) thr4_ID);

    // wait for all threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    sem_destroy(&FLAG);     // destroy semaphore
    cout << "All threads complete\n";
}
