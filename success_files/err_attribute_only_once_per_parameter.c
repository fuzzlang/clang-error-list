
void j(char *p __attribute__((pass_object_size(0), pass_object_size(1)))); // expected-error{{'pass_object_size' attribute can only be applied once per parameter}}
