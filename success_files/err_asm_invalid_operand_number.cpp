
int main() {
    int cond;
    
    asm goto ("testl %0, %0; jne %l3;" :: "r"(cond)::label_true, loop); // expected-error@+1 {{invalid operand number in inline asm string}}
    
    return 0;
}
