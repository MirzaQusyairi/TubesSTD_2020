#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED
#define first_parent(L) L.first_parent
#define next_parent(P) P->next_parent
#define info_parent(P) P->info_parent
#include <iostream>

using namespace std;
typedef int infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;
};

struct List_parent {
    address_parent first;
};

void createList(List_parent &L);
address_parent allocate(infotype_parent x);
void deallocate(address_parent &P);

void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent P, address_parent Prec);
void insertLast(List_parent &L, address_parent P);

void deleteFirst(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent &P, address_parent Prec);
void deleteLast(List_parent &L, address_parent &P);

void printInfo(List_parent L);
address_parent findElm(List_parent L, infotype_parent x);

#endif // LIST_PARENT_H_INCLUDED
