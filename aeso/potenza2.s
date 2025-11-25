.global main
.global pow
.extern printf

.text

main:
    @ 1. ALLINEAMENTO STACK
    @ Salviamo r4 (registro preservato) e lr (link register)
    @ Questo sposta lo stack di 8 byte (perfetto per printf)
    push {r4, lr}

    @ 2. CHIAMA POW
    mov r0, #4       @ Testiamo il numero 4
    bl pow           @ Ritorna 1 se potenza di 2, altrimenti 0

    @ 3. PREPARA PRINTF
    mov r1, r0       @ Sposta il risultato in r1 (per il %d)
    ldr r0, =msg     @ Carica indirizzo stringa
    bl printf        @ Stampa

    @ 4. USCITA PULITA
    mov r0, #0       @ Return 0
    pop {r4, pc}     @ Ripristina r4 e salta all'indirizzo di ritorno (pop in pc = ret)

@ --- FUNZIONE POW ---
pow:
    mov r1, #1       @ Maschera
    mov r2, #0       @ Contatore bit a 1
    mov r3, #0       @ Indice ciclo

loop:
    cmp r3, #32      @ Controlliamo tutti i 32 bit
    beq finepow
    
    tst r0, r1       @ Test bit (AND logico senza salvare risultato)
    addne r2, r2, #1 @ Se il bit è 1 (Not Equal to 0), incrementa count
    
    lsl r1, r1, #1   @ Shifta maschera
    add r3, r3, #1   @ Incrementa indice
    b loop

finepow: 
    cmp r2, #1       @ Abbiamo trovato esattamente UN bit a 1?
    mov r0, #0       @ Default: Falso
    moveq r0, #1     @ Se vero: Vero
    mov pc, lr       @ Ritorna

@ --- SEZIONE DATI (Messa alla fine per sicurezza) ---
.data
msg: .asciz "potenza di 2 :%d\n"