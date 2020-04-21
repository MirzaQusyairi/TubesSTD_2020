#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#include <iostream>

using namespace std;

struct infotypeChild {
    string ID;
    string namapasien;
};

typedef struct Child *address2;

struct Child {
    infotypeChild info;
    address2 next;
    address2 prev;
};

struct List2 {
    address2 first;
};

void createListChild(List2 &L);
address2 CreateElmChild(infotypeChild st);
void insertFirstChild(List2 &L, address2 P);
void insertAfterChild(List2 &L, address2 Prec, address2 P);
void insertLastChild(List2 &L, address2 P);
void insertSortChild(List2 &L, infotypeChild st);
void deleteFirstChild(List2 &L, address2 &P);
void deleteAfterChild(List2 &L, address2 Prec, address2 &P);
void deleteLastChild(List2 &L, address2 &P);
void deleteListChild(List2 &L, string st);
address2 findElmChild(List2 &L, string X);
void printInfoChild(List2 L);


#endif // LIST_CHILD_H_INCLUDED
