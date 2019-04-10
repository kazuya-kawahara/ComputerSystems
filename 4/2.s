    .text
main:
    li $v0, 5
    syscall
    move $t0, $v0

    move $a0, $t0
    move $t5, $ra //
    jal create_array

    move $a0, $v0
    move $a1, $t0
    jal calc_sum

create_array:


calc_sum: