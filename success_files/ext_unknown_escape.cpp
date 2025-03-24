
// expected-error@-5 {{use of non-standard escape character '\%'}}
void foo() {
    const char *unknown = "\Q";
}
