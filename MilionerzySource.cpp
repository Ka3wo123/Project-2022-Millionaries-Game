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

void readLinesFromFile(string path)
{
    ifstream file;
    string nowy;
    int lineCounter = 1, randomLine = rand() % 10 + 1, x = 0;
    file.open(path);

    if(file.good() != true)
    {
        cout << "Nie udalo sie otworzyc pliku z pytaniem" << endl;
        file.close();
        return;
    }

    while( true )
        {

            if(randomLine == lineCounter)
            {
                getline(file, nowy);
                correctAns = nowy[nowy.length() - 1];

                for(unsigned i = 0; i < nowy.length(); i++)
                {
                    if(nowy[i] == ';')
                    {
                        nowy[i] = ' ';
                        x++;
                    }
                    switch(x)
                    {

                    case 0: question += nowy[i]; break;
                    case 1: ansA += nowy[i]; break;
                    case 2: ansB += nowy[i]; break;
                    case 3: ansC += nowy[i]; break;
                    case 4: ansD += nowy[i]; break;
                    }
                }
                break;
            }
            else
            {
                lineCounter++;
            }
            getline(file, nowy);
        }

    file.close();
}
void Friend5()
{
    char answer = correctAns + 16;;
    cout << "Moim zdaniem poprawna odpowiedzia jest odpowiedz: " << answer << endl;
}
void PhoneToFriend()
{
    char answer = 64;
    int random;
    if( !writeAns[0] || !writeAns[1] || !writeAns[2] || !writeAns[3] )
    {
        if( stage <= 5 )
        {
            Friend5();
            return;
        }
        else
        {
            for( int i = 0 ; i < 4 ; i++ )
            {
                if( writeAns[i] )
                {
                    answer += i + 1;
                    cout << "Nie jestem pewien, ale mysle ze to odpowiedz: " << answer << endl;
                    return;
                }
            }
        }
    }

    if( stage <= 5 )
        Friend5();
    else
    {
        random = rand() % 4 + 1;
        for( int i = 1; i < 5 ; i++)
        {
            if( i == random )
            {
                answer += i;
                cout << "Nie jestem pewien, ale mysle ze to odpowiedz: " << answer << endl;
                break;
            }
        }
    }
}
void Crowd()
{

    char letter = 'A';
    int suma = 100, other=0;
    int correct = rand() % 51 + 50;
    suma -= correct;

     if( !writeAns[0] || !writeAns[1] ||  !writeAns[2] || !writeAns[3] )
     {
          cout << "Glosowanie publicznosci zakonczylo sie, a oto sa wyniki:" << endl;
          for( int i = 0 ; i < 4 ; i++ )
          {
              if( letter - 16 == correctAns)
              {
                  cout << letter++ << ". " << correct << "%" << endl;
              }
              else if( writeAns[i] )
              {
                  cout << letter++ << ". " << suma << "%" << endl;
              }
              else
              {
                  cout << letter++ << "." << endl;
              }
          }
          return;
     }


    cout << "Glosowanie publicznosci zakonczylo sie, a oto sa wyniki:" << endl;
    for( int i = 1 ; i <= 4 ; i++)
    {
        if( i == correctAns - 48)
        {
            cout << letter++  << ". " << correct << "%" << endl;
        }
        else if( i == 4)
        {
            cout << letter++  << ". " << suma << "%" << endl;
        }
        else
        {
            other = rand() % (suma + 1);
            suma -= other;
            cout << letter++  << ". " << other << "%" << endl;
        }
    }
}
void fifty()
{
    int first, second;
    int tmpCor = correctAns - 49;

    for( ; ; )
    {
        first = rand() % 4;
        second = rand() % 4;
        if( first == tmpCor || second == tmpCor || first == second )
        {
            continue;
        } else
        {
            break;
        }
    }
    writeAns[ first ] = false;
    writeAns[ second ] = false;

}
