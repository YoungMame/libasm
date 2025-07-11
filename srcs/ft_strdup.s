bits 64

extern malloc

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
    mov rdx, rax         ; rdx = allocated memory
    xor rcx, rcx

.copy:
    mov al, byte [rsi + rcx]
    mov byte [rdx + rcx], al
    cmp al, 0
    je .done
    inc rcx
    jmp .copy

.done:
    mov rax, rdx
    ret