
struct TestDestructor {
    ~TestDestructor() {
        return ReturnsVoid(); // expected-error {{destructor '~TestDestructor' must not return void expression}}  
        // expected-error {{cannot perform a tail call from a destructor}}
    }

    void ReturnsVoid() {}
};
