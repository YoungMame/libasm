bits 64

extern __errno_location

section .text
    global ft_read
    ft_read:
        mov rax, 0      ; syscall number for read
        syscall
        cmp rax, 0      ; check if rax is negative
        jl .error       ;
        ret
    .error:
        neg rax          ;  rax is returned as negative by syscall on error
        mov		rdi, rax		; we keep rax in rdi because 
        call __errno_location     ; get pointer to errno
        mov [rax], rdi       ; set errno to rdi
        mov rax, -1         ; return NULL
        ret
