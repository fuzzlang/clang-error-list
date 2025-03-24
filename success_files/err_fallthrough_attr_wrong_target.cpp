
struct S {
    void foo(int x) {
        switch (x) {
            case 1:
                [[clang::fallthrough]]  // expected-error{{'fallthrough' attribute is only allowed on empty statements}} expected-note{{did you forget ';'?}}
                case 2:
                break;
        }
    }
};
