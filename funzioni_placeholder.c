#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe


void push (xxx val,xxx **arr,int *length, int *size){
    if((*length) == (*size)) {
        (*arr) = realloc(*arr,(*size)*2*sizeof(xxx));
        *size=*size*2;
    }
    (*arr)[*length]= val;
    *length = (*length)+1;
}

