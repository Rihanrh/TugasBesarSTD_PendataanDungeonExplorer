#include "dungeon.h"

int main()
{
    ListPlayer P;
    ListDungeon D;
    createListPlayer(P);
    createListDungeon(D);
    int N, monsterN, rewardN, banyakDungeon;
    infotype1 ip;
    infotype2 id;
    string playerName, d_Name;

    adrP ap, delp;
    adrD ad;

    int gamemenu = menu();

    while (gamemenu != 0){
        cout<<endl;
        cout<<"+----------------------------------------+"<<endl;
        cout<<"|         Anda memilih Menu: "<<gamemenu<<"           |"<<endl;
        cout<<"+----------------------------------------+"<<endl;

        if (gamemenu == 1){
            cout<<"Input Data Player"<<endl;
            cout<<"Banyak Player: ";
            cin>>N;
            cout<<endl;
            for (int i = 0; i < N; i++){
                cout<<"Nama Player: ";
                cin>>ip.playerName;
                cout<<"Umur Player: ";
                cin>>ip.playerAge;
                ip.playerRank = 0;
                ap = createElemenPlayer(ip);
                insertLastPlayer(P, ap);
                cout<<endl;
            }
            cout<<endl;

        }else if (gamemenu == 2){
            showPlayer(P);
            cout<<endl;

        }else if (gamemenu == 3){
            deleteLastPlayer(P, delp);
            cout<<"Player terakhir telah dihapus dari data."<<endl;
            cout<<endl;

        }else if (gamemenu == 4){
            cout<<"Data Dungeon"<<endl;
            cout<<"Nama Dungeon: ";
            cin>>id.d_Name;

            cout<<"Monster di dalam Dungeon"<<endl;
            cout<<"Banyak Monster: ";
            cin>>monsterN;
            cout<<"Nama Monster: ";
            for (int mn = 0; mn < monsterN; mn++){
                cin>>id.d_Monster[mn];
            }

            cout<<"Reward dari Dungeon"<<endl;
            cout<<"Banyak Reward: ";
            cin>>rewardN;
            cout<<"Nama Reward: ";
            for (int rn = 0; rn < rewardN; rn++){
                cin>>id.reward[rn];
            }

            ad = createElemenDungeon(id);
            insertDungeon(D, ad);
            cout<<endl;
        }else if (gamemenu == 5){
            cout<<"Input Player yang melakukan eksplorasi"<<endl;
            cout<<"Nama Player: ";
            cin>>playerName;
            cout<<"Input Dungeon yang di eksplorasi"<<endl;
            cout<<"Nama Dungeon: ";
            cin>>d_Name;
            connectPlayerDungeon(P, D, playerName, d_Name);
            cout<<"Player "<<playerName<<" Telah mengeksplorasi dungeon "<<d_Name<<endl<<endl;

        }else if (gamemenu == 6){
            showAll(P);
            cout<<endl;

        }else if (gamemenu == 7){
            cout<<"Input Player yang melakukan eksplorasi"<<endl;
            cout<<"Nama Player: ";
            cin>>playerName;
            deleteLastDungeon(P, playerName, ad);
            cout<<endl;

        }else if (gamemenu == 8){
            cout<<"Input Player yang melakukan eksplorasi"<<endl;
            cout<<"Nama: ";
            cin>>playerName;
            banyakDungeon = countDungeon(P, playerName, ad);
            cout<<"Banyak dungeon yang telah dieksplorasi adalah: "<<banyakDungeon;
            cout<<endl<<endl;
        }
        gamemenu = menu();
    }
    cout<<"  +----------------------------------------+"<<endl;
    cout<<"  |   Pendataan Dungeon Explorer Berakhir  |"<<endl;
    cout<<"  +----------------------------------------+"<<endl;
    return 0;
}
