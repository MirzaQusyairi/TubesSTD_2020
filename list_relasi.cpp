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
    int i = 1;
    adr_relasi P = first(L);
    if (P != NULL) {
        while (P != NULL){
        cout <<i<<". pasien "<< info(child(P)).Nama <<" berobat kepada dokter "<< info(parent(P)).Keahlian << " (";
        cout << info(parent(P)).Nama << ")"<<endl;
        P = next(P);
        i++;
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
        } else if (AdrC){
            cout << "\nDokter tidak ditemukan."<<endl;
        } else {
            cout << "\nPasien tidak ditemukan."<<endl;
        }
    } else {
        cout << "\nPasien sudah terdata dengan dokter tersebut" <<endl;
    }
}

void deleteListRelasi(List_relasi &ListR,int IDdokter,int IDpasien){
    adr_relasi P;

    if (first(ListR) != NULL){
        if (info(child(first(ListR))).IDPasien == IDpasien && info(parent(first(ListR))).IDDokter == IDdokter){
            deleteFirstRelasi(ListR,P);
            dealokasiRelasi(P);
        } else if(info(child(last(ListR))).IDPasien == IDpasien && info(parent(last(ListR))).IDDokter == IDdokter) {
            deleteLastRelasi(ListR,P);
            dealokasiRelasi(P);
        } else {
            adr_relasi Q = first(ListR);
            while (Q != NULL && info(child(Q)).IDPasien < IDpasien && info(parent(Q)).IDDokter < IDdokter) {
                P = Q;
                Q = next(Q);
            }
            deleteAfterRelasi(P,Q);
            dealokasiRelasi(Q);
        }
    }
}

void DeleteRelasi(List_relasi &ListR){
    int IDpasien,IDdokter;

    cout << "ID Pasien : ";
    cin >> IDpasien;
    cout << "ID Dokter  : ";
    cin >> IDdokter;
    if (findElmRelasi(ListR,IDpasien,IDdokter) != NULL){
        deleteListRelasi(ListR,IDdokter,IDpasien);
        cout << "Data berobat telah dihapus" <<endl;
    } else {
        cout << "Data tidak ditemukan" <<endl;
    }
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

void printChildFromOneParent(List_relasi ListR, List_parent ListP){
    int ID;
    cout << "ID Dokter : ";
    cin >> ID;
    adr_relasi P = first(ListR);
    adr_relasi Q = cariParentRelasi(ListR,ID);
    adr_parent R = findElmParent(ListP,ID);

    if (R != NULL){
        if (Q != NULL){
            cout << "\nPasien dari dokter (" << info(parent(Q)).Nama << ") : \n";
            while (P != NULL){
                if (info(parent(P)).IDDokter == ID){
                    cout <<"=>"<< info(child(P)).Nama <<endl;
                }
                P = next(P);
            }
        } else {
           cout << "Dokter ini belum memiliki pasien" <<endl;
        }
    } else {
        cout << "Dokter ini belum terdaftar" <<endl;
    }
}

void printChildFromAllParent(List_relasi ListR,List_parent ListP){
    adr_parent P;
    adr_relasi R;

    cout << "DATA SELURUH PASIEN DARI SEMUA DOKTER"<<endl;
    P = first(ListP);
    int i = 1;
    while (P != NULL){
        cout << i <<". Pasien dari dokter ("<< info(P).Nama <<") : "<<endl;
        R = first(ListR);
        int j = 1;
        while (R != NULL){
            if (info(P).IDDokter == info(parent(R)).IDDokter) {
                cout <<"\t"<<j<<". "<<info(child(R)).Nama <<endl;
                j++;
            }
            R = next(R);
        }
        cout<<endl;
        i++;
        P = next(P);
    }

}

void DokterSenior(List_parent &L){
    adr_parent P = first(L);
    while(P!=NULL ){
        if(info(P).Pengalaman >= 5){
            cout << "ID Dokter     : " << info(P).IDDokter << endl;
            cout << "Nama          : " << info(P).Nama << endl;
            cout << "Alamat        : " << info(P).Alamat << endl;
            cout << "Jenis Kelamin : " << info(P).JenisKel << endl;
            cout << "Keahlian      : " << info(P).Keahlian << endl;
            cout << "Pengalaman    : " << info(P).Pengalaman << " Tahun" << endl;
            cout<<endl;
        }
        P=next(P);
    }
}

void TglHariIni(Date &HariIni){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    HariIni.tanggal = ltm->tm_mday;
    HariIni.bulan = 1 + ltm->tm_mon;
    HariIni.tahun = 1900 + ltm->tm_year;
}

void PasienDibawahUmur(List_child &L, Date &HariIni){
    adr_child P = first(L);
    if(P!=NULL){
        do{
            int selisih = (HariIni.tahun - info(P).TglLahir.tahun) - 1;
            if(HariIni.bulan >= info(P).TglLahir.bulan && HariIni.tanggal >= info(P).TglLahir.tanggal){
                selisih = selisih + 1;
            }
            if(selisih < 18){
                cout << "ID Pasien     : " << info(P).IDPasien << endl;
                cout << "Nama          : " << info(P).Nama << endl;
                cout << "Alamat        : " << info(P).Alamat << endl;
                cout << "Jenis Kelamin : " << info(P).JenisKel << endl;
                cout << "Umur          : " << selisih << endl;
            }
            P=next(P);
        }while (P != first(L));
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
