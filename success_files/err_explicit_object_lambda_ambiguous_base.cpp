
namespace cwg2881 { // cwg2881: 19 tentatively ready 2024-05-31

template <typename T>
struct A : T {};

template <typename T>
struct B : T {};

template <typename T>
struct C : virtual T { C(T t) : T(t) {} };

template <typename T>
struct D : virtual T { D(T t) : T(t) {} };

template <typename Ts>
struct O1 : A<Ts>, B<Ts> {
    using A<Ts>::operator();
    using B<Ts>::operator();
};

void f() {
    int x;
    auto L1 = [=](this auto&& self) { (void) &x; };
    O1<decltype(L1)>{L1, L1}(); // expected-error {{inaccessible due to ambiguity}}
}

} // namespace cwg2881
