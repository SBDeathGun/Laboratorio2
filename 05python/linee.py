import os
import sys


"""Scrivere uno script python linee.py che prende in input sulla linea di comando il nome di una directory dir, un intero positivo num, e una stringa pattern.

Lo script deve visitare tutti i file presenti nella directory dir e sue sottodirectory mettendoli in una lista di nome tutti utilizzando la metodologia vista a lezione. 
Per ogni file lo script deve memorizzare in una classe apposita almeno il nome del file e le prime num linee di testo del file, dove num è il parametro intero positivo passato 
sulla linea di comando. Attenzione che il file potrebbe avere meno di num linee di testo, in tal caso memorizzate quelle che ci sono; il file potrebbe anche essere vuoto, 
in tal caso non deve essere memorizzata nessuna linea.

Successivamente, lo script deve creare una nuova lista di nome pochi contenente solamente i file tali che una delle righe memorizzate contiene la stringa pattern. 
Si noti che per verificare se una stringa è contenuta in un altra, si può usare la keyword in, ad esempio:

>>> "remo" in "saremo felici" 
True
>>> "ramo" in "saremo felici"
False

Infine lo script deve stampare i file della lista pochi ordinati con il seguente criterio:

    lessicograficamente rispetto alla linea contenente la stringa pattern; se ci sono più linee che contengono pattern si consideri quella che si trova prima nel file
    a parità di linea contente la stringa pattern si consideri l'ordine lessicografico dei nomi

La stampa di ogni file deve consistere in almeno:

    il nome del file
    le massimo num linee memorizzate insieme al file

Obbligatorio:

    definire in maniera appropriata una classe nel quale memorizzare il nome del file e le linee di testo
    effettuare l'ordinamento della lista pochi definendo in maniera opportuna il metodo __lt__ dentro tale classe
    effettuare la stampa dei file definendo in maniera opportuna il metodo __str__ dentro tale classe.
"""




class MioFile:
    path:str
    nlinee:int
    linee:str
    patternline:str
    def __init__(self,path,num, pattern):
        self.path=path
        self.nlinee , self.linee =self.prendilinee(num)
        self.patternline = None
        for linea in (self.linee.split('\n')):
            if pattern in linea:
                self.patternline = linea
                break
        
    def prendilinee(self,num):
        with open(self.path,'r')as file:
            i=0
            acc=""
            for linea in file:
                if i<num:
                    acc+=linea
                    i+=1
                else:
                    break
            return  i , acc



    
    
    
    
    
    def __str__(self):
        return f"{self.path} , {self.nlinee} \n {self.linee} \n"
    
    def __lt__(self,other:MioFile):
        if(self.patternline != None and other.patternline != None):
            if self.patternline<=other.patternline:
                return True
            else:
                return False






def creaLista(dir:str,num:int,pattern:str,giavisti:set[str]=[],res:list[MioFile]=[]):

    files = os.listdir(os.path.abspath(dir))
    for file in files:
        nomecompleto = os.path.join(dir,file)
        if os.path.isdir(nomecompleto):
            nomereale = os.path.realpath(nomecompleto)
            if nomereale in giavisti:
                continue
            giavisti.append(nomereale)
            creaLista(os.path.join(dir,file),num,pattern,giavisti,res)
        else:
            res.append(MioFile(os.path.join(dir,file),num,pattern))
    return res

            
            


    



def main (argv):
    if len(argv)< 4:
        print("il programma deve avere 3 argomenti: dir num e pattern")
        exit()
    if os.path.isdir(argv[1]) and (int)(argv[2])<0 and type(argv[3] is str):
        print("argomenti errati")
        exit()
    filelist = creaLista(os.path.abspath(argv[1]),(int)(argv[2]),argv[3])
    for elem in filelist:
        print (elem)
    pochi = []
    for elem in filelist:
        if elem.patternline != None:
            pochi.append(elem)
    pochi.sort()
    print(f"stampando pochi {len(pochi)} \n\n\n\n")
    for elem in pochi:
        print(elem)


main(sys.argv)