bits 64

extern malloc
extern __errno_location


section .text
    global ft_strdup

ft_strdup:
    xor rcx, rcx

.loop:
    cmp byte [rdi + rcx], 0
    je .alloc
    inc rcx
    jmp .loop

.alloc:
    mov rsi, rdi        ; save original string pointer
    mov rdi, rcx
    inc rdi              ; allocate space for null terminator
    call malloc
    cmp rax, 0
    jz .error             ; if malloc failed, return NULL

    mov rdx, rax         ; rdx = allocated memory
    xor rcx, rcx

.copy:
    mov al, byte [rsi + rcx]
    mov byte [rdx + rcx], al
    cmp al, 0
    je .done
    inc rcx
    jmp .copy

.error:
    mov rdi, 12          ; 12 error code for ENOMEM
    call __errno_location        ; get pointer to errno
    mov [rax], rdi       ; set errno to 12
    xor rax, rax         ; return NULL
    ret

.done:
    mov rax, rdx
    ret