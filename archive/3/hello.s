    .data
str:
    .asciiz"helloWorld\n"

    .text
main:
    li $v0, 4
    la $a0, str
    syscall
    jr $ra