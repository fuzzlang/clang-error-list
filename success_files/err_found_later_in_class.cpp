
namespace test1 {
    template <typename> class ArraySlice {};
    class Foo;

    class NonTemplateClass {
        void MemberFunction(ArraySlice<Foo> resource_data, int);
        template <class T> void MemberFuncTemplate(ArraySlice<T> resource_data, int);
    };

    void NonTemplateClass::MemberFunction(ArraySlice<Foo> resource_data, int now) {
        // expected-note@+1 {{in instantiation of function template specialization 'test1::NonTemplateClass::MemberFuncTemplate<test1::Foo>'}}
        MemberFuncTemplate(resource_data, now);
    }

    template <class T>
    void NonTemplateClass::MemberFuncTemplate(ArraySlice<T> resource_data, int) {
        // expected-error@+1 {{member 'UndeclaredMethod' used before its declaration}}
        UndeclaredMethod(resource_data);
    }
    
    // expected-error@+2 {{out-of-line definition of 'UndeclaredMethod' does not match any declaration}}
    // expected-note@+1 {{member is declared here}}
    void NonTemplateClass::UndeclaredMethod() {}
}
