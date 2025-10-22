#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe


char *z ="efiohufeogkusn"; //modo sbagliato per fare le stringhe perche da una stringa immutabile
char *str = strdup("fhjyfvjfvjgvjg"); // questa fa una malloc di lenght+1 perche convenzionalmente la fine della stringa c'e il byte \0