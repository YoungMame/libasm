bits 64

section .text
    global ft_write
    ft_write:
        mov rax, 1  ; syscall number for write
        inc rdx
        syscall
        ret