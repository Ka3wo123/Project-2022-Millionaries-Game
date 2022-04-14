#include <iostream>
#include "MilionerzyHeader.h"
#include <time.h>

using namespace std;

int main()
{

    int x = 1;

    srand( time( NULL) );
    string path = "..\\project_07_35223\\Pytania\\.csv", levelNumber = "1";

    starterWindow();
    while(stage <= 15 && gameStatus)
    {
        path.insert(path.length() - 4, levelNumber);
        readLinesFromFile(path);
        getAnswer();
        if(levelNumber.length() > 1)
        {
            x = 2;
        }
        path.erase(path.length() - 4 - x, x);
        levelUp(levelNumber);
        stage++;
    }
    if(gameStatus)
    {
        cout << "WYGRALES MILION ZLOTYCH!!!" << endl;
    }

    return 0;

}
