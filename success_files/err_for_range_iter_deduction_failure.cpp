
struct VoidBegin {
    void begin();
    void end();
};

void test() {
    for (auto a : VoidBegin()) // expected-error {{cannot use type 'void' as an iterator}}
        ;
}
