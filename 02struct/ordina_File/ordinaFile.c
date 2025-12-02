#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
/*Ordinamento di file (21/10/24)

Scrivere un programma che legge dalla riga di comando un elenco di nomi di file e stampa l'elenco di questi file ordinati per dimensione decrescente,
i file con la stessa dimensione devono essere ordinati lessicograficamente.

Nota: per eseguire dei test con molti nomi di file osserviamo che la linea di comando linux ha un meccanismo di espansione dei pattern
che viene effettuato prima di invocare i comandi. Ad esempio, se scriviamo ordina *.c *.txt al programma ordina, attraverso argc e argv,
vengono passati tutti i file che hanno estensione .c e .txt

Questo esercizio è stato svolto in aula nel file array_file.c 
esclusa la parte di ordinamento che potete svolgere modificando opportunamente il mergesort visto in array_capitali_funz.c*/

typedef struct file{
    long dim;
    char *filename;
}filestruct;

void termina(char *msg){
    perror(msg);
    exit(1);
}

filestruct *createfilestruct(long dim, char* filename){
    filestruct *tmpfile = malloc(sizeof(filestruct));
    tmpfile->dim=dim;
    tmpfile->filename=strdup(filename);
    return tmpfile;
}

void destroyfilestruct(filestruct *file){
    free(file->filename);
    free(file);
}

void stampa_filestruct(filestruct *file){
    printf("%s     %ld\n",file->filename,file->dim);
}

void push(filestruct *val , filestruct ***arr,int *length, int *size){
    if(*length < *size){
        (*arr)[*length] = val;
        
    } else{
        *arr =  realloc(*arr,*size*2*sizeof(**arr));
        if(*arr==NULL) termina("realloc falliata");
        *size = *size*2;
        (*arr)[*length] = val;
    }
    *length+=1;
}

void stampa_array_file(filestruct **arr,int length){
    for(int i=0; i<length;i++){
        stampa_filestruct(arr[i]);
    }
}

int compare(const filestruct **primo,const filestruct **secondo){
    if((*primo)->dim>(*secondo)->dim){
        return -1;
    }else if((*primo)->dim<(*secondo)->dim){
        return 1;
    }else{
        return strcmp((*primo)->filename,(*secondo)->filename);
    }


}

int main(int argc, char **argv){
    int size = 10,length=0;
    filestruct **arrOfFile = malloc(sizeof(filestruct *)*size);

    for(int i=1;i<argc;i++){
        FILE *fp = fopen(argv[i],"r");
        fseek(fp,0,SEEK_END);
        push(createfilestruct(ftell(fp),argv[i]),&arrOfFile,&length,&size);
        fclose(fp);
    }
    stampa_array_file(arrOfFile,length);
    printf("--------------------------------\n");
    qsort(arrOfFile,length,sizeof(filestruct *),(__compar_fn_t)&compare);
    stampa_array_file(arrOfFile,length);
    for(int i =0; i<length;i++){
        destroyfilestruct(arrOfFile[i]);
    }
    free(arrOfFile);
    return 0;
}