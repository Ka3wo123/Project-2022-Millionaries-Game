#include "MilionerzyHeader.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <thread>

using namespace std;

bool gameStatus = true, phone = true, audience = true, fiftyFifty = true, run50 = false, writeAns[4] = {true, true, true, true};
unsigned stage = 1, sum[16] = {0, 100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 25000, 500000, 1000000};
string question, ansA, ansB, ansC, ansD;
char correctAns;
