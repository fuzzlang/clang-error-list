
void f() {
    typedef void fn_ty();
    fn_ty(); // expected-error {{cannot create object of function type 'fn_ty'}}
}
