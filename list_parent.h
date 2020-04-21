#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED
#include <iostream>

using namespace std;

struct infotypeParent {
    string ID;
    string namadokter;
};

typedef struct Parent *address1;

struct Parent {
    infotypeParent info;
    address1 next;
};

struct List1 {
    address1 first;
    address1 last;
};

void createListParent(List1 &L);
address1 CreateElmParent(infotypeParent st);
void insertFirstParent(List1 &L, address1 P);
void insertAfterParent(List1 &L, address1 Prec, address1 P);
void insertLastParent(List1 &L, address1 P);
void insertSortParent(List1 &L, infotypeParent st);
void deleteFirstParent(List1 &L, address1 &P);
void deleteAfterParent(List1 &L, address1 Prec, address1 &P);
void deleteLastParent(List1 &L, address1 &P);
void deleteListParent(List1 &L, string st);
address1 findElmParent(List1 &L, string X);
void printInfoParent(List1 L);


#endif // LIST_PARENT_H_INCLUDED
