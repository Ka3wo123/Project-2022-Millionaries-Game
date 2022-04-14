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

void getAnswer()
{

    char answer;

options:
    system("cls");
    cout << "Pytanie nr " << stage << " za " << sum[stage] << " zl " << "(masz " << sum[stage-1] << " zl)" << endl;
    cout << question << endl;
    if( writeAns[0] ) cout << "A. " + ansA << endl;
    else cout << endl;
    if( writeAns[1] ) cout << "B. " + ansB << endl;
    else cout << endl;
    if( writeAns[2] ) cout << "C. " + ansC << endl;
    else cout << endl;
    if( writeAns[3] ) cout << "D. " + ansD << endl << endl;
    else cout << endl;
    if( run50  == true )
    {
        fifty();
        run50 = false;
        goto options;
    }
    if(phone)
    {
        cout << "5 - telefon do przyjaciela" << endl;
    }
    if(audience)
    {
        cout << "6 - pytanie do publicznosci" << endl;
    }
    if(fiftyFifty)
    {
        cout << "7 - 50/50" << endl;
    }
    cout << "8 - zrezygnuj" << endl;

    cout << "Podaj odpowiedz lub wybierz opcje: ";
    cin >> answer;


    if(answer == 'A' || answer == 'a')
    {
        answer = '1';
    } else if(answer == 'B' || answer == 'b')
    {
        answer = '2';
    } else if(answer == 'C' || answer == 'c')
    {
        answer = '3';
    } else if(answer == 'D' || answer == 'd')
    {
        answer = '4';
    } else if (answer == '5' && phone)
    {
        PhoneToFriend();
        this_thread::sleep_for(4000ms);
        phone = false;
        goto options;
    } else if(answer == '6' && audience)
    {
        Crowd();
        this_thread::sleep_for(4000ms);
        audience = false;
        goto options;
    }
    else if(answer == '7' && fiftyFifty)
    {
        run50 = true;
        fiftyFifty = false;
        goto options;
    }else if(answer == '8')
    {
        system("cls");
        cout << "Wygrales " << sum[stage - 1] << " zl" << endl;
        exit(0);
    } else
    {
        cout << "Wybierz dostepne opcje" << endl;
        this_thread::sleep_for(1000ms);
        system("cls");
        goto options;

    }
    if(answer == correctAns)
    {
        system("cls");
        cout << "Poprawna odpowiedz!" << endl;
        this_thread::sleep_for(2000ms);
        system("cls");
    } else
    {
        system("cls");
        cout << "Bledna odpowiedz!" << endl;

        if(stage >= 5 && stage < 10)
        {
            cout << "Konczysz z kwota: " << sum[5] << " zl" << endl;
        } else if(stage >= 10)
        {
            cout << "Konczysz z kwota: " << sum[10] << " zl" <<  endl;
        } else
        {
            cout << "Konczysz z kwota: 0 zl " << endl;
        }

        gameStatus = false;

    }

    question = "";
    ansA = "";
    ansB = "";
    ansC = "";
    ansD = "";
    for(int i = 0; i < 4; i++)
    {
        writeAns[i] = true;
    }

}


void levelUp(string &s)
{
    int levelNumberInt;
    levelNumberInt = stoi(s);
    levelNumberInt++;
    s = to_string(levelNumberInt);
}

void starterWindow()
{
    cout << "                                            **MILIONERZY**" << endl;
    cout << "Witaj w grze Milionerzy!" << endl;
    cout << "Przed Toba 15 pytan." << endl;
    cout << "Poprawna odpowiedz to przejscie do kolejnego pytania." << endl;
    cout << "Do wykorzystania masz 3 kola ratunkowe - telefon do przyjaciela, 50/50 oraz pytanie do publicznosci." << endl;
    cout << "Dwa progi z suma gwarantowana przy 5. i 10. pytaniu." << endl;
    cout << "Gotowy do gry? ";
    system("pause");
    system("cls");
}
