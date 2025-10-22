#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void termina(char *msg, int exitnumber){
    perror(msg);
    exit(exitnumber);
}

int *doubleresizeIntArray(int *arr,int size){
    int *tmp = realloc(arr,size*2*sizeof(int));
    if(tmp==NULL) termina("errrore resize array",2);
    return tmp;
}

void pushint(int val,int **arr,int *size,int *length){
    if(*length<*size){
        (*arr)[*length]=val;
    }else{
        *arr=doubleresizeIntArray(*arr,*size);
        *size=(*size)*2;
        (*arr)[*length]=val;    
    }
    *length+=1;
}

void arrayintPrint(int *arr,int length){
for (int i=0;i<length;i++){
    printf("%d   ",arr[i]);
}
}


int main (int argc,char *argv[]){

    FILE *inputfile = fopen(argv[1],"r");
    
    int n;
    int sizeinput=10,lengthinput=0;
    int *inputarr = malloc(sizeinput*sizeof(int));
    while (true){
        int e = fscanf(inputfile,"%d",&n);
        if(e==EOF) break;
        if(e!=1) termina("errore nella lettura",1);
        printf("n = %d", n);
        pushint(n,&inputarr,&sizeinput,&lengthinput);
}

    for(int i=2; i<argc;i++){
        int multiplo = atoi(argv[i]);
        char *filename= malloc(strlen(argv[1])+3);
        filename[0]='\0';
        strcat(filename,argv[1]);
        strcat(filename,".");
        strcat(filename,argv[i]);
        FILE *output = fopen(filename,"w");
        for(int i = 0 ; i<lengthinput ; i++){
            if((inputarr[i]%multiplo)==0){
                fprintf(output,"%d \n",inputarr[i]);
            }
        }       
        fclose(output);
        free(filename);
    }


    
    free (inputarr);
    fclose(inputfile);
}