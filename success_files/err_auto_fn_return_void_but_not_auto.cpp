
namespace AutoPtr {
    int i;
    auto *f2() {
        return; // expected-error {{cannot deduce return type 'auto *' from omitted return expression}}
    }
}
