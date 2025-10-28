#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe

/*
void push (xxx val,xxx **arr,int *length, int *size){
    if((*length) == (*size)) {
        (*arr) = realloc(*arr,(*size)*2*sizeof(xxx));
        *size=*size*2;
    }
    (*arr)[*length]= val;
    *length = (*length)+1;
}*/

void merge (int a[],int na, int b[], int nb){
    int *arrtmp = malloc(sizeof(int )*(na+nb)); //istanzio un array temporaneo dove storare tutti i valori ordinati
    int r=0 , l=0; //indici per capire a che punto soo arrivato dei due array
    int lengthtmp = 0; 
    while (r!=na && l!=nb){  //finche non ho finito una delle due meta continuo a fare i confronti per capire quale devo mettere
        if(a[r]<b[l]){
            arrtmp[lengthtmp] = a[r];
            r++;
        }else{
            arrtmp[lengthtmp] = b[l];
            l++;
        }
        lengthtmp++;
    }
    while (lengthtmp<na+nb){ //copio i restanti valori di uno o dell'altro array
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

void mergeSort(int a[], int n){
    if(n==1) return;
    int n1= n/2;
    int n2 = n-n1;
    mergeSort(a,n1); //mergesort  della prima sotto meta
    mergeSort(&a[n1],n2); //mergesort della seconda meta
    merge(a,n1,&a[n1],n2);
}

//merge sort2 da non usare
/*
void merge2 (void *a,int na, void *b, int nb, int (*f)(void *,void*)){
    void *arrtmp = malloc(sizeof(int )*(na+nb)); //istanzio un array temporaneo dove storare tutti i valori ordinati
    int r=0 , l=0; //indici per capire a che punto soo arrivato dei due array
    int lengthtmp = 0; 
    while (r!=na && l!=nb){  //finche non ho finito una delle due meta continuo a fare i confronti per capire quale devo mettere
        if(f(a[r],b[l])){
            arrtmp[lengthtmp] = a[r];
            r++;
        }else{
            arrtmp[lengthtmp] = b[l];
            l++;
        }
        lengthtmp++;
    }
    while (lengthtmp<na+nb){ //copio i restanti valori di uno o dell'altro array
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

void mergeSort2(void *a[], int n, int (*f)(void *,void*)){
    if(n==1) return;
    int n1= n/2;
    int n2 = n-n1;
    mergeSort2(a,n1,f); //mergesort  della prima sotto meta
    mergeSort2(&a[n1],n2,f); //mergesort della seconda meta
    merge2(a,n1,&a[n1],n2, f);
}

int compare(void *aa,void *bb){
    int *a = (int*)aa;
    int *b = (int*)bb;
    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
} */

int main (void){
    int arr[9]={4,5,8,7,100,8,9,-1,5};
    mergeSort(arr,9);
    for(int i=0; i<9;i++){
        printf("%d   ",arr[i]);
    }
    return 0;
}