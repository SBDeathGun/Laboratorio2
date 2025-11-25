#include <stdlib.h>
#include <stdio.h>

int *conta(char*);

void print_array_lettere(int* array){
    for(int i=0;i<26;i++){
        printf("%c,%d \n",97+i,array[i]);
    }
}

int main(int argc,char *argv[]){
    for (int i=1;i<argc;i++){
        int* lettere=conta(argv[i]);
        print_array_lettere(lettere);
    }


}