section .data
    hello_message db "Hello, Holberton", 0
    format db "%s", 10, 0

section .bss
    rsp_save resq 1

section .text
    global main
    extern printf

main:
    mov [rsp_save], rsp

    mov rdi, format
    mov rsi, hello_message
    call printf

    mov rsp, qword [rsp_save]

    mov rax, 60
    xor rdi, rdi
