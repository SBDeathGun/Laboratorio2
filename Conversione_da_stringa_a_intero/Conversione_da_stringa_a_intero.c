#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
/*Scrivere una funzione

int mioa2toi(char *s, int *n)

che data una stringa s la interpreta come intero decimale (allo stesso modo di atoi). Se la conversione avviene con successo il valore ottenuto deve essere scritto in *n e la funzione deve restituire il valore 0; se invece la conversione non ha successo la variabile n non deve essere modificata e la funzione deve restituire un intero positivo che indica l'errore che si è verificato secondo il seguente schema:

    se la stringa è vuota o contiene solamente spazi 1
    se viene incontrato un carattere che non sia uno fra +-0123456789 (esempio, la stringa "234s7")
    se il segno (+ o -) compare più di una volta, o compare in posizione non corretta (esempio le stringhe "+-34", "-3-4", o "-34+")
    se compare esattamente un segno, ma nessuna cifra (ad esempio la stringa "-")

La conversione deve ignorare eventuali spazi iniziali e deve terminare non appena viene incontrato uno spazio. Quindi l'input "  +34 21" deve restituire il valore 0 (conversione OK) e scrivere in *n il valore 34, mentre l'input "  + 34 21"deve restituire il valore 4 (conversione fallita perché ha letto il segno e poi lo spazio ha fatto interrompere la conversione prima che incontrasse una qualsiasi cifra.

Per quanto riguarda la parte di calcolo, a parte la gestione del segno e degli errori, osservate che se l'input è "XYZ" e la stringa "XY" è stata convertita nel valore t allora "XYZ"vale 10 t + z dove z è il valore tra 0 e 9 rappresentato dal carattere Z. Ricordo che i codice ascii di caratteri tra 0 e 9 sono gli interi tra 48 e 57.

La vostra funzione non può usare atoi, ma la potete usare nel main per verificare la correttezza della vostra funzione, Ad esempio scrivendo:

int main(int argc, char *argv[])
{
  for(int i=1;i<argc;i++) {
    int n, e;
    e = mioatoi(argv[i],&n);
    if(e!=0) printf("Errore conversione: %d\n",e);
    else printf("Mia funzione: %d, libreria: %d\n",n,atoi(argv[i]));
  }
  return 0;
} 

Fate il test con valori sia positivi che negativi! La riga di comando di default non mette gli spazi dentro gli argv[] ma potete inserirli scrivendo la stringa tra doppie virgolette. Quindi scrivendo

mioprog + 123

si ha argv[1]="+" e argv[2]="123", mentre scrivendo

mioprog "+ 123"

si ha argv[1]="+ 123" e non ci sono altri argomenti.*/
void termina();

int  mioatoi(char *str, int*n){
    int converito=0, segno = -1, pos=1 ;
    bool caratteri=false;
    if(strlen(str)==0) return 1;

    for(int i=strlen(str)-1;i>-1;i--){
        if(str[i]==' ') continue;
        if(segno==-1){
            if(str[i]=='+'){
                segno=1;
                continue;
              } else if(str[i]=='-'){
                segno=2;
                continue;
              }
        } else{
            if (str[i]=='+' || str[i]=='-') return 3;
        }
        if(str[i]<48 || str[i]>57 ) return 2;
        caratteri=true;
        converito += (str[i]-48)*pos;
        pos=pos*10;
    }
    if(!caratteri) return 1;
    if(segno==2) converito= converito*-1;
    *n = converito;
    return 0;
}


int main(int argc, char *argv[])
{
  for(int i=1;i<argc;i++) {
    int n, e;
    e = mioatoi(argv[i],&n);
    if(e!=0) printf("Errore conversione: %d\n",e);
    else printf("Mia funzione: %d, libreria: %d\n",n,atoi(argv[i]));
    assert(n==atoi(argv[i]));
  }
  return 0;
} 

