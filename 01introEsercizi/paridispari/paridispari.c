#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe


/*int* resize(int *n,int size){
    n=realloc(n,2*size*sizeof(int));
    return n;
}*/


void termina(char *msg,int errorcode){
    perror(msg);
    exit(errorcode);
}

int main(int argc,char *argv[]){
    FILE *pari = fopen("pari.txt","w");
    int sizepari=10 , sizedispari=10;
    int lenghtpari = 0,lenghtdispari = 0;
    int *pariArray = malloc(sizepari*sizeof(int));
    int *dispariArray = malloc(sizedispari*sizeof(int));
    int sommapari = 0,sommadispari = 0;
    if (pari==NULL){
        termina("errore nell'apertura file pari.txt",1);
    }    
    FILE *dispari = fopen("dispari.txt","w");
    if (pari==NULL){
        termina("errore nell'apertura file dispari.txt",1);
    }
    for (int i=0; i<argc; i++){
        int number = atoi(argv[i]);
        if(number%2==0){
            fprintf(pari,"%d\n",number);
            sommapari+=number;
            if(lenghtpari<sizepari){
                pariArray[lenghtpari]=number;
                lenghtpari++;
            }else{
                pariArray = realloc(pariArray,2*sizepari*sizeof(int));
                if (pariArray==NULL){
                    termina("realloc fallita",1);
                }
                pariArray[lenghtpari]=number;
                lenghtpari++;
            }
        } else{
            fprintf(dispari,"%d\n",number);
            sommadispari+=number;
            if(lenghtdispari<sizedispari){
                pariArray[lenghtdispari]=number;
                lenghtdispari++;
            }else{
                dispariArray = realloc(dispariArray,2*sizedispari*sizeof(int));
                if (dispariArray==NULL){
                    termina("realloc fallita",1);
                }
                dispariArray[lenghtdispari]=number;
                lenghtdispari++;
            }
        }

    }
    //fwrite(pariArray,sizeof(int),lenghtpari,pari);
    //fprintf(dispariArray,sizeof(int),lenghtdispari,dispari);
    fclose(pari);
    fclose(dispari);
    printf("pari: %d\n",sommapari);
    printf("dispari: %d",sommadispari);
    free(dispariArray);
    free(pariArray);
    return 0;
}



