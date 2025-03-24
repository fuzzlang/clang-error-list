
void test(void) {
    const int a = 3;
    switch (a) {
        case 3: // expected-note {{previous case}} 
        case a: // expected-error {{duplicate case value: '3' and 'a' both equal '3'}}
            break;
    }
}
