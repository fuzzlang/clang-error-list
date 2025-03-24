
class MyClass {
    static void meth();
};

void MyClass::meth() { } // expected-note {{previous}}

extern "C" {
    void _ZN7MyClass4methEv() { } // expected-error {{definition with same mangled name '_ZN7MyClass4methEv' as another definition}}
}
