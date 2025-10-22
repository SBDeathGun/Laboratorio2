#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
/*Ordina stringhe per lunghezza (17/10/25)

Scrivere una funzione

void mergesort(char *a[], int n)

ch dato un array a[] di n stringhe le ordina in ordine di lunghezza crescente. 
Suggerimento si modifichi le funzioni mergesort/merge viste a lezione in mergeSort.c, 
osservando che c'è un'unica istruzione nella quale gli elementi di a[] vengono confrontati. 
Dato che vogliamo ordinare le stringhe per lunghezza, per confrontare a[i] e c[j] il confronto deve essere fatto tra i valori strlen(a[i]) e strlen(c[j])

Scrivere poi un programma ostringhe che ordina per lunghezza crescente gli elementi di argv e stampa le stringhe ordinate sul terminale. 
Ad esempio, scrivendo

ostringhe due ricorsione dieci casa Po

deve essere visualizzato l'elenco

Po
due
casa
dieci
ricorsione

Verificate con valgrind il corretto uso e deallocazione della memoria*/
// [1 , 7 ,8, 5, 2 ,4 ,2 ,1] , n = 8 n1 = 4 n2= 4

//funzione che implementa il merge
void merge (char *a[],int na, char *b[], int nb){
    char **arrtmp = malloc(sizeof(char *)*(na+nb)); //istanzio un array temporaneo dove storare tutti i valori ordinati
    int r=0 , l=0; //indici per capire a che punto soo arrivato dei due array
    int lengthtmp = 0; 
    while (r!=na && l!=nb){  //finche non ho finito una delle due meta continuo a fare i confronti per capire quale devo mettere
        if(strlen(a[r])<strlen(b[l])){
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

void mergeSort(char *a[], int n){
    if(n==1) return;
    int n1= n/2;
    int n2 = n-n1;
    mergeSort(a,n1); //mergesort  della prima sotto meta
    mergeSort(&a[n1],n2); //mergesort della seconda meta
    merge(a,n1,&a[n1],n2);
}

void stampa_array(char *a[],int length, FILE *f){
    for(int i = 0; i<length;i++)
        fprintf(f,"%s \n", a[i]);
}

int main(int argc, char *argv[]){
    char **arrayOrdinato;
    arrayOrdinato = &argv[1];
    mergeSort(arrayOrdinato,argc-1);
    stampa_array(arrayOrdinato,argc-1,stdout);
    return 0;
}