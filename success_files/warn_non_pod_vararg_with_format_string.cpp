
struct A {};
struct B { ~B(); };
class C { char *c_str(); };
struct D { char *c_str(); };
struct E { E(); };
struct F { F(); char *c_str(); };

void v(...);
void w(const char*, ...) __attribute__((format(printf, 1, 2)));

void test(A a, B b, C c, D d, E e, F f) {
    w("%s", b); // expected-error-re {{cannot pass non-{{POD|trivial}} object of type 'B' to variadic function; expected type from format string was 'char *'}}
}
