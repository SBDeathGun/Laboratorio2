#! /usr/bin/env python3
"""Linee (12/2/26)

Risolvere in python l'esercizio C della prova in itinere del 5/12/25 (disponibile su moodle). 
A questo scopo definire una classe con i due campi chiave e linea; al posto dell'ABR utilizzare un set() 
per eliminare i duplicati; e una lista per memorizzare gli oggetti e per l'ordinamento finale. 
L'output ottenuto deve essere lo stesso richiesto per il C (si utilizzi il file esempi.zip per i test).

Si consideri la struttura

typedef struct nodo {
  char *chiave;
  char *linea;
  struct nodo *left, *right;
} nodo;

che rappresenta il nodo di un albero binario di ricerca (ABR) contenente i campi chiave e linea . 
All'interno dell'ABR i nodi sono ordinati secondo il campo chiave, se i campi chiave sono uguali l'ordinamento è 
basato sul campi linea; se entrambi sono uguali i nodi sono considerati uguali.

E' obbligatorio usare la funzione

nodo *nodo_crea(char *s1, char *s2)
{
  nodo *a  = malloc(sizeof(*a));
  a->chiave = strdup(s1); // creo una copia di s1 e l'assegno a chiave
  a->linea = strdup(s2); // creo una copia di s2 e l'assegno a linea
  a->left = a->right = NULL;
  return a;
}

per la creazione di un nodo date le due stringhe s1 e s2, e la funzione

void nodo_stampa(const nodo *a, FILE *f) {
  fprintf(f,"<%-14s> <%s>\n",a->chiave,a->linea);
}

per scrivere su f una rappresentazione del nodo a.

Scrivere un programma abr.c che legge dalla linea di comando il nome di un file di testo e partendo da un 
ABR vuoto esegue le seguenti operazioni su tutte le linee del file:

    utilizzando la funzione getline legge la linea copiandola in un buffer b
    esegue b[strlen(b)-1]='\0' per cancellare il carattere \n in fondo alla linea
    utilizzando la funzione strtok tokenizza una copia della linea rispetto al separatore " " (spazio) e salva una copia 
    del secondo token in una stringa z
    aggiunge all'ABR un nuovo nodo n con z come campo chiave e b come campo linea

Casi particolari:

    se il nuovo nodo è uguale ad un nodo già presente nell'albero non deve essere inserito ma semplicemente deallocato 
    e il programma deve stampare un messaggio su stderr
    se non esiste il secondo token. come campo chiave si deve usare la stringa "MANCA"

Dopo l'inserimento nell'ABR il programma deve stampare su stdout l'elenco dei nodi nell'ordine crescente dell'ABR, 
deallocare tutta la memoria utilizzata (verificare con valgrind) e terminare.

Esempio: se il file di input contiene

prima linea
seconda linea
altra linea
lineasenzasecondaparola
linea molto moooooooooooooooooooooooooooooooooooooolto lunga
linea ripetuta più volte
linea ripetuta più volte
linea ripetuta più volte
QUI RICORDA CHE LE MAIUSCOLE PRECEDONO LE MINUSCOLE
linea ripetuta più volte
linea ripetuta più volte
linea ripetuta più volte
la prossima linea è vuota

fine

l'output dovrebbe essere

<MANCA         > <>
<MANCA         > <fine>
<MANCA         > <lineasenzasecondaparola>
<RICORDA       > <QUI RICORDA CHE LE MAIUSCOLE PRECEDONO LE MINUSCOLE>
<linea         > <altra linea>
<linea         > <prima linea>
<linea         > <seconda linea>
<molto         > <linea molto moooooooooooooooooooooooooooooooooooooolto lunga>
<prossima      > <la prossima linea è vuota>
<ripetuta      > <linea ripetuta più volte>

in quanto la quarta e le ultime due righe non hanno il secondo token e quindi la loro chiave è MANCA. I caratteri < e > e gli spazi sono inseriti dalla funzione nodo_stampa() che dovete usare per visualizzare un nodo.

Questo esempio e altri 2 sono disponibili con la rispettiva soluzione nell'archivio esempi.zip"""

import sys, os
class nodo:
    chiave:str
    linea:str
    def __init__(self,chiave,linea):
        self.chiave=chiave
        self.linea=linea
    def __str__(self):
        return (f"<{self.chiave}>   <{self.linea}>")
    def __eq__(self,other):
        return (self.chiave==other.chiave) and (self.linea==other.linea)   
    def __hash__(self):
        return hash((self.chiave, self.linea))
    

def main(argv):
    if len(argv)<2:
        print("argomento non inserito")
    if os.path.isdir(argv[1]):
        print("argomento non valido")
    parole = set()
    with open (argv[1],'r')as file:
        for linee in file:
            if(linee[len(linee)-1]=='\n'):
                linee = linee[0:len(linee)-1]
                arr = linee.split(" ")
                if len(arr)<2:
                    parole.add(nodo("MANCA",linee))
                else:
                    parole.add(nodo(arr[1],linee))
    lista = (list)(parole)
    lista.sort(key=lambda x: (x.chiave,x.linea))
    for elem in lista:
        print (elem)
main(sys.argv)