#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/*Reverse di stringhe (3/10/25)

Scrivere un programma reverse che stampa sullo schermo gli argomenti passati sulla linea di comando 
(escluso il nome del programma) con i caratteri in ordine inverso. Ad esempio, scrivendo

reverse sole azzurro 123

l'output dovrebbe essere

elos orruzza
321

Si noti che per stampare i caratteri in ordine inverso potete 
1. creare la stringa ribaltata e poi stamparla con printf con modificatore %s, oppure 
2. stampare i caratteri da destra a sinistra uno alla volta con il modificatore %c.*/

void stampaCharReverse(char *str){
    for(int i=strlen(str)-1;i>=0;i--){
        printf("%c",str[i]);
    }
}

char* strReverse(char *str){
    char *newstr = malloc(sizeof(char)*strlen(str)+1);
    int j=0;
    for(int i=strlen(str)-1;i>=0;i--){
        newstr[i]=str[j];
        j++;
    }
    newstr[j]='\0';
    return newstr;
}

int main(int argc,char *argv[]){
    for(int i = 1; i<argc;i++){
        printf("stringa stampata char a char: ");
        stampaCharReverse(argv[i]);
        char *revstr = strReverse(argv[i]);
        printf("\n stringa Reversata e poi stampata: %s \n",revstr);
        free (revstr);
    }
    return 0;
}