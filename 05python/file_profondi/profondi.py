#! /usr/bin/env python3
import sys,os
"""esplora la directory nomedir e le sue sottodirectory e visualizza l'elenco dei file che si trovano a 
maggiore profondità nell'albero con radice nomedir ordinando l'elenco per dimensione di file crescente. 
Ad esempio, se la directory nomedir ha la seguente struttura:
nomedir
├── dir0_d1
│   ├── dir0_d0
│   │   ├── filea0.txt
│   │   └── filea1.txt
│   ├── file0.txt
│   └── file1.txt
├── dir1_d1
│   ├── dir1_d0
│   │   ├── fileb0.txt
│   │   └── fileb1.txt
│   ├── file0.txt
│   └── file1.txt
├── file0.txt
└── file1.txt
l'output deve consistere dei 4 file filea0.txt, filea1.txt, fileb0.txt, fileb1.txt ordinati per dimensione di file crescente.
"""
class MioFile:
    path:str
    nomefile:str
    dim:int
    isdir:bool
    def __init__(self,path:str,nomefile:str,dim:int):
        self.path=path
        self.nomefile = nomefile
        self.dim=dim

    def __str__(self):
        return f"{self.path} , {self.nomefile} , {self.dim} "
    
    def __lt__(self, other):
        if self.dim<other.dim:
            return True
        elif self.dim>other.dim:
            return False
        return self.nomefile>other.nomefile


def profondita_cartella (sorgente,giavisti=None,profondita=0):
    if giavisti is None:
        giavisti = set()
    dirindir=False
    deepest=(0,[])
    files=[]
    listfile = os.listdir(os.path.abspath(sorgente))
    for file in listfile:
        if os.path.isdir(os.path.join(sorgente,file)):
            dirindir=True
            nomereale = os.path.realpath(os.path.join(sorgente,file))
            if nomereale in giavisti:
                continue
            giavisti.add(nomereale)
            new = profondita_cartella(os.path.join(sorgente,file),giavisti,profondita+1)
            if new[0]>deepest[0]:
                deepest=new
            elif new[0]==deepest[0]:
                deepest[1].extend(new[1])
        else:
            files.append(MioFile(os.path.join(sorgente,file),file,os.path.getsize(os.path.join(sorgente,file))))
    if not dirindir:
        return (profondita,files)
    else:
        return deepest





def main(argv):
    if len(argv)<2:
        print("errore1")
    if not os.path.isdir(os.path.abspath(argv[1])):
        print("errore2")
    a = profondita_cartella(argv[1])
    print(a[0])
    a[1].sort()
    for f in a[1]:
        print(f)


main(sys.argv)