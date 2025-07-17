bits 64

extern __errno_location

section .text
    global ft_write
    ft_write:
        mov rax, 1  ; syscall number for write
        syscall
        cmp rax, 0  ; check if rax is negative
        jl .error    ; if negative, jump to error handling
        ret
    .error:
        neg rax          ;  rax is returned as negative by syscall on error
        mov		rdi, rax		; we keep rax in rdi because 
        call __errno_location wrt ..plt    ; get pointer to errno
        mov [rax], rdi       ; set errno to rdi
        mov rax, -1         ; return NULL
        ret