bits 64

extern malloc
extern __errno_location
extern ft_strcpy
extern ft_strlen


section .text
    global ft_strdup

ft_strdup:
    mov rax, 0
    jmp .alloc

.alloc:

    mov rsi, rdi ; save original string pointer

    ; rdi = pointer to the string to duplicate
    call ft_strlen      ; rax = length of the string

    inc rax         ; increment length for null terminator

    mov rdi, rax         ; rdi = length of the string

    call malloc
    cmp rax, 0
    jz .error             ; if malloc failed, return NULL

    mov rdi, rax         ; rdi = allocated memory
    ; rsi = original string pointer
    call ft_strcpy      ; copy the string to the allocated memory
    ret

.error:
    mov rdi, 12          ; 12 error code for ENOMEM
    call __errno_location        ; get pointer to errno
    mov [rax], rdi       ; set errno to 12
    xor rax, rax         ; return NULL
    ret
