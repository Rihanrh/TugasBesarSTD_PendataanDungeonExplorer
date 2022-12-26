#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>

using namespace std;

struct clearD{
    adrD info;
    adrD next;
};

struct player{
    string playerName;
    int playerAge;
    string inventory[5];
    int playerRank;
};

struct dungeon{
    string d_Name;
    string d_Monster[5];
    string reward[5];
    string clearInfo;
};

typedef struct player infotype1;
typedef struct dungeon infotype2;
typedef struct elmP *adrP;
typedef struct elmD *adrD;
typedef struct clearD infotype3;

struct elmP{
    infotype1 info;
    infotype3 clearD;
    adrP next;
};

struct elmD{
    infotype2 info;
    adrD next;
};

struct ListPlayer{
    adrP first;
};

struct ListDungeon{
    adrD first;
};


#endif // DUNGEON_H_INCLUDED
