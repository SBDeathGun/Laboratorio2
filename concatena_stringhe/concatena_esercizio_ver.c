#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

int main(int argc,char *argv[]){
    int len=0, pos=0;
    for(int i=1 ; i<argc;i++){
        len+=strlen(argv[i]);
    }
    char *strfin = malloc(sizeof(char)*(len+1));
    for(int i=1; i<argc; i++){
        for(int j=0;j<strlen(argv[i]);j++){
            strfin[pos] = argv[i][j];
            pos++;
        }
    }
    strfin[pos]='\0';
    printf("%s",strfin);
    free (strfin);
    return 0;
}