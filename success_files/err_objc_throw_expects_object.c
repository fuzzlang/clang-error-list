
void func() {
    @throw 1, 2; // expected-error {{@throw requires an Objective-C object type ('int' invalid)}}
}
