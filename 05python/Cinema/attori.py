#! /usr/bin/env python3
import sys,os

def main(argv):
    if not os.path.exists(os.path.abspath(argv[1])):
        print("erorre")
        exit()
    if os.path.isdir(os.path.abspath(argv[1])):
        print("errorw")
        exit()
    persone = {}
    attrici = []
    with open (argv[1],'r')as f:
        for line in f:
            line = line.split('\t')
            nome = line[1]
            ruoli = line[4].split(',')
            for r in ruoli:
                if persone.get(r)==None:
                    persone[r] = [nome]
                else:
                    persone[r].append(nome)
                if r=="attrici":
                    attrici.append(nome)
    with open("attrici.txt",'w') as a:
        for r in persone.keys():
            with open(r +".txt",'w') as f:
                persone[r].sort()
                for p in persone[r]:
                    print(p,file=f)
                    if(r=="Actress"):
                        print(p,file=a)



                
main(sys.argv)