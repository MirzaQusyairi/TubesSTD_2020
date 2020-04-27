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

adr_relasi findElmRelasi(List_relasi L, int diC, int diP){
    adr_relasi Q = first(L);
    while (Q != NULL) {
        if (info(parent(Q)).IDDokter == diP  && info(child(Q)).IDPasien == diC){
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

void bersih (){
    cout<<endl;
    system("pause > 0 | echo tekan enter untuk melanjutkan..");
    system("CLS");
}
