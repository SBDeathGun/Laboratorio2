#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
 
char *concat(char *str1,char *str2){
    int len1 =strlen(str1);
    int selector = 0;
    str1= realloc(str1, sizeof(char)*(len1 + strlen(str2)+1));
    for(int i =len1;i<len1+strlen(str2);i++){
        str1[i] = str2[selector];
        selector++;
    }
    str1[len1+selector]='\0';
    return str1;
}




int main(int argc, char *argv[]){
    char *strfin = strdup(argv[1]);
    if(argc>1){
        for(int i=2;i<argc;i++){
            strfin = concat(strfin,argv[i]);
        }
    }
    printf("%s",strfin);
    free (strfin);
    
    return 0;
}



/*domande per il prof 
 con questo main 

void concat(char *str1,char *str2){
    int len1 =strlen(str1);
    int selector = 0;
    str1= realloc(str1, sizeof(char)*(len1 + strlen(str2)+1));
    for(int i =len1;i<len1+strlen(str2);i++){
        str1[i] = str2[selector];
        selector++;
    }
    str1[len1+selector]='\0';
    return str1;
}

int main(int argc, char *argv[]){
    char *strfin = strdup(argv[1]);
    if(argc>1){
        for(int i=2;i<argc;i++){
            concat(strfin,argv[i]);
        }
    }
    printf("%s",strfin);
    free (strfin);

    return 0;
}
    valgrind si lamentava 
*/