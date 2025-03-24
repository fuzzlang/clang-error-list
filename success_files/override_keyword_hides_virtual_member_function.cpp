
namespace virt {
    struct Foo {
        virtual void DoIt(void *const p __attribute__((pass_object_size(0))));
    };

    struct Baz : public Foo {
        void DoIt(void *const p) override; // expected-error{{non-virtual member function marked 'override' hides virtual member function}} expected-note@81{{hidden overloaded virtual function 'virt::Foo::DoIt' declared here}}
    };
}
