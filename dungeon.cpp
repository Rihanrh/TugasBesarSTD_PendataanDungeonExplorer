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

//Memasukkan Dungeon pada Player yang dituju
void insertDungeon(ListPlayer &P, string playerName){
    adrP P = searchPlayer(P, playerName);

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
    cout<<"  | 5. Pencarian data Player pada Dungeon  |"<<endl;
    cout<<"  | 6. Menghapus data Dungeon pada Player  |"<<endl;
    cout<<"  | 7. Menghitung Dungeon pada Player      |"<<endl;
    cout<<"  | 0. Exit                                |"<<endl;
    cout<<"  +----------------------------------------+"<<endl;
    cout<<"               Pilihan Menu: ";

    int input = 0;
    cin >> input;

    return input;
}
