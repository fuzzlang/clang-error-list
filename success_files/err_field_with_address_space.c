
class MyClass {
public:
    private int i; // expected-error{{field may not be qualified with an address space}}
};
