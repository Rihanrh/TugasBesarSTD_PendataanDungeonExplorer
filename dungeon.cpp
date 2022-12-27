#include "dungeon.h"

//=============================================Codingan Player=============================================

//Membuat list
void createListPlayer (ListPlayer &P){
    first(P) = NULL;
};

//Membuat Elemen Player
adrP createElemenPlayer (infotype1 ip){
    adrP p = new elmP;
    info(p) = ip;
    next(p) = NULL;
    return p;
};

//Memasukkan Player di akhir
void insertLastPlayer (ListPlayer &P, adrP ap){
    if (first(P) == NULL){
            first(P) = ap;
            }else{
                adrP p = first(P);
                while (next(p) != NULL){
                    p = next(p);
            }
            next(p) = ap;
    }
};

//Menampilkan Semua Player
void showPlayer (ListPlayer &P){
    adrP p = first(P);
    while(next(p) != NULL){
        cout<<"Nama: "<<info(p).playerName<<endl;
        cout<<"Umur: "<<info(p).playerAge<<endl;
        cout<<"Inventory: "<<info(p).inventory<<endl;
        cout<<"Rank: "<<info(p).playerRank<<endl;
        cout<<endl;
        p = next(p);
    }
    cout<<"Nama: "<<info(p).playerName<<endl;
    cout<<"Umur: "<<info(p).playerAge<<endl;
    cout<<"Inventory: "<<info(p).inventory<<endl;
    cout<<"Rank: "<<info(p).playerRank<<endl;
    cout<<endl;
};

//Menghapus Player di akhir
void deleteLastPlayer (ListPlayer &P, adrP delp){
    adrP p;
    if(first(P)==NULL){
        delp=NULL;
        cout<<"No Player"<<endl;
    }else if(next(first(P))==NULL){
        delp=first(P);
        first(P)=NULL;
    }else{
        p=first(P);
        delp=first(P);
        while(next(delp)!=NULL){
            p=delp;
            delp=next(p);
        }
        next(p)=NULL;
    }
};

//Mencari Player
adrP searchPlayer (ListPlayer P, string playerName){
    if (first(P) == NULL){
        return NULL;
    }else{
        adrP p = first(P);
        while (p != NULL && info(p).playerName != playerName){
            p = next(p);
        }
        return p;
    }
};



//=============================================Codingan Dungeon=============================================

//Membuat List Dungeon
void createListDungeon (ListDungeon &D){
    first(D) = NULL;
};

//Membuat Elemen Dungeon
adrD createElemenDungeon (infotype2 id){
    adrD d = new elmD;
    info(d) = id;
    next(d) = NULL;
    return d;
};

//Memasukan Dungeon di akhir
void insertLastDungeon (ListDungeon &D, adrD ad){
    if (first(D) == NULL){
            first(D) = ad;
            }else{
                adrD d = first(D);
                while (next(d) != NULL){
                    d = next(d);
            }
            next(d) = ad;
    }
};



