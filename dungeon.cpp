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

//Melakukan Pengecekan adanya isi Inventory
bool cekInventoryEmpty(string inventory[99]){
    for (int i = 0; i < 99; i++){
        if (inventory[i] != ""){
            return false;
        }
    }
    return true;
}

//Menampilkan Semua Player
void showPlayer (ListPlayer P){
    adrP p = first(P);
    int i = 1;
    while(p != NULL){
        cout<<"\t Data Player "<<i<<endl;
        cout<<"\t Nama: "<<info(p).playerName<<endl;
        cout<<"\t Umur: "<<info(p).playerAge<<endl;

        //Pengecekan Inventory berisi atau tidak

        if (!cekInventoryEmpty(info(p).inventory)){
            cout<<"\t Inventory: ";
            for (int i = 0; i < 99; i++){
                cout<<info(p).inventory[i]<<" ";
            }
        }else{
            cout<<"\t Inventory kosong.";
        }

        //Pengecekan memiliki rank atau tidak
        if (info(p).playerRank != 0){
            cout<<endl<<"\t Rank: "<<info(p).playerRank<<endl;
        }else{
            cout<<endl<<"\t Tidak ada Rank."<<endl;
        }
        cout<<endl;
        i++;
        p = next(p);
    }
};

//Menghapus Player di akhir
void deleteLastPlayer (ListPlayer &P, adrP delp){
    adrP p;
    if(first(P)==NULL){
        delp=NULL;
        cout<<"Tidak ada Player"<<endl;
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

//Melakukan Pengecekan adanya reward Dungeon
bool cekRewardEmpty(string reward[99]){
    for (int j = 0; j < 99; j++){
        if (reward[j] != ""){
            return false;
        }
    }
    return true;
}

//Memasukan Dungeon di akhir
//void insertLastDungeon (ListDungeon &D, adrD ad){
//    if (first(D) == NULL){
//        first(D) = ad;
//    }else{
//        adrD d = first(D);
//        while (next(d) != NULL){
//            d = next(d);
//        }
//        next(d) = ad;
//    }
//};

//Memasukkan Dungeon pada Player yang dituju
void insertDungeon(ListPlayer &P, string playerName, adrD ad){
    adrP SP = searchPlayer(P, playerName);
    adrD D;

    ad = nextPD(SP);
    if (nextPD(SP) == NULL){
        nextPD(SP) = ad;
    }else{
        while (next(D) != NULL){
            D = next(D);
        }
        next(D) = ad;
    }
}

void showAll(ListPlayer P, ListDungeon D){
    adrP ap = first(P);
    int i = 1;
    while(ap != NULL){
        //++++++++++++++++++++++++++BAGIAN PLAYER+++++++++++++++++++
        cout<<"\t Data Player "<<i<<endl;
        cout<<"\t Nama: "<<info(ap).playerName<<endl;
        cout<<"\t Umur: "<<info(ap).playerAge<<endl;

        //Pengecekan Inventory berisi atau tidak

        if (!cekInventoryEmpty(info(ap).inventory)){
            cout<<"\t Inventory: ";
            for (int i = 0; i < 99; i++){
                cout<<info(ap).inventory[i]<<", ";
            }
        }else{
            cout<<"\t Inventory kosong.";
        }

        //Pengecekan memiliki rank atau tidak
        if (info(ap).playerRank != 0){
            cout<<endl<<"\t Rank: "<<info(ap).playerRank<<endl;
        }else{
            cout<<endl<<"\t Tidak ada Rank."<<endl;
        }
        cout<<endl;

        //+++++++++++++++++++++++++BAGIAN DUNGEON++++++++++++++++++++
        cout<<"    Dungeon yang telah diexplore oleh "<<info(ap).playerName<<endl;
        adrD ad = first(D);
        while(ad != NULL){
            cout<<"\t Nama Dungeon: "<<info(ad).d_Name<<endl;

            cout<<"\t Monster: ";
            for (int j = 0; j < 99; j++){
                cout<<info(ad).d_Monster[j]<<", ";
            }

            //Pengecekan Reward Dungeon ada atau tidak
            if (!cekRewardEmpty(info(ad).reward)){
                cout<<"t Reward: ";
                for (int k = 0; k < 99; k++){
                    cout<<info(ad).reward[k]<<", ";
                }
            }else{
                cout<<"\t Reward: -";
            }
            ad = next(ad);
        }
        cout<<endl;
        i++;
        ap = next(ap);
    }
}

//=============================================Menu=============================================

int menu(){
    cout<<"  +----------------------------------------+"<<endl;
    cout<<"  |       Pendataan Dungeon Explorer       |"<<endl;
    cout<<"  +----------------------------------------+"<<endl;
    cout<<"  | 1. Masukkan data Player                |"<<endl;
    cout<<"  | 2. Hapus Player terakhir               |"<<endl;
    cout<<"  | 3. Tampilkan data Player               |"<<endl;
    cout<<"  | 4. Masukkan data Dungeon               |"<<endl;
    cout<<"  | 5. Menampilkan Dungeon Explorer        |"<<endl;
    cout<<"  | 6. Menghapus data Dungeon pada Player  |"<<endl;
    cout<<"  | 7. Menghitung Dungeon pada Player      |"<<endl;
    cout<<"  | 0. Exit                                |"<<endl;
    cout<<"  +----------------------------------------+"<<endl;
    cout<<"               Pilihan Menu: ";

    int input = 0;
    cin >> input;

    return input;
}
