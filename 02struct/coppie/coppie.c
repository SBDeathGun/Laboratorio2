#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
/*Coppie (21/10/25)

Facendo riferimento alla struct coppia vista nell'esempio array_coppie.c, 
scrivere un programma che richiede sulla linea di comando un numero pari 2n di interi, 
crea un array di n puntatori a coppie, le ordina per differenza di elementi crescente e stampa e dealloca l'array ordinato.
Ad esempio, scrivendo

coppie 2 2 3 4 7 0 2 1

deve creare l'array di coppie (2 2) (3 4) (7 0) (2 1), che ordinato per differenza crescente risulta (3 4) (2 2) (2 1) (7 0), 
essendo le differenze rispettivamente -1, 0, 1, 7.*/
typedef struct {
 int primo;
 int secondo;
}coppie;

coppie constructorcoppie(int primo, int secondo){
    coppie a;
    a.primo=primo;
    a.secondo=secondo;
    return a;
}

void stampaArrCoppie(coppie a[], int length){
    for (int i=0; i<length;i++){
        printf("primo : %d    secondo: %d\n",a[i].primo,a[i].secondo);
    }
}

void termina(char *msg);

void merge (coppie a[],int na, coppie b[], int nb){
    coppie *arrtmp = malloc(sizeof(coppie)*(na+nb));
    int r=0 , l=0; 
    int lengthtmp = 0; 
    while (r!=na && l!=nb){  
        if(a[r].primo-a[r].secondo<b[l].primo-b[l].secondo){
            arrtmp[lengthtmp] = a[r];
            r++;
        }else{
            arrtmp[lengthtmp] = b[l];
            l++;
        }
        lengthtmp++;
    }
    while (lengthtmp<na+nb){ 
        if(r!=na){
            arrtmp[lengthtmp] = a[r];
            r++;
        }else{
            arrtmp[lengthtmp] = b[l];
            l++;
        }
        lengthtmp++;
    }
    for(int i = 0; i<lengthtmp;i++){ //copio la soluzione nell'array originale usando solo il primo puntatore perche le due meta sono contigue
        a[i] = arrtmp[i];
    }
    free (arrtmp);
}

void mergeSort(coppie a[], int n){
    if(n==1) return;
    int n1= n/2;
    int n2 = n-n1;
    mergeSort(a,n1); //mergesort  della prima sotto meta
    mergeSort(&a[n1],n2); //mergesort della seconda meta
    merge(a,n1,&a[n1],n2);
}

int main(int argc, char * argv[]){
    if((argc-1)%2 != 0) termina ("elementi non pari");
    int size=10, length=0;
    coppie *arraycoppie= malloc(sizeof(coppie)*size);
    for(int i=1;i<argc;i=i+2){
        if(length<size){
            arraycoppie[length]= constructorcoppie(atoi(argv[i]),atoi(argv[i+1]));
        }else{
            size=size*2;
            arraycoppie = realloc(arraycoppie, sizeof(coppie)*size);
            if(arraycoppie==NULL) termina("errore nella realloc");
            arraycoppie[length] = constructorcoppie(atoi(argv[i]),atoi(argv[i+1]));
        }
        length++;
    }
    mergeSort(arraycoppie,(argc-1)/2);
    stampaArrCoppie(arraycoppie, length);
    free ( arraycoppie);
    return 0;
}

void termina(char*msg){
    if(errno!=0) perror(msg);
    else printf("%s", msg);
    exit(1);
}
