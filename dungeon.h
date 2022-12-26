#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>

using namespace std;

struct player{
    string idName;
    int idAge;
    string inventory[5];
};

struct dungeon{
    string d_Name;
    string d_Monster[5];
    string reward[5];
    string clearInfo;
};

typedef struct

#endif // DUNGEON_H_INCLUDED
