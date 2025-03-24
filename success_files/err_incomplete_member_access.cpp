
namespace vtable_uses_incomplete {
    class DeclaredOnly; // forward declaration

    class RefPtr {
    public:
        DeclaredOnly* m_ptr; // pointer to incomplete type

        ~RefPtr() {
            m_ptr->deref(); // expected-error {{member access into incomplete type 'vtable_uses_incomplete::DeclaredOnly'}}
        }
    };
}
