
namespace cwg1397 { // cwg1397: 3.2
#if __cplusplus >= 201103L
struct A {
    void *p = A{}; // expected-error@-1 {{default member initializer for 'p' needed within definition of enclosing class 'A' outside of member functions}}
    operator void*() const { return nullptr; }
};
#endif
} // namespace cwg1397
