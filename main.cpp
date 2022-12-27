#include "dungeon.h"

int main()
{
    ListPlayer P;
    ListDungeon D;
    createListPlayer(P);
    createListDungeon(D);
    int N, i = 0;
    infotype1 ip;

    adrP ap, delp;

    int gamemenu = menu();

    while (gamemenu != 0){
        cout<<endl;
        cout<<"  +----------------------------------------+"<<endl;
        cout<<"  |         Anda memilih Menu: "<<gamemenu<<"           |"<<endl;
        cout<<"  +----------------------------------------+"<<endl;
        if (gamemenu == 1){
            cout<<"\t Input Data Player"<<endl;
            cout<<"\t Banyak Player: ";
            cin>>N;
            cout<<endl;
            while (i < N){
                cout<<"\t Nama Player: ";
                cin>>ip.playerName;
                cout<<"\t Umur Player: ";
                cin>>ip.playerAge;
                ip.playerRank = 0;
                ap = createElemenPlayer(ip);
                insertLastPlayer(P, ap);
                i++;
                cout<<endl;
            }
            cout<<endl;
        }else if (gamemenu == 2){
            deleteLastPlayer(P, delp);
            cout<<"   Player terakhir telah dihapus dari data."<<endl;
            cout<<endl;
        }else if (gamemenu == 3){
            showPlayer(P);
            cout<<endl;
        }else if (gamemenu == 4){
            showPlayer(P);
            cout<<endl;
        }
        gamemenu = menu();
    }
    cout<<"  +----------------------------------------+"<<endl;
    cout<<"  |   Pendataan Dungeon Explorer Berakhir  |"<<endl;
    cout<<"  +----------------------------------------+"<<endl;

    return 0;
}
