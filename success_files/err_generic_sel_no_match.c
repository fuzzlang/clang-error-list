
void test() {
    (void)_Generic("bla", 
                   int: 0, 
                   float: 0.0); // expected-error {{controlling expression type 'char *' not compatible with any generic association type}}
}
