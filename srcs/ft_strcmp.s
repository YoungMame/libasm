bits 64

section .text
    global ft_strcmp

ft_strcmp:
    xor rax, rax        ; used for comparison
    xor rbx, rbx        ; used for indexing
    jmp .loop
.loop:
    cmp byte [rdi + rbx], 0 ; check if end of first string
    jz .return ; if '\0' then ZF = 1 true, jump to return
    cmp byte [rsi + rbx], 0 ; check if end of second string
    jz .return ; if '\0' then ZF = 1 true, jump to return

    mov al, byte [rsi + rbx] ; load byte from first string
    cmp [rdi + rbx], al

    jnz .return                ; if cmp is not different then ZF = 0, jump to return

    inc rbx
    jmp .loop

.return:
    movzx rax, byte [rdi + rbx]
    movzx rbx, byte [rsi + rbx]
    sub rax, rbx
    ret