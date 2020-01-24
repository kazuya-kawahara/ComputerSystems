    .text
main:
    li $v0, 5
    syscall
    move $t0, $v0 # $t0 = Length

    move $a0, $t0
    # $ra退避
    jal create_array

    move $a0, $v0
    move $a1, $t0
    # $ra退避
    jal calc_sum

    jr $ra
create_array:
    add $a0, $t0, $t0
    add $a0, $a0, $a0 # $a0 = 4Length

    li $v0, 9
    syscall
    move $t1, $v0

while:
    beq $t0, $zero, end
    addi $t0, -1
    
    add $t2, $t0, $t0
    add $t2, $t2, $t2
    add $t2, $t1, $t2
    li $v0, 5
    syscall
    sw $v0, 0($t2)

    j while
end:
    jr $ra
calc_sum: