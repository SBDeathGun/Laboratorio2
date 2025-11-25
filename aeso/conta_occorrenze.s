@Contare il numero di occorrenze di ciascun carattere in una stringa

.data
.text
.global conta
.type conta,%function
.type lowercase,%function

conta: 
    push {r4,lr}
    bl lowercase  @ho la stringa lowcaseata in r0
    mov r5,r0 @ muovo il poiter in r5
    mov r0,#26
    mov r1,#4
    bl calloc
    
    mov r2,r0 @pointer array lettere
    mov r0,#0
    
    loop:   
        ldrb r3,[r5,r0] @carico un byte di r1 (lettera)
        cmp r3,#0 
        beq fine
        cmp r3,#97 @controllo se e minore di 97 
        blt skip_inc
        cmp r3,#122 @controllo se e maggiore di 122
        bgt skip_inc
        sub r3,r3,#97 @ levo 97 per farlo diventare da 0 a 26
        ldr r4,[r2,r3,lsl #2] @carico il valore della lettera
        add r4 ,r4,#1 @sommo la lettera trovata
        str r4, [r2,r3,lsl #2]
        skip_inc: 
            add r0,r0,#1
            b loop

    fine:
    pop {r4,lr}
    mov r0,r2
    mov pc,lr   @controllo
    
    



lowercase:
    mov r2,#0
    loopcase:
        ldrb r1,[r0,r2]
        cmp r1,#0
        beq finelowercase
        cmp r1,#65
        blt skip
        cmp r1 ,#90
        bgt skip
        add r1,r1,#32
        strb r1,[r0,r2]
        skip:
            add r2,r2,#1
            b loopcase



    finelowercase:
        mov pc,lr

    