
void test(int n) {
    switch (n) {
        try { // #cwg98-try
            case 0:
                // expected-error@-1 {{cannot jump from switch statement to this case label}}
                // expected-note@#cwg98-try {{jump bypasses initialization of try block}}
                x:
                    throw n;
        } catch (...) { // #cwg98-catch
            case 1:
                // expected-error@-1 {{cannot jump from switch statement to this case label}}
                // expected-note@#cwg98-catch {{jump bypasses initialization of catch block}}
                y:
                    throw n;
        }
        case 2:
            goto x;
            // expected-error@-1 {{cannot jump from this goto statement to its label}}
            // expected-note@#cwg98-try {{jump bypasses initialization of try block}}
        case 3:
            goto y;
            // expected-error@-1 {{cannot jump from this goto statement to its label}}
            // expected-note@#cwg98-catch {{jump bypasses initialization of catch block}}
    }
}
