#include <stdio.h>
#include <mips.h>

void full_adder(Signal in1, Signal in2, Signal carry_in, Signal *out1, Signal *carry_out)
{
    Signal inner1;
    xor_circuit(in1, in2, &inner1);
    xor_circuit(carry_in, inner1, out1);

    Signal inner21;
    Signal inner22;
    and_circuit(carry_in, inner1, &inner21);
    and_circuit(in1, in2, &inner22);
    or_circuit(inner21, inner22, carry_out);
}

void rca(Word in1, Word in2, Signal carry_in, Word *out1, Signal *carry_out)
{
    int i;
    Signal tmp_in = carry_in;
    Signal tmp_out;
    for (i = 0; i < 32; ++i) {
        full_adder(in1->bit[i], in2->bit[i], tmp_in, out->bit[i], &tmp_out);
        tmp_in = tmp_out
    }
    *carry_out = tmp_out;
}

void test_full_adder()
{
    Signal a, b, carry_in, out, carry_out;
    for (a = 0; a <= 1; ++a) {
        for (b = 0; b <= 1; ++b) {
            for (carry_in = 0; carry_in <= 1; ++b) {
                full_adder(a, b, carry_in, &out, &carry_out)    
                printf("FA(%d, %d, %d) => (%d, %d)\n", a, b, carry_in, out, carry_out);
            }
        }
    }
}

void test_rca(int val1, int val2)
{
    Word w1,w2;
    word_set_value(&w1, val1);
    word_set_value(&w2, val2);
    Word out;
    Signal carry_out;
    rca(w1, w2, 0, &out, &carry_out);
    printf("%d + %d = %d\n", val1, val2, out);
}

