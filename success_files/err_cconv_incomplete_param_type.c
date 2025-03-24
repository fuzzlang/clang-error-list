
// expected-error@+2 {{parameter 'p' must have a complete type to use function 'fwd_fast' with the fastcall calling convention}}
struct Foo; // Incomplete type declaration

extern "C" void __fastcall fwd_fast(struct Foo p); // Function declaration with incomplete type

void (__fastcall *fp_fwd_fast)(struct Foo) = &fwd_fast;
