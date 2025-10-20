/*
Ribalta elenco (17/10/25)

Scrivere un programma che invocato dalla linea di comando scrivendo

    main infile outfile

legge tutte le stringhe dal file di testo *infile* e le riscrive su *outfile* **in ordine inverso**. Ad esempio, se *infile* contiene
```
Mattarella
Napolitano
Ciampi
Scalfaro
Cossiga
Pertini
```
il file *outfile* deve contenere
```
Pertini
Cossiga
Scalfaro
Ciampi
Napolitano
Mattarella
```
Leggere le stringhe del file di input utilizzando `fscanf` for formato `%ms` in modo da non preoccuparvi della loro lunghezza. Dato però che non ci sono limitazioni al numero totale di stringhe, per poterle scrivere in ordine inverso dovete prima memorizzarle in un array di stringhe la cui dimensione deve aumentare dinamicamente. 

Verificate con valgrind il corretto uso e deallocazione della memoria */
#define _GNU_SOURCE
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void termina (char *msg,int exitnumber);

int main(int argc, char* argv[]){
    FILE *infile= fopen(argv[1],"r");
    FILE *outfile= fopen(argv[2],"w");
    int e=0;
    int size=10, length=0;
    char **arrStr = malloc(sizeof(char*)*size);
    while(true){
        e = fscanf(infile,"%ms",&arrStr[length]);
        if(e==EOF) break;
        length++;
        if (length == size){
            arrStr = realloc(arrStr, size*2*sizeof(char*));
            size=size*2;
            if(arrStr==NULL) termina("errore realloc", 1 );
        }
    }

    for(int i=length-1;i>=0;i--){
        e = fprintf(outfile,"%s\n",arrStr[i]);
    }
    
    for(int i = 0 ; i<length;i++){
        free(arrStr[i]);
    }
    fclose(infile);
    fclose(outfile);
    free (arrStr);
    return 0;
}


void termina(char *msg,int exitnumber){
    perror (msg);
    exit(exitnumber);
}