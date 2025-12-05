#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

void termina(char * msg){
    if(errno!=0) perror(msg);
    else printf("%s",msg);
    exit(1);
}

typedef struct nodo {
    char *chiave;
    char *linea;
    struct nodo *left, *right;
} nodo;

nodo *nodo_crea(char *s1, char *s2)
{
    nodo *a  = malloc(sizeof(*a));
    a->chiave = strdup(s1); // creo una copia di s1 e l'assegno a chiave
    a->linea = strdup(s2); // creo una copia di s2 e l'assegno a linea
    a->left = a->right = NULL;
    return a;
}

void nodo_stampa(const nodo *a, FILE *f) {
    fprintf(f,"<%-14s> <%s>\n",a->chiave,a->linea);
}

void distruggi_nodo(nodo *nodo){
    free(nodo->chiave);
    free(nodo->linea);
    free(nodo);
}

int confronta_nodo(nodo *a,nodo *b){
    int cmpk = strcmp(a->chiave,b->chiave);
    if(cmpk ==0){
        return strcmp(a->linea,b->linea);
    }
    return cmpk;
}

void inserisciAbr(nodo **radice,nodo *nodo){
    if(*radice==NULL) {
        *radice = nodo;
        return;
    }
    int cmp= confronta_nodo(*radice,nodo);
    if(cmp>0){
        inserisciAbr(&((*radice)->left),nodo);
    }
    else if(cmp<0){
        inserisciAbr(&((*radice)->right),nodo);
    }
    else{
        nodo_stampa(nodo,stderr);
        distruggi_nodo(nodo);
    }
}

void visitaInOrder(nodo *radice){
    if(radice ==NULL) return ;
    visitaInOrder(radice->left);
    nodo_stampa(radice,stdout);
    visitaInOrder(radice->right);
}

void distruggi_abr(nodo *radice){
    if(radice ==NULL) return ;
    distruggi_abr(radice->left);
    distruggi_abr(radice->right);
    distruggi_nodo(radice);
}

int main(int argc,char *argv[]){
    if(argc <2) termina("nome file non presente");
    FILE *f = fopen(argv[1],"r");
    size_t size;
    char *b=NULL;
    nodo *radice = NULL;
    char *z;
    ssize_t e=getline(&b,&size,f);
    bool freez;
    while(e!=-1 && errno==0){
        b[strlen(b)-1]='\0';
        char *tmpb = strdup(b);
        strtok(tmpb," ");
        z=strtok(NULL," ");
        if(z==NULL){
            z=strdup("MANCA");
            freez = true;
        }
        nodo *current = nodo_crea(z,b);
        inserisciAbr(&radice,current);

        free(b);
        b=NULL;
        e=getline(&b,&size,f);
        free(tmpb);
        if(freez){
            free(z);
            freez=false;
        }
    }
    free(b);

    visitaInOrder(radice);
    
    distruggi_abr(radice);
    fclose(f);
    return 0;
}
