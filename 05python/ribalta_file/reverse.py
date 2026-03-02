#! /usr/bin/env python3
"""
Scrivere un programma python reverse.py che invocato dalla linea di comando scrivendo

reverse.py nomefile

legge le linee del file di testo nomefile e le scrive in ordine inverso su un nuovo file chiamato nomefile.rev. 
Ad esempio se il file test.txt contiene le linee

prima riga

questa è la terza riga
la seconda era vuota

deve essere creato il file test.txt.rev contenente

la seconda era vuota
questa è la terza riga

prima riga
"""
import sys , os
def main(argv):
    if len(argv)<2:
        print("argomento non inserito")
    if os.path.isdir(argv[1]):
        print("argomento non valido")
    parole = []
    with open (argv[1],'r') as file:
        for linee in file:
            parole.append(linee)
    parole = parole[::-1]
    with open (argv[1] + ".rev",'w')as rev:
        for linee in parole:
            print(linee,file=rev,end="")
    




main(sys.argv)