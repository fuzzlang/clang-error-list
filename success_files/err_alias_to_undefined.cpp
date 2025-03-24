
void *undefined_func(void) { return nullptr; }
void iserr_alias_to_undefined(void) __attribute__((ifunc("undefined_func")));
