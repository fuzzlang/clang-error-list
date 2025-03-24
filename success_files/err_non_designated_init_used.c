
typedef void (*func_ptr)();

void foo(void);
void bar(void);
void baz(void);

struct test {
    func_ptr a;
    func_ptr b;
    func_ptr c;
} __attribute__((randomize_layout));

struct test t4 = { .a = foo, bar, baz }; // expected-error {{a randomized struct can only be initialized with a designated initializer}}
