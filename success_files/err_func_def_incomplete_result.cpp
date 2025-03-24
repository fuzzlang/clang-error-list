
namespace PR51708 {

class a1;                  // expected-note 4 {{forward declaration of 'PR51708::a1'}}
template <class> class A2; // expected-note 4 {{template is declared here}}
using a2 = A2<int>;

template <class b> b f() { 
    // expected-error@-1 {{incomplete result type 'PR51708::a1' in function definition}}
    b d; 
    // expected-error@-1 {{variable has incomplete type 'PR51708::a1'}}
    return d; 
}

template a1 f<a1>(); // expected-note-re {{in instantiation {{.*}} requested here}}
template a2 f<a2>(); // expected-note-re {{in instantiation {{.*}} requested here}}

} // namespace PR51708
