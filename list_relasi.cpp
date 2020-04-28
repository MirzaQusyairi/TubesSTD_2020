#include "list_relasi.h"

void createListRelasi(List_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_relasi alokasiRelasi(adr_parent P, adr_child C){
    adr_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    return Q;
}

void insertFirstRelasi(List_relasi &L, adr_relasi P){
    if (first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
        last(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
    }
}

void insertLastRelasi(List_relasi &L, adr_relasi P){
    if (first(L) == NULL){
        insertFirstRelasi(L,P);
    } else {
        next(last(L)) = P;
        last(L) = P;
        next(P) = NULL;
    }
}

void insertAfterRelasi(adr_relasi Prec, adr_relasi P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteFirstRelasi(List_relasi &L, adr_relasi &P){
    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
}

void deleteLastRelasi(List_relasi &L, adr_relasi &P){
    P = first(L);
    while (next(P) != last(L)){
        P = next(P);
    }
    last(L) = P;
    P = next(P);
    next(last(L)) = NULL;
}

void deleteAfterRelasi(adr_relasi Prec, adr_relasi &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

void dealokasiRelasi(adr_relasi &P){
    delete P;
}

adr_relasi findElmRelasi(List_relasi L, int IDChild, int IDParent){
    adr_relasi Q = first(L);
    while (Q != NULL) {
        if (info(parent(Q)).IDDokter == IDParent  && info(child(Q)).IDPasien == IDChild){
            return Q;
        } else {
            Q = next(Q);
        }
    }
    return NULL;
}

void printRelasi(List_relasi L){
    adr_relasi P = first(L);
    if (P != NULL) {
        while (P != NULL){
        cout << info(child(P)).Nama <<" berobat kepada dokter "<< info(parent(P)).Keahlian << " (";
        cout << info(parent(P)).Nama << ")";
        P = next(P);
        }
    } else {
        cout << "Tidak ada data berobat" <<endl;
    }
    cout<<endl;
}

void PasienBerobat(List_parent &ListP, List_child &ListC, List_relasi &ListR, adr_child &AdrC, adr_parent &AdrP, adr_relasi &AdrR){
    int IDpasien,IDdokter;

    cout << "ID Pasien : ";
    cin >> IDpasien;
    cout << "ID Dokter  : ";
    cin >> IDdokter;
    AdrC = findElmChild(ListC,IDpasien);AdrP = findElmParent(ListP,IDdokter);
    if (findElmRelasi(ListR,IDpasien,IDdokter) == NULL){
        if (AdrC && AdrP) {
            AdrR = alokasiRelasi(AdrP,AdrC);
            insertLastRelasi(ListR,AdrR);
            cout << "\nData berobat telah diinput." << endl;
        } else {
            cout << "\nPasien tidak ditemukan."<<endl;
        }
    } else {
        cout << "\nPasien sudah terdata dengan dokter tersebut" <<endl;
    }
    clrscr();
}

adr_relasi cariParentRelasi(List_relasi ListR, int ID){
    adr_relasi P = first(ListR);

    while (P != NULL) {
        if (info(parent(P)).IDDokter == ID){
            return P;
        } else {
            P = next(P);
        }
    }
    return P;
}

adr_relasi cariChildRelasi(List_relasi ListR,int ID){
    adr_relasi P = first(ListR);

    while (P != NULL) {
        if (info(child(P)).IDPasien == ID){
            return P;
        } else {
            P = next(P);
        }
    }
    return NULL;
}

void deleteParentRelasi(List_relasi &ListR,int ID){
    adr_relasi P,Q;

    while (cariParentRelasi(ListR,ID) != NULL){
        if (info(parent(first(ListR))).IDDokter == ID ){
            deleteFirstRelasi(ListR,P);
            dealokasiRelasi(P);
        } else if (info(parent(last(ListR))).IDDokter == ID ){
            deleteLastRelasi(ListR,P);
            dealokasiRelasi(P);
        } else {
            Q = first(ListR);
            while (cariParentRelasi(ListR,info(parent(P)).IDDokter) != NULL){
                if (info(next(parent(Q))).IDDokter == ID){
                    deleteAfterRelasi(Q,next(Q));
                    dealokasiRelasi(Q);
                }
                Q = next(Q);
            }
        }
    }
}

void deleteChildRelasi(List_relasi &ListR, int ID){
    adr_relasi P;

    while (cariChildRelasi(ListR,ID) != NULL) {
        if(info(child(first(ListR))).IDPasien == ID ){
            deleteFirstRelasi(ListR,P);
            dealokasiRelasi(P);
        } else if (info(child(last(ListR))).IDPasien == ID){
            deleteLastRelasi(ListR,P);
            dealokasiRelasi(P);
        } else {
            adr_relasi Q = first(ListR);
            while (P != NULL && info(child(Q)).IDPasien < ID) {
                   P = Q;
                   Q = next(Q);
                }
            deleteAfterRelasi(P,Q);
            dealokasiRelasi(Q);
        }
    }
}

void DeleteParent(List_parent &ListP, List_relasi &ListR){
    int ID;
    cout << "ID Dokter yang akan di hapus : ";
    cin >> ID;
    if (findElmParent(ListP,ID) != NULL) {
        if(cariParentRelasi(ListR,ID) != NULL) {
            deleteParentRelasi(ListR,ID);
        }
        deleteListParent(ListP,ID);
        cout << "Data berhasil dihapus" <<endl;
    } else {
        cout << "ID tidak terdaftar" <<endl;
    }
}

void DeleteChild(List_child &ListC, List_relasi &ListR){
    int ID;
    cout << "ID Pasien yang akan di hapus : ";
    cin >> ID;
    if (findElmChild(ListC,ID) != NULL){
        if (cariChildRelasi(ListR,ID) != NULL){
            deleteChildRelasi(ListR,ID);
        }
        deleteListChild(ListC,ID);
        cout << "Data berhasil dihapus" <<endl;
    } else {
        cout << "ID tidak terdaftar" <<endl;
    }
}

void clrscr(){
    string any;
    cout<<endl;
    cout<<"Tekan enter untuk melanjutkan";
    cin.get();
    getline(cin,any);
    system("CLS");
}
