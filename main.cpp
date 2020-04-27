#include <iostream>
#include <stdlib.h>

#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

void MainMenu(){
    infotype_parent parent;
    infotype_child child;

    List_parent A;
    List_child B;

    createListParent(A);
    createListChild(B);

    int choose,view;
    do{
        cout<<"=========== KLINIK MITRA SEHAT ==========="<< endl;
        cout<<"1. Input Data Dokter"<< endl;
        cout<<"2. Input Data Pasien"<< endl;
        cout<<"3. Tampilkan Data"<< endl;
        cout<<"0. Keluar"<< endl;
        cout<<"\nPilih Menu : ";
        cin>>choose;
        system("CLS");
        switch(choose){
        case 1:
            InputDataDokter(A,parent);
            break;
        case 2:
            InputDataPasien(B,child);
            break;
        case 3:
            cout<<"1. Tampilkan Data Dokter" << endl;
            cout<<"2. Tampilkan Data Pasien"<< endl;
            cout<<"\nPilih : ";
            cin>>view;
            system("CLS");
            if(view == 1){
                printParent(A);
                bersih();
            } else if(view == 2){
                printChild(B);
                bersih();
            }
            break;
        }
        if(choose == 0){
            break;
        }
    }while(true);
}

int main()
{
    MainMenu();
    return 0;
}
