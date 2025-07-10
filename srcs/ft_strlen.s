

// rax is the register for return value 

section .text
    global ft_strlen // entrypoint for linker

ft_strlen:
    xor rax, rax // set all bytes to 0
    jmp .loop 

.loop:
    cmp byte [rdi + rax], 0 // cmnp = compare
    je .end     // je = jump if equal

    inc rax // increment rax
    jmp .loop

.end:
    ret // return (rax);


// rax : registre d’accumulateur (calculs, retour de fonctions)
// rbx : registre de base
// rcx : registre de compteur (boucles)
// rdx : registre de données
// rsi : source d’opérations (ex : copie de mémoire)
// rdi : destination d’opérations
// rsp : pointeur de pile (stack pointer)
// rbp : base de pile (base pointer)
// r8 à r15 : registres supplémentaires (généraux)
