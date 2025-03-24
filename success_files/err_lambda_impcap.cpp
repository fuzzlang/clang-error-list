
namespace test_lambda {
    void test() {
        int i = 10; //expected-note 3{{declared here}}
        auto L = [](auto a) {
            return [=](auto b) {
                i = b;  //expected-error 3{{cannot be implicitly captured}}
                return b;
            };
        };
        auto M = L(3);
        M(4.15);
    }
}
