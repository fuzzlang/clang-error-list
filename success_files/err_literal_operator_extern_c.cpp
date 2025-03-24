
extern "C" void operator "" _a(const char *); // expected-error {{must have C++ linkage}}

void test() {
    // This function intentionally left blank.
}
