
struct S {
    union {
        int NonStaticMember;
    };
};

template<int*>
struct X0 {};

void test() {
    X0<&S::NonStaticMember> x0_non_static; // precxx17-error {{non-static data member}} cxx17-error {{value of type 'int addr_of_obj_or_func::S::*' is not implicitly convertible to 'int *'}}
}
