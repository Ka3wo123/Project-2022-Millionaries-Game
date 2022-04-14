#ifndef MILIONERZYHEADER_H
#define MILIONERZYHEADER_H

#include <iostream>

extern bool gameStatus, phone, audience, fiftyFifty, writeAns[];
extern unsigned stage, sum[16];
extern std::string question, ansA, ansB, ansC, ansD;
extern char correctAns;

void readLinesFromFile(std::string path);
void PhoneToFriend();
void Crowd();
void fifty();
void getAnswer();
void levelUp(std::string &s);
void starterWindow();

#endif // MILIONERZYHEADER_H
