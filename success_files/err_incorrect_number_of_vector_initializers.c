
void test_vector_initialization() {
    vector int vi = (vector int)(1, 2); // expected-error {{number of elements must be either one or match the size of the vector}}
}
