#include "list_parent.h"

void createListParent(List_parent &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_parent alokasiParent(infotype_parent x){
    adr_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirstParent(List_parent &L, adr_parent P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfterParent(List_parent &L, adr_parent Prec, adr_parent P){
    next(P) = next(Prec);
    next(Prec) = P;

}
void insertLastParent(List_parent &L, adr_parent P){
       next(last(L)) = P;
       last(L) = P;

}

void deleteFirstParent(List_parent &L, adr_parent &P){
    if (first(L) != NULL){
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(first(L));
            next(P) = NULL;
        }
    }
}
void deleteLastParent(List_parent &L, adr_parent &P){
    P = last(L);
    adr_parent Q = first(L);
    while (next(Q) != last(L)){
        Q = next(Q);
    }
    last(L) = Q;
    next(Q) = NULL;
}

void deleteAfterParent(List_parent &L,adr_parent Prec, adr_parent &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

void insertSortParent(List_parent &L, adr_parent Q){
     if (first(L) != NULL) {
        if (info(Q).IDDokter < info(first(L)).IDDokter){
            insertFirstParent(L,Q);
        } else if (info(Q).IDDokter > info(last(L)).IDDokter) {
            insertLastParent(L,Q);
        } else {
            adr_parent P = first(L);
            while (P != NULL && info(Q).IDDokter > info(next(P)).IDDokter){
                P = next(P);
            }
            insertAfterParent(L,P,Q);
        }
    } else {
        insertFirstParent(L,Q);
    }

}

void deleteListParent(List_parent &L, int ID){
    adr_parent P = first(L);

    if (first(L) != NULL){
        if(info(P).IDDokter == ID ){
            deleteFirstParent(L,P);
            dealokasiParent(P);
        } else if(info(last(L)).IDDokter == ID){
            deleteLastParent(L,P);
            dealokasiParent(P);
        } else {
            adr_parent Q = first(L);
            while (Q != NULL && info(Q).IDDokter < ID) {
                   P = Q;
                   Q = next(Q);
                }
            deleteAfterParent(L,P,Q);
            dealokasiParent(Q);
        }
    }
}

void dealokasiParent (adr_parent &P){
    delete P;
}

void printParent(List_parent L) {
    adr_parent P = first(L);
    if (first(L) != NULL ) {
        while (P != NULL) {
            cout << "ID Dokter     : " << info(P).IDDokter << endl;
            cout << "Nama          : " << info(P).Nama << endl;
            cout << "Alamat        : " << info(P).Alamat << endl;
            cout << "Jenis Kelamin : " << info(P).JenisKel << endl;
            cout << "Keahlian      : " << info(P).Keahlian << endl;
            cout << "Pengalaman    : " << info(P).Pengalaman << " Tahun" << endl;
            P = next(P);
            cout<<endl;
        }
    } else {
        cout << "Tidak ada data dokter" <<endl;
    }
}

adr_parent findElmParent(List_parent L, int x) {
    adr_parent P = first(L);
    while (P != NULL && info(P).IDDokter != x){
        P = next(P);
    }
    return P;
}

int randomIDDokter(){
    int rndm = 100 + rand() % 999;
    return rndm;
}

void InputDataDokter(List_parent &L, infotype_parent &data){
    cout << "========DATA DOKTER========\n";
    cout << "Input Nama          : ";
    cin.get();
    getline(cin, data.Nama);
    cout << "Input Alamat        : ";
    getline(cin, data.Alamat);
    cout << "Input Jenis Kelamin : ";
    getline(cin, data.JenisKel);
    cout << "Input Keahlian      : ";
    getline(cin, data.Keahlian);
    cout << "Input Pengalaman    : ";
    cin >> data.Pengalaman;

    data.IDDokter = randomIDDokter();
    if(findElmParent(L,data.IDDokter) != NULL){
         data.IDDokter = randomIDDokter();
    }
    insertSortParent(L,alokasiParent(data));

    cout << "\nData dokter berhasil dibuat!" <<endl;
    cout << "ID Dokter anda : "<<data.IDDokter<<endl;
}
