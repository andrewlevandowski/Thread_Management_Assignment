#include <string>

using namespace std;

string currentCard(int i, int j);   // determines current card being processed
void* threadRunner(void* thr_ptr);  // runs threads
void threadCreator();               // creates threads
