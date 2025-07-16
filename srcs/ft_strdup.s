bits 64

extern malloc
extern __errno_location
extern ft_strcpy
extern ft_strlen


section .text
    global ft_strdup

ft_strdup:
    ;save the original string on the stack
    push rdi

    call ft_strlen
    inc rax

    ;alloc memory for strlen + 1
    mov rdi, rax 
    call malloc

    cmp rax, 0
    je .error ; check if malloc failed


    ;rax is the address of the allocated memory
    mov rdi, rax

    ; get back the src string from stack
    pop rsi

    ;rdi = destination string
    ;rsi = source string
    call ft_strcpy
    ;rax is the address of the new string
    ret

.error:
    mov rdi, 12          ; 12 error code for ENOMEM
    call __errno_location     ; get pointer to errno
    mov [rax], rdi       ; set errno to 12
    xor rax, rax         ; return NULL
    ret
