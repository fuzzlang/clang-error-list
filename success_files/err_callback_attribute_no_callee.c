
void no_callee(void (*callback)(void)) __attribute__((callback()));

void my_function() {
    no_callee(NULL);
}
