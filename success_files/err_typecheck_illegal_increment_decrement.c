
void dr098(void) {
    typedef void func_type(void);
    func_type fp;

    ++fp; /* expected-error {{cannot increment value of type 'func_type' (aka 'void (void)')}} */
}
