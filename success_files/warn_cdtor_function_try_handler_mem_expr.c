
@interface MyClass
- (void)someMethod;
@end

struct BadReturn {
    BadReturn(MyClass * myObject) try : CObj(myObject) {
    } catch(...) {
        try {
            getMe = bar(myObject); // expected-error {{cannot refer to a non-static member from the handler of a constructor function try block}}
        } catch(...) {}
    }

    int bar(MyClass * myObject) {
        return 0;
    }

    MyClass *CObj;
    static int getMe;
};

- (void)privateMethod { }
