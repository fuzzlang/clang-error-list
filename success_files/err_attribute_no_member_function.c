
struct MyStruct {
    __attribute__((diagnose_as_builtin(__builtin_memset))) void f(); // expected-error{{'diagnose_as_builtin' attribute cannot be applied to non-static member functions}}
};
