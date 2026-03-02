#! /usr/bin/env python3
"""Scrivere un programma python ordina.py che invocato dalla linea di comando scrivendo

reverse.py nomefile

legge le linee del file di testo nomefile e le scrive in ordine di lunghezza decrescente su un nuovo file chiamato nomefile.dec. 
Ad esempio per il file test.txt dell'esercizio precedente dovrebbe essere creato un file test.txt.dec contente le linee:

questa è la terza riga
la seconda era vuota
prima riga


Nota: dopo aver letto le linee in un array, ordinarlo mediante il metodo sort utilizzando come chiave la 
lunghezza della stringa."""
import sys, os

def main(argv):
    if len(argv)<2:
        print("argomento non inserito")
    if os.path.isdir(argv[1]):
        print("argomento non valido")
    parole = []
    with open (argv[1],'r')as file:
        for linee in file:
            parole.append(linee)
    parole.sort(key=len, reverse=True)
    with open(argv[1] + ".dec",'w')as dec:
        for linee in parole:
            print(linee, file=dec,end="")
    





main(sys.argv)