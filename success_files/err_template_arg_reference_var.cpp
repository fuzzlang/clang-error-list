
namespace PR6749 {
    template <int& i> struct foo {}; // expected-note 0-1{{template parameter is declared here}}
    int x, &y = x; 

    void test() {
        T &ref2 = ref; // expected-error{{drops 'const' qualifier}}
        foo<y> f; 
    }
    
    int counter;
    void inc() {}
    void bind() {}
}
