
extern int incomplete[];

int main() {
    for (auto a : incomplete) // expected-error {{cannot use incomplete type 'int[]' as a range}}
        ;
    return 0;
}
