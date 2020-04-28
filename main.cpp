#include <iostream>
#include <stdlib.h>

#include "list_parent.h"
#include "list_child.h"
#include "list_relasi.h"

using namespace std;

void MainMenu(){
    infotype_parent parent;
    infotype_child child;

    adr_child ADRchild;
    adr_parent ADRparent;
    adr_relasi ADRrelasi;
    List_parent A;
    List_child B;
    List_relasi C;
    createListParent(A);
    createListChild(B);
    createListRelasi(C);

    int choose;
    do{
        cout<<"KLINIK MITRA SEHAT"<< endl;
        cout<<"1.  Input Data Dokter"<< endl;
        cout<<"2.  Input Data Pasien"<< endl;
        cout<<"3.  Input Data Berobat"<< endl;
        cout<<"4.  Tampil Data Dokter" << endl;
        cout<<"5.  Tampil Data Pasien"<< endl;
        cout<<"6.  Tampil Data Berobat"<< endl;
        cout<<"7.  Tampil Pasien Satu Dokter"<< endl;
        cout<<"8.  Tampil Pasien Setiap Dokter"<< endl;
        cout<<"9.  Hapus Data Dokter"<< endl;
        cout<<"10. Hapus Data Pasien"<< endl;
        cout<<"11. Hapus Data Berobat"<< endl;
        cout<<"12. "<< endl;
        cout<<"13. "<< endl;
        cout<<"0.  Keluar"<< endl;
        cout<<"\nPilih Menu : ";
        cin>>choose;
        system("CLS");
        switch(choose){
        case 1:
            InputDataDokter(A,parent);
            clrscr();
            break;
        case 2:
            InputDataPasien(B,child);
            clrscr();
            break;
        case 3:
            PasienBerobat(A,B,C,ADRchild,ADRparent,ADRrelasi);
            clrscr();
            break;
        case 4:
            printParent(A);
            clrscr();
            break;
        case 5:
            printChild(B);
            clrscr();
            break;
        case 6:
            printRelasi(C);
            clrscr();
            break;
        case 7:
            printChildFromOneParent(C,A);
            clrscr();
            break;
         case 8:
            printChildFromAllParent(C,A);
            clrscr();
            break;
        case 9:
            DeleteParent(A,C);
            clrscr();
            break;
        case 10:
            DeleteChild(B,C);
            clrscr();
            break;
        case 11:
            DeleteRelasi(C);
            clrscr();
            break;
        case 12:

            clrscr();
            break;
        case 13:

            clrscr();
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
