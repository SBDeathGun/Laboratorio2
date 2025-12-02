#define _GNU_SOURCE
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
/*Liste di interi (31/10/25)

Utilizzare la struct

typedef struct _intero {
  int valore;
  struct _intero next;
} intero;

per rappresentare un elemento di una lista di interi.

Scrivere un funzione

int confronta_lunghezza(intero *lis1, intero *lis2);

che date due liste di interi lis1 e lis2 (possibilemente anche vuote) restituisce -1 se lis1 ha meno elementi di lis2, 1 se lis1 ha più elementi di lis2, 0 se hanno lo stesso numero di elementi (le liste vuote si considerano avere 0 elementi).

Si scriva poi un main che legge dalla linea di comando un numero qualsiasi di interi e crea due liste contenenti rispettivamente gli interi pari e gli interi dispari passati sulla linea di comando (si noti che le liste possono essere vuote).

Successivamente il main deve invocare confronta_lunghezza e stampare la lista più lunga; se le liste hanno la stessa lughezza deve stampare quella la cui somma degli elementi è maggiore, se anche la somma degli elementi è la stessa non deve stampare nulla.

Il programma deve poi deallocare tutta la memoria utilizzata e terminare.*/


typedef struct head {
  int valore;
  struct head* next;
} intero;

intero *creanodo(int n){
    intero *nodo= malloc(sizeof(intero));
    nodo->valore=n;
    return nodo;
}
void distruttoreLista(intero *head){
    assert(head!=NULL);
    intero *next=head->next;
    while (next!=NULL){
        free(head);
        head=next;
        next=head->next;
    }
    free(head);
}


void inseriscinodo(intero** head,intero* n){
    n->next=*head;
    *head=n;    
}
void stampaLista(intero *head){
    while(head != NULL){
        printf("%d\n",head->valore);
        head=head->next;
    }
}

int sommaLista(intero* head){
    int somma=0;
    while(head!=NULL){
        somma+=head->valore;
        head = head->next;
    }
    return somma;
}

int confronta_lunghezze(intero* primo,intero* secondo){
    while(primo!=NULL && secondo!=NULL){
        primo=primo->next;
        secondo=secondo->next;
    }
    if(primo==NULL && secondo==NULL){
        return 0;
    }
    else if(primo==NULL){
        return 1;
    }
    return -1;

}

int main(int argc,char *argv[]){
    int n;
    intero *headpari = NULL;
    intero *headdispari =NULL;
    for (int i=1;i<argc;i++){
        n = atoi(argv[i]);
        
        if(n%2==0)
            inseriscinodo(&headpari,creanodo(n));
        else
            inseriscinodo(&headdispari,creanodo(n));
    }
    if(confronta_lunghezze(headpari,headdispari)==-1){
        stampaLista(headpari);
    }else if(confronta_lunghezze(headpari,headdispari)==1){
        stampaLista(headdispari);
    }else{
        if(sommaLista(headdispari)-sommaLista(headpari)<0){
            stampaLista(headpari);
        }else if(sommaLista(headdispari)-sommaLista(headpari)>0){
            stampaLista(headdispari);
        }

    }
    distruttoreLista(headpari);
    distruttoreLista(headdispari);
}