#define _GNU_SOURCE
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

/*Scrivere una funzione C

int *somme_distinte(int a[], int n, int *size)

che dato un array di interi a[] di lunghezza n>0 alloca e restituisce un nuovo array b[] contenente tutti gli interi distinti che si possono 
ottenere sommando tra loro due elementi di a (compreso un elemento sommato a se stesso). 
Ad esempio

	input: 1 2
	output: 2 3 4   [infatti: 2=1+1, 3=1+2, 4=2+2] 
	input: 1 0 0 1 0 0 1 
	output: 2 1 0   [l'ordine nell'array di output non è importante]
	input: -2 3 1 10 
	output: -4 1 -1 8 6 4 13 2 11 20

Dato che non è possibile stabilire a priori quale sarà la lunghezza dell'array risultato, tale lunghezza deve essere passata per riferimento 
utilizzando il puntatore *size. Non vi preoccupate dell'efficienza della soluzione da voi proposta.

Si scriva poi un programma che invoca somme_distinte passandogli l'array ottenuto convertendo in interi i valori forniti sulla linea di comando e 
successivamente stampa su stderr l'array restituito da somme_distinte. Infine il programma deve stampare su stdout la somma dei valori contenuti 
nell'array restituito da somme_distinte. (Nota: per stampare su stdout si può usare fprintf(stdout,...) oppure semplicemente printf). 
Il programma deve deallocare tutta la memoria utilizzata (verificare con valgrind).*/
void termina(char *msg, int exitnumber){
    perror(msg);
    exit(exitnumber);
}

int *doubleresizeIntArray(int *arr,int size){
    int *tmp = realloc(arr,size*2*sizeof(int));
    if(tmp==NULL) termina("errrore resize array",2);
    return tmp;
}
void pushint(int val,int *arr,int *size,int *length){
    if(*length<*size){
        arr[*length]=val;
    }else{
        arr=doubleresizeIntArray(arr,*size);
        *size=(*size)*2;
        arr[*length]=val;    
    }
    *length+=1;
}

bool findArray(int val,int *arr,int length){
    for(int i = 0;i<length;i++){
        if(val==arr[i]) return true;
    }
    return false;
}

void arrayintPrint(int *arr,int length){
    for (int i=0;i<length;i++){
        printf("%d   ",arr[i]);
    }
}

int *somme_distinte(int *arrayA, int lengthA, int *size, int *lenght){
    int sizeB = 10, lengthB=0;
    int *arrayB= malloc(sizeB*sizeof(int));
    
    if (lengthA<=0) termina("argomenti = 0", 1);
    for(int i=0; i<lengthA;i++){
        for(int j=i;j<lengthA;j++){
            if(!findArray(arrayA[i]+arrayA[j],arrayB,lengthB)) pushint(arrayA[i]+arrayA[j],arrayB,&sizeB,&lengthB);
        }
    }
    *size=sizeB;
    *lenght=lengthB;
    return arrayB;
}


int main(int argc,char *argv[]){
    int size=10,lengthA=0;
    int *arrayA = malloc(size*sizeof(int));
    for(int i=1; i<argc;i++){
        pushint(atoi(argv[i]),arrayA,&size,&lengthA);
        
    }
    int sizeris,lengthris=0;
    int *ris=somme_distinte(arrayA,lengthA,&sizeris,&lengthris);
    int somma=0;
    for(int i=0;i<lengthris;i++){
        fprintf(stderr,"%d\n",ris[i]);
        somma+=ris[i];

    }
    fprintf(stdout,"%d",somma);
    free (arrayA);
    free (ris);
    return 0;
}