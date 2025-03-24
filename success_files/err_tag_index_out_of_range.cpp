
#define INT_TAG 42

static const int test_in
    __attribute__((type_tag_for_datatype(test, int))) = INT_TAG;

// Argument index: 1, Type tag index: 2
void test_bounds_index(...)
    __attribute__((argument_with_type_tag(test, 1, 2)));

class C {
public:
    // Argument index: 2, Type tag index: 3
    void test_bounds_index(...)
        __attribute__((argument_with_type_tag(test, 2, 3)));

    void test_bounds() {
        test_bounds_index(1);       // expected-error {{type tag index 2 is greater than the number of arguments specified}}
    }
};
