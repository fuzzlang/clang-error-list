
// expected-error@-1 {{rvalue of type 'const int *const *'}}

// FIXME: We order these as a speculative defect resolution.
void f(const int * const * const &r);
#if __cplusplus >= 201103L
constexpr
#endif
int *const *const &f(int * const * const &r) { return r; }

// No temporary is created here.
int *const *const &check_f = f(p);
#if __cplusplus >= 201103L
static_assert(&p == &check_f, "");
#endif
}

namespace cwg2353 { // cwg2353: 9
struct X {
    static const int n = 0;
};

// CHECK: FunctionDecl {{.*}} use
int use(X x) {
    // CHECK: MemberExpr {{.*}} .n
    // CHECK-NOT: non_odr_use
    // CHECK: DeclRefExpr {{.*}} 'x'
    // CHECK-NOT: non_odr_use
    return *&x.n;
}
#pragma clang __debug dump use

// CHECK: FunctionDecl {{.*}} not_use
int not_use(X x) {
    // CHECK: MemberExpr {{.*}} .n {{.*}} non_odr_use_constant
    // CHECK: DeclRefExpr {{.*}} 'x'
    return x.n;
}
#pragma clang __debug dump not_use

// CHECK: FunctionDecl {{.*}} not_use_2
int not_use_2(X *x) {
    // CHECK: MemberExpr {{.*}} ->n {{.*}} non_odr_use_constant
    // CHECK: DeclRefExpr {{.*}} 'x'
    return x->n;
}
#pragma clang __debug dump not_use_2
}

namespace cwg2354 { // cwg2354: 15
#if __cplusplus >= 201103L
enum alignas(64) A {};
#else
// expected-error@-1 {{expected declaration}}
#endif
