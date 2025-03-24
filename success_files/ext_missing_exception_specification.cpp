
// Test for missing exception specification in operator overload

#if __cplusplus == 199711L
#define static_assert(...) __extension__ _Static_assert(__VA_ARGS__)
#endif

__extension__ typedef __SIZE_TYPE__ size_t;
void *operator new(size_t); // #cwg5xx-global-operator-new

class MyClass {
public:
    void myFunction() noexcept; // expected-error {{missing exception specification on 'operator new'}}
};
