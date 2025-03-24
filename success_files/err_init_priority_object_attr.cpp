
int main() {
    int i __attribute__((init_priority(1001))); // expected-error {{can only use 'init_priority' attribute on file-scope definitions of objects of class type}}
    return 0;
}
