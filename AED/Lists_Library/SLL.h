#include <stdio.h>
#include <stdlib.h>

/*

====================================

	Simple Linked List Library

====================================

*/

// Struct Definition

struct SimpleLinkedListStruct{
	int data;
	struct SimpleLinkedListStruct *nextIndex;	
};
typedef struct SimpleLinkedListStruct SLL;


// Methods

SLL* StartList(void);

SLL* AddNewElementStart(SLL *l, int elem);
SLL* AddNewElementEnd(SLL *l, int elem);
SLL* RemoveElement(SLL *l, int elem);

SLL* SearchElement(SLL *l, int elem);
SLL* SearchByIndex(SLL *l, int searchedIndex);

int GetSize(SLL *l);
void RecursivePrintList(SLL *l);


/*
TLSE* TLSE_ins_ini(TLSE* l, int elem);
TLSE* TLSE_ins_fim(TLSE* l, int elem);
TLSE* TLSE_ins_fim_rec(TLSE* l, int elem);
TLSE* TLSE_ins_ord(TLSE* l, int elem);
TLSE* TLSE_ins_ord_rec(TLSE* l, int elem);

void TLSE_imprime(TLSE* l);
void TLSE_imp_rec(TLSE* l);
void TLSE_imp_rec_rev(TLSE* l);

void TLSE_libera(TLSE* l);
void TLSE_lib_rec(TLSE* l);

TLSE* TLSE_busca(TLSE* l, int elem);
TLSE* TLSE_busca_rec(TLSE* l, int elem);

TLSE* TLSE_retira(TLSE* l, int elem);
TLSE* TLSE_retira_rec(TLSE* l, int elem);*/

