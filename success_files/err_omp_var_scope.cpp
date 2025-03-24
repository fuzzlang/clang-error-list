
class TestClass {
public:
    static int b; // Declaration of static variable
};

#pragma omp threadprivate(TestClass::b) // expected-error {{'#pragma omp threadprivate' must appear in the scope of the 'TestClass::b' variable declaration}}

int TestClass::b = 0; // Definition and initialization of static variable
