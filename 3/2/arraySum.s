    .data
L:
    .word 4         # length of A,B
A:
    .word 1 2 3 4
B:
    .word 5 6 7 8

    .text
main:
    li $t1, 0   # t1 = 0

    lw $t0, L($zero)    # $t0 = L
    add $t0, $t0, $t0   # $t0 = L*2
    add $t0, $t0, $t0   # $t0 = L*4
    move $t2, $t0
    addi $t2, -4    # t2 = 4(L-1) - t1

    li $v0, 1       # syscall = print

    j while

while:
    lw $t3, A($t1)  # t3 = A+t1
    lw $t4, B($t2)  # t4 = B+t2

    add $a0, $t3, $t4   # a0 = A+t1 + B+t2

    syscall     # print(a0)

    addi $t1, 4     # t1 += 4
    addi $t2, -4    # t2 -= 4

    bne $t1, $t0, while     # if (t1 < t0(=4L)) do while 
    

    jr $ra      # finish