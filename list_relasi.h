#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "list_parent.h"
#include "list_child.h"
#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *adr_relasi;

struct elmlist_relasi {
    adr_child child;
    adr_parent parent;
    adr_relasi next;
};

struct List_relasi {
    adr_relasi first;
    adr_relasi last;
};

void createListRelasi(List_relasi &L);
adr_relasi alokasiRelasi(adr_parent P, adr_child C);
void insertFirstRelasi(List_relasi &L, adr_relasi P);
void insertLastRelasi(List_relasi &L, adr_relasi P);
void insertAfterRelasi(adr_relasi Prec, adr_relasi P);
void deleteFirstRelasi(List_relasi &L, adr_relasi &P);
void deleteLastRelasi(List_relasi &L, adr_relasi &P);
void deleteAfterRelasi(adr_relasi Prec, adr_relasi &P);
void dealokasiRelasi(adr_relasi &P);
adr_relasi findElmRelasi(List_relasi L, int IDChild, int IDParent);
void printRelasi(List_relasi L);
void PasienBerobat(List_parent &LP,List_child &LC,List_relasi &LR,adr_child &AC,adr_parent &AP,adr_relasi &AR);
void deleteListRelasi(List_relasi &ListR,int IDdokter,int IDpasien);
void DeleteRelasi(List_relasi &ListR);
adr_relasi cariParentRelasi(List_relasi ListR, int ID);
adr_relasi cariChildRelasi(List_relasi ListR,int ID);
void deleteParentRelasi(List_relasi &ListR,int ID);
void deleteChildRelasi(List_relasi &ListR, int ID);
void DeleteParent(List_parent &ListP, List_relasi &ListR);
void DeleteChild(List_child &ListC, List_relasi &ListR);
void printChildFromOneParent(List_relasi ListR, List_parent ListP);
void printChildFromAllParent(List_relasi ListR, List_parent ListP);
void DokterSenior(List_parent &L);
void PasienDibawahUmur(List_child &L, Date &HariIni);
void TglHariIni(Date &HariIni);

void clrscr();

#endif // LIST_RELASI_H_INCLUDED
