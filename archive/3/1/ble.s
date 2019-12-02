    beq $s1,$s2,label   # if (x==y) goto label

    slt $t0,$s1,$s2   # if (x<y) a=1 else a=0
    bne $t0,$zero,label   # if (a!=0) goto label