
void foo();  // Declaration of foo

#pragma alloc_text(a, foo) // expected-error {{'#pragma alloc_text' is applicable only to functions with C linkage}}
