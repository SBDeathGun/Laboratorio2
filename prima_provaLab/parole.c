#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe
#include <errno.h>
void termina (char * msg){
    if(errno==1) perror(msg);
    else printf("%s",msg);
    exit(1);
}
typedef struct {
    int primo;
    int secondo;
} coppia;

coppia *create_coppia(int primo, int secondo){
    coppia * res = malloc(sizeof(coppia *));
    res->primo=primo;
    res->secondo=secondo;
    return res;
}

int numOfHastag(char *string){
    int res=0;
    for(int i=0;i<strlen(string);i++){
        if(string[i]=='#') res++;
    }
    return res;
}

void destroyarrcoppia(coppia **arr,int length){
    for(int i=0;i<length;i++){
        free(arr[i]);
    }
    free (arr);
}
void destroyarrstring(char **arr,int length){
    for(int i=0;i<length;i++){
        free(arr[i]);
    }
    free (arr);
}

void mergeStringhe (char *a[],int na, char *b[], int nb){
    char **arrtmp = malloc(sizeof(char *)*(na+nb)); //istanzio un array temporaneo dove storare tutti i valori ordinati
    int r=0 , l=0; //indici per capire a che punto soo arrivato dei due array
    int lengthtmp = 0; 
    while (r!=na && l!=nb){  //finche non ho finito una delle due meta continuo a fare i confronti per capire quale devo mettere
        if(strlen(a[r])<strlen(b[l])){
            arrtmp[lengthtmp] = a[r];
            r++;
        }else{
            arrtmp[lengthtmp] = b[l];
            l++;
        }
        lengthtmp++;
    }
    while (lengthtmp<na+nb){ //copio i restanti valori di uno o dell'altro array
        if(r!=na){
            arrtmp[lengthtmp] = a[r];
            r++;
        }else{
            arrtmp[lengthtmp] = b[l];
            l++;
        }
        lengthtmp++;
    }
    for(int i = 0; i<lengthtmp;i++){ //copio la soluzione nell'array originale usando solo il primo puntatore perche le due meta sono contigue
        a[i] = arrtmp[i];
    }
    free (arrtmp);
}
void mergeSortStringhe(char *a[], int n){
    if(n==1) return;
    int n1= n/2;
    int n2 = n-n1;
    mergeSortStringhe(a,n1); //mergesort  della prima sotto meta
    mergeSortStringhe(&a[n1],n2); //mergesort della seconda meta
    mergeStringhe(a,n1,&a[n1],n2);
}
void mergeCoppie (coppia *a[],int na, coppia *b[], int nb){
    coppia **arrtmp = malloc(sizeof(char *)*(na+nb)); //istanzio un array temporaneo dove storare tutti i valori ordinati
    int r=0 , l=0; //indici per capire a che punto soo arrivato dei due array
    int lengthtmp = 0; 
    while (r!=na && l!=nb){  //finche non ho finito una delle due meta continuo a fare i confronti per capire quale devo mettere
        if(a[r]->primo<b[l]->primo){
            arrtmp[lengthtmp] = a[r];
            r++;
        }else if(a[r]->primo >b[l]->primo){
            arrtmp[lengthtmp] = b[l];
            l++;
        } else{
            if(a[r]->secondo<b[l]->secondo){
                arrtmp[lengthtmp] = a[r];
                r++;
            }else if(a[r]->secondo >b[l]->secondo){
                arrtmp[lengthtmp] = b[l];
                l++;
        }
        }
        lengthtmp++;
    }
    while (lengthtmp<na+nb){ //copio i restanti valori di uno o dell'altro array
        if(r!=na){
            arrtmp[lengthtmp] = a[r];
            r++;
        }else{
            arrtmp[lengthtmp] = b[l];
            l++;
        }
        lengthtmp++;
    }
    for(int i = 0; i<lengthtmp;i++){ //copio la soluzione nell'array originale usando solo il primo puntatore perche le due meta sono contigue
        a[i] = arrtmp[i];
    }
    free (arrtmp);
}
void mergeSortCoppie(coppia *a[], int n){
    if(n==1) return;
    int n1= n/2;
    int n2 = n-n1;
    mergeSortCoppie(a,n1); //mergesort  della prima sotto meta
    mergeSortCoppie(&a[n1],n2); //mergesort della seconda meta
    mergeCoppie(a,n1,&a[n1],n2);
}

char * concat(char *a,char*b){
    char *res = malloc(strlen(a)+strlen(b)+1);
    for(int i= 0; i<strlen(a);i++){
        res[i]=a[i];
    }
    for(int i= 0; i<strlen(b);i++){
        res[i+strlen(a)]=b[i];
    }
    res[strlen(a)+strlen(b)] = '\0';
    return res;
}

int main (int argc,char *argv[]){
    if(argc!=2) termina("il programma deve essere parole nomfile");
    FILE * originale = fopen(argv[1],"r");
    char *nomifile = concat(argv[1],".ordinato");
    FILE * ordinato = fopen(nomifile,"w");
    free(nomifile);
    nomifile = concat(argv[1],".prima");
    FILE *prima = fopen(nomifile,"w");
    free(nomifile);
    nomifile = concat(argv[1],".dopo");
    FILE *dopo = fopen(nomifile,"w");
    free(nomifile);
    int length=0, size=10;
    char **parolefile = malloc(sizeof(char *)*size);
    if(parolefile ==NULL) termina("malloc fallita");
    int e=0;
    while (true){
        char *strfile;
        if(length == size){
            size*=2;
            parolefile = realloc(parolefile,sizeof(char *)*size);
        }
        e = fscanf(originale,"%ms",&strfile);
        if(e==EOF) break;
        if(e!=1) termina("fscanf fallita");
        parolefile[length]= strfile;
        length++;
    }
        mergeSortStringhe(parolefile,length);
    for(int i=0;i<length;i++){
        fprintf(ordinato,"%s \n",parolefile[i]);
    }
    coppia **arrcoppie = malloc(sizeof(coppia *)*length);
    if(arrcoppie ==NULL) termina("malloc fallita");
        for(int i=0;i<length;i++){
        coppia *tmp = create_coppia(numOfHastag(parolefile[i]),strlen(parolefile[i]));
        arrcoppie[i]= tmp;
        fprintf(prima,"%d %d \n",tmp->primo,tmp->secondo);
    }
    mergeSortCoppie(arrcoppie,length);

    for(int i=0;i<length;i++){
        fprintf(dopo,"%d %d\n",arrcoppie[i]->primo,arrcoppie[i]->secondo);
    }

    
    fclose(originale);
    fclose(ordinato);
    fclose(prima);
    fclose(dopo);
    destroyarrcoppia(arrcoppie,length);
    destroyarrstring(parolefile,length);

}