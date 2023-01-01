#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define nextPD(P) (P)->nextPD
#define first(L) ((L).first)


struct player{
    string playerName;
    int playerAge;
    int playerRank;
};

struct dungeon{
    string d_Name;
    string d_Monster[99];
    string reward[99];
};

typedef struct player infotype1;
typedef struct dungeon infotype2;
typedef struct elmP *adrP;
typedef struct elmD *adrD;

struct elmP{
    infotype1 info;
    adrP next;
    adrD nextPD;
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

void createListPlayer (ListPlayer &P);
adrP createElemenPlayer (infotype1 ip);
void insertLastPlayer (ListPlayer &P, adrP ap);
void showPlayer (ListPlayer P);
void deleteLastPlayer (ListPlayer &P, adrP delp);
adrP searchPlayer(ListPlayer P, string playerName);

void createListDungeon (ListDungeon &D);
adrD createElemenDungeon (infotype2 id);
void insertDungeon(ListDungeon &D, adrD ad);
int countDungeon(ListPlayer P, string playerName, adrD ad);
adrD searchDungeon(ListDungeon D, string d_Name);
void deleteLastDungeon(ListPlayer &P, string playerName, adrD ad);

void connectPlayerDungeon(ListPlayer &P, ListDungeon D, string playerName, string d_Name);

void showAll(ListPlayer P);
int menu();

#endif // DUNGEON_H_INCLUDED
