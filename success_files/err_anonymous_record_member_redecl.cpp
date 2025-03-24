
struct {
    int x;
    struct {
        int x; // expected-error{{member of anonymous union redeclares 'x'}}
    };
};
