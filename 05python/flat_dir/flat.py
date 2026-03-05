#! /usr/bin/env python3

import os,sys
def flat(srcpdest,dest,giavisti=None):
    if giavisti==None:
        giavisti=set()
    for file in os.listdir(srcpdest):
        if os.path.isdir(os.path.join(srcpdest,file)):
            nomereale = os.path.realpath(srcpdest)
            if nomereale in giavisti:
                continue
            os.link(nomereale,dest)
            giavisti.add(nomereale)
            flat(nomereale,dest,giavisti)



def main(argv):
    if len(argv)<3:
        print("errore")
        exit()
    src = argv[1]
    dest = argv[2]
    if os.path.exists(os.path.join(os.path.abspath(dest),"dest")):
        exit(1)
    os.mkdir(os.path.join(os.path.abspath(dest),"dest"))
    flat(src,os.path.join(os.path.abspath(dest),"dest"))



main(sys.argv)