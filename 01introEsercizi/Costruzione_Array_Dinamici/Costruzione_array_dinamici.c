/*
Scrivere un programma C che legge un intero N e costruisce i seguenti due array di interi:

    l'array a[] contente i numeri tra 1 e N che sono multipli 3 ma non di 5: 3, 6, 9, 12, 18, 21, 24, 27, 33, ...

    l'array b[] contente i numeri tra 1 e N che sono multipli 5 ma non di 3: 5, 10, 20, 25, 35, 40, 50, ...

Al termine della costruzione deve stampare lunghezza e la somma gli elementi degli array a e b, deve poi deallocarli e terminare.

Ad esempio per N=100 i due array risultano

a = [3, 6, 9, 12, 18, 21, 24, 27, 33, 36, 39, 42, 48, 51, 54, 57, 63, 66, 69, 72, 78, 81, 84, 87, 93, 96, 99]

b = [5, 10, 20, 25, 35, 40, 50, 55, 65, 70, 80, 85, 95, 100]

e di conseguenza l'output dovrebbe essere


lunghezza a[] = 27,  somma a[] = 1368
lunghezza b[] = 14,  somma b[] = 735

Per N=99999 l'output dovrebbe essere

lunghezza a[] = 26667,  somma a[] = 1333366668
lunghezza b[] = 13333,  somma b[] = 666633335

Eseguire il programma anche utilizzando valgrind verificando che non stampi nessun messaggio d'errore e al termine visualizzi il messaggio

HEAP SUMMARY:
 in use at exit: 0 bytes in 0 blocks

*/
#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe

void termina(char *msg,int exitcode){
    perror(msg);
    exit(exitcode);
}
void resize(int *arr,int size){


}

int main(int argc,char *argv[]){
    int n;
    if(argc>0){
        n = atoi(argv[1]);
    } else{
        int answ = scanf("%d",&n);
        if(answ<1) {
            termina("non hai messo un input da tastiera",1); 
        }
    } 
    int sizeTre=10, lenghtTre=0;
    int *arrTre = malloc(sizeof(int)*sizeTre);
    int sizeCinque=10 , lenghtCinque=0;
    int *arrCinque = malloc(sizeof(int)*sizeCinque);
    int sommaTre=0, sommaCinque=0;

    for(int i=0;i<=n;i++){
        if(i%3==0 && i%5!=0){
            sommaTre+=i;
            if(lenghtTre<sizeTre){
                arrTre[lenghtTre] = i;
            }else{
                arrTre = realloc(arrTre,2*sizeTre*sizeof(int));
                sizeTre=sizeTre*2;
                if(arrTre==NULL){
                    termina("errore nel realloc",2);
                }
                arrTre[lenghtTre] = i;
            }
            lenghtTre++;
        }
        else if(i%3!=0 && i%5==0){
            sommaCinque+=i;
            if(lenghtCinque<sizeCinque){
                arrCinque[lenghtCinque] = i;
            }else{
                arrCinque = realloc(arrCinque,sizeCinque*2*sizeof(int));
                sizeCinque=sizeCinque*2;
                if(arrCinque==NULL){
                    termina("errore nel realloc",2);
    }
                arrCinque[lenghtCinque] = i;
            }
            lenghtCinque++;
        }
    }
    printf("numeri dentro arrTre[ ");
    for(int i=0;i<lenghtTre;i++){
        printf("%d ",arrTre[i]);
    }
    printf("]\n");

    printf("numeri dentro arrCinque[");
    for(int i=0;i<lenghtCinque;i++){
        printf("%d ",arrCinque[i]);
    }
    printf("]\n");
    
    printf("\nlunghezza arrTre: %d \n lunghezza arrCinque: %d\n \n",lenghtTre,lenghtCinque);
    printf("somma arrTre: %d \n somma arrCinqur: %d \n",sommaTre,sommaCinque);
    free(arrTre);
    free(arrCinque);
    return 0;
}
