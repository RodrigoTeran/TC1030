#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

string createID() {

    string abc = "qwertyuiopasdfghjklzxcvbnm";
    string id;
    int randomInt;

    for (int i = 0; i < abc.size(); i++)
    {
        randomInt = rand() % (abc.size() - 1);
        id += abc[randomInt];
    };

    return id;
};
