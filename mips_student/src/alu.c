#include <stdio.h>
#include <mips.h>

void mux(Signal in1, Signal in2, Signal ctl, Signal *out1)
{
    Signal inner1[2], inner2[2], inner3[2];

    not_gate(ctl, inner1 + 0);
    inner1[1] = in1;
    and_gate(inner1[0], inner1[1], inner3 + 0);

    not_gate(ctl, inner2 + 0);
    inner2[1] = in2;
    and_gate(inner2[0], inner2[1], inner3 + 1);

    or_gate(inner3[0], inner3[1], out1);
}

void mux4(Signal in1, Signal in2, Signal in3, Signal in4, Signal ctl1, Signal ctl2, Signal *out1)
{
    Signal inner1[3], inner2[3], inner3[3], inner4[3], inner5[4];

    /* ctl1 != true && ctl2 != true) */
    not_gate(ctl1, inner1 + 0);
    not_gate(ctl2, inner1 + 1);
    inner1[2] = in1;
    andn_gate(inner1, 3, inner5 + 0);
    /* ctl1 == true && ctl2 != true) */
    inner2[0] = ctl1;
    not_gate(ctl2, inner2 + 1);
    inner2[2] = in2;
    andn_gate(inner2, 3, inner5 + 1);
    /* (ctl1 != true && ctl2 == true) */
    not_gate(ctl1, inner3 + 0);
    inner3[1] = ctl2;
    inner3[2] = in3;
    andn_gate(inner3, 3, inner5 + 2);
    /* (ctl1 == true && ctl2 == true) */
    inner4[0] = ctl1;
    inner4[1] = ctl2;
    inner4[2] = in4;
    andn_gate(inner4, 3, inner5 + 3);
    
    orn_gate(inner5, 4, out1);
}

void alu(Signal *ops, Signal a, Signal b, Signal less, Signal carry_in, Signal *s, Signal *carry_out)
{
    Signal inner[4], subinner[2];

    and_gate(a, b, inner + 0);

    or_gate(a, b, inner + 1);

    not_gate(b, subinner + 0);
    mux(b, subinner[0], ops[2], subinner + 1);
    full_adder(a, subinner[1], carry_in, inner + 2, carry_out);

    mux4(inner[0], inner[1], inner[2], less, ops[0], ops[1], s);
}

void alu_msb(Signal *ops, Signal a, Signal b, Signal less, Signal carry_in, Signal *s, Signal *carry_out, Signal *set)
{
    Signal inner[4], subinner[2];

    and_gate(a, b, inner + 0);

    or_gate(a, b, inner + 1);

    not_gate(b, subinner + 0);
    mux(b, subinner[0], ops[2], subinner + 1);
    full_adder(a, subinner[1], carry_in, inner + 2, carry_out);

    *set = inner[2]

    mux4(inner[0], inner[1], inner[2], less, ops[0], ops[1], s);
}

void alu32(Signal *ops, Word a, Word b, Word *s, Signal *zero)
{
    int i;

    Signal carry_in = ops[2];
    Signal carry_out;
    for (i = 0; i < 31; ++i) {
        alu(ops, (&a)->bit[i], (&b)->bit[i], 0, carry_in, &(s->bit[i]), &carry_out);
        carry_in = carry_out;
    }
    alu_msb(ops, (&a)->bit[31], (&b)->bit[31], 0, ops[2], &(s->bit[31]), &carry_out);

    alu(ops, (&a)->bit[0], (&b)->bit[0], s->bit[31], ops[2], &(s->bit[0]), &carry_out);

    Signal inner;
    orn_gate(s, 32, &inner);
    not_gate(inner, zero);
}

void test_alu()
{
    /* Exercise 6-1 */
    Signal a, b, carry_in, s, carry_out;
    Signal ops[3];
    
    /* AND */
    ops[0] = false;
    ops[1] = false;
    ops[2] = false;
    for (carry_in = 0; carry_in <= 1; ++carry_in) {
        for (a = 0; a <= 1; ++a) {
            for (b = 0; b <= 1; ++b) {
                alu(ops, a, b, false, carry_in, &s, &carry_out);
                printf("ALU(AND, %d, %d, %d) => (%d, %d)\n", a, b, carry_in, s, carry_out);
            }
        }
    }
    /* OR */
    /* ADD */
}

void test_alu32(int val1, int val2)
{
    /* Exercise 6-1 */
    Signal ops[3];
    Word in1, in2, out1;
    Signal carry_in, carry_out;
    word_set_value(&in1, val1);
    word_set_value(&in2, val2);
    carry_in = false;
    
    /* AND */
    ops[0] = false;
    ops[1] = false;
    ops[2] = false;
    alu32(ops, in1, in2, &out1, &carry_out);
    printf("ALU32(AND, %x, %x, %d) => (%x, %d)\n", val1, val2, carry_in, word_get_value(out1), carry_out);

    /* OR */
    /* ADD */
    /* SUB (also check zero?) */
    /* SLT */

}
