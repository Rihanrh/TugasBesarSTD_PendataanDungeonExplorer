#include "dungeon.h"

int main()
{
    ListPlayer P;
    ListDungeon D;
    createListPlayer(P);
    createListDungeon(D);
    int N, i = 0, monsterN, rewardN, banyakDungeon;
    infotype1 ip;
    infotype2 id;
    string playerName;

    adrP ap, delp;
    adrD ad;

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
            cout<<"   Input Player yang melakukan explorasi"<<endl;
            cout<<"   Nama: ";
            cin>>playerName;
            cout<<"\t Data Dungeon"<<endl;
            cout<<"\t Nama Dungeon: ";
            cin>>id.d_Name;

            cout<<"\t Monster di dalam Dungeon"<<endl;
            cout<<"\t Banyak Monster: ";
            cin>>monsterN;
            cout<<"\t Nama Monster: ";
            for (int mn = 0; mn < monsterN; mn++){
                cin>>id.d_Monster[mn];
            }

            cout<<"\t Reward dari Dungeon"<<endl;
            cout<<"\t Banyak Reward: ";
            cin>>rewardN;
            cout<<"\t Nama Reward: ";
            for (int rn = 0; rn < rewardN; rn++){
                cin>>id.reward[rn];
            }

            ad = createElemenDungeon(id);
            insertDungeon(P, playerName, ad);
            cout<<endl;

        }else if (gamemenu == 5){
            showAll(P, D);
            cout<<endl;
        }else if (gamemenu == 7){
            cout<<"   Input Player yang melakukan eksplorasi"<<endl;
            cout<<"   Nama: ";
            cin>>playerName;
            banyakDungeon = countDungeon(P, playerName, ad);
            cout<<"Banyak dungeon yang telah dieksplorasi adalah: "<<banyakDungeon;
            cout<<endl;
        }
        gamemenu = menu();
    }
    cout<<"  +----------------------------------------+"<<endl;
    cout<<"  |   Pendataan Dungeon Explorer Berakhir  |"<<endl;
    cout<<"  +----------------------------------------+"<<endl;
    return 0;
}
