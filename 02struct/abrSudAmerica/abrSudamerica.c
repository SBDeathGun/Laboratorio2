#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<errno.h>
/*ABR Città Sud America (7/11/25)

Questo esercizio richiede di creare un ABR contenente le città del Sud America predendole da file sudAmerica.txt. 
Si proceda nel seguente modo. Nel programma abr_capitali si cambi la definizione di capitale nella seguente

typedef struct capit {
  char *nome;
  char *nazione;
  int kpop;
  struct capit *left, *right;
} capitale;

e si modifichino di conseguenza le funzioni capitale_stampa, capitale_crea, e capitale_distruggi. 
Si cancelli la funzione capitale_leggi e si modifichi la funzione crea_abr in modo che il ciclo while legga il file utilizzando getline ad ogni iterazione 
e per ogni linea utilizzando strtok crei e inserisca nell'ABR un nodo contenente i dati della città letta (si veda legginomi.c per un esempio).*/

typedef struct capit {
    char *nome;
    char *nazione;
    int kpop;
    struct capit *left, *right;
} capitale;

void termina(char *msg){
    if(errno!=0) perror(msg);
    else printf("%s", msg);
    exit(1);
}

capitale *capitale_crea(char *str){
    capitale * c = malloc(sizeof(capitale));
    c->nome = strdup(strtok(str,";\n"));
    c->kpop = atoi(strtok(NULL,";\n"));
    c->nazione = strdup(strtok(NULL,";\n"));
    return c;

}

void capitale_distruggi(capitale *c){
    if(c==NULL) return;
    free(c->nome);
    free(c->nazione);
    capitale_distruggi(c->left);
    capitale_distruggi(c->right);
    free(c);
    return;
}

int confronta_capitale(capitale *c1,capitale *c2){
    return c1->kpop-c2->kpop;
}

void capitale_stampa(capitale *c,FILE* f){
    fprintf(f,"%s , %d , %s\n",c->nome,c->kpop,c->nazione);
}
void inserisciAbrCapitale(capitale **radice,capitale *nodo){
    if(*radice==NULL) {
        *radice = nodo;
        return;
    }
    if(confronta_capitale(*radice,nodo)<0){
        /*if((*radice)->left==NULL){
            (*radice)->left = nodo;
            return;
        }*/
        inserisciAbrCapitale(&((*radice)->left),nodo);
    }
    else{
        /*if((*radice)->right==NULL){
            (*radice)->right = nodo;
            return;
        }*/
        inserisciAbrCapitale(&((*radice)->right),nodo);
    }

}

capitale *creaAbrCapitale(FILE* f){
    size_t size;
    char *str=NULL;
    capitale *radice=NULL;

    ssize_t e=getline(&str,&size,f);
    while(e!=-1 && errno==0){
        capitale *nodo = capitale_crea(str);
        inserisciAbrCapitale(&radice,nodo);
        e=getline(&str,&size,f);
        
    }
    free(str);
    if (errno<0) termina("errore lettura");
    return radice;
}

void stampaAbr(capitale *radice,FILE* f){
    if(radice==NULL) return;
    stampaAbr(radice->left,f);
    capitale_stampa(radice,f);
    stampaAbr(radice->right,f);
}


int main(int argc,char *argv[]){
    if(argc<2) termina("manca argomento");
    FILE *input=fopen(argv[1],"r");
    capitale *radice =creaAbrCapitale(input);
    fclose(input);
    stampaAbr(radice,stdout);

    return 0;
}