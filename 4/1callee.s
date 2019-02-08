    .text
main:
    addi $sp, $sp, -4 # 
    sw $ra, 0($sp)

    li $t0, 0
    li $t1, 0
loop:
    jal read1bit
    
    sll $t0, $t0, 1
    add $t0, $t0, $v0

    addi $t1, $t1, 1
    
    blt $t1, 8, loop

    move $a0, $t0
    li $v0, 1
    syscall

    lw $ra, 0($sp)
    addi $sp, $sp, 4 #
    jr $ra

read1bit:
    li $v0, 5
    syscall
    jr $ra