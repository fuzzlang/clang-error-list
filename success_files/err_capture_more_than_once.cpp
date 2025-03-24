
class Test {
public:
    void func() {
        (void)[*this, this]{}; // expected-error{{'this' can appear only once}}
    }
};
