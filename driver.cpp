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
