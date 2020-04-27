#include "list_child.h"
#include "list_relasi.h"

void createListChild(List_child &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_child alokasiChild(infotype_child x){
    adr_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirstChild(List_child &L, adr_child P){
    if (first(L) != NULL){
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
        last(L) = P;
    }
}
void insertLastChild(List_child &L, adr_child P){
    if(first(L) == NULL){
       insertFirstChild(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        next(P) = first(L);
        prev(first(L)) = P;
        last(L) = P;
    }
}

void insertAfterChild(List_child &L, adr_child &Prec, adr_child P){
    if (first(L) == NULL){
        insertFirstChild(L, P);
    } else {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void deleteFirstChild(List_child &L, adr_child &P){
    P = first(L);
    if (next(first(L))!= P){
        first(L) = next(P);
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }
}

void deleteLastChild(List_child &L, adr_child &P){
    if (first(L) != last(L)){
        P = prev(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(prev(P));
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        deleteFirstChild(L,P);
    }
}

void deleteAfterChild(List_child &L, adr_child Prec, adr_child &P){
    if (next(Prec) != first(L)) {
        P = next(Prec);
        prev(next(P)) = Prec;
        next(Prec) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        deleteFirstChild(L,P);
    }
}

void insertSortChild(List_child &L, adr_child Q){
    adr_child P = first(L);
    adr_child Prec;
    if(P == NULL || info(first(L)).IDPasien >= info(Q).IDPasien){
        insertFirstChild(L,Q);
    } else if (info(last(L)).IDPasien <= info(Q).IDPasien){
        insertLastChild(L,Q);
    } else {
        do {
            Prec = P;
            P = next(P);
        } while(P != first(L) && info(P).IDPasien < info(Q).IDPasien);
        insertAfterChild(L,Prec,Q);
    }
}

void deleteListChild(List_child &L, int x){
    adr_child P, Q;
    P = first(L);
    if(info(first(L)).IDPasien == x){
        deleteFirstChild(L,Q);
        dealokasiChild(Q);
    } else if(info(prev(P)).IDPasien == x){
        deleteLastChild(L, Q);
        dealokasiChild(Q);
    } else {
        do {
            P = next(P);
        } while (P != first(L) && info(prev(P)).IDPasien != x);
        deleteAfterChild(L, prev(prev(P)), Q);
        dealokasiChild(Q);
    }
}

void dealokasiChild(adr_child &P) {
    delete P;
}

adr_child findElmChild(List_child L, int x) {
    adr_child P = first(L);
    if (P != NULL){
        do{
            if(info(P).IDPasien == x ) {
                return P;
            }
            P = next(P);
        } while(P != first(L));
    }
    return NULL;
}

void printChild(List_child L) {
    adr_child P = first(L);
    if (first(L) != NULL ) {
        do {
            cout << "ID Pasien     : " << info(P).IDPasien << endl;
            cout << "Nama          : " << info(P).Nama << endl;
            cout << "Alamat        : " << info(P).Alamat << endl;
            cout << "Jenis Kelamin : " << info(P).JenisKel << endl;
            cout << "Tanggal Lahir : " << info(P).TglLahir.tanggal <<
            "/" << info(P).TglLahir.bulan << "/" << info(P).TglLahir.tahun <<endl;
            P = next(P);
            cout<<endl;
        } while (P != first(L));
    } else {
        cout << "Tidak ada data pasien" <<endl;
    }

}

int randomIDPasien(){
    int number = rand() % 9000 + 1000;
    return number;
}

void InputDataPasien(List_child &L, infotype_child &data) {
    cout << "========DATA PASIEN========\n";
    cout << "Input Nama          : ";
    cin.get();
    getline(cin, data.Nama);
    cout << "Input Alamat        : ";
    getline(cin, data.Alamat);
    cout << "Input Jenis Kelamin : ";
    getline(cin, data.JenisKel);
    cout << "Input Tanggal Lahir : ";
    cin >> data.TglLahir.tanggal >> data.TglLahir.bulan >> data.TglLahir.tahun;

    data.IDPasien = randomIDPasien();
    if(findElmChild(L,data.IDPasien)!=NULL){
        data.IDPasien = randomIDPasien();
    }
    insertSortChild(L,alokasiChild(data));

    cout << "\nData pasien berhasil dibuat!" <<endl;
    cout << "ID Pasien anda : "<<data.IDPasien<<endl;
    bersih();
}
