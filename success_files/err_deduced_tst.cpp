
template<typename T>
struct identity { using type = T; };

template<typename T>
using identity_t = typename identity<T>::type;

template<typename A>
struct iserr_deduced_tst {
    static_assert(!requires { typename identity_t<A, A>; }); // expected-error{{too many template arguments for alias template 'identity_t'}}
    static_assert(requires { typename identity<A>; });
    static_assert(!requires { typename identity; });
};

int main() {
    iserr_deduced_tst<int> test; // instantiate the template
    return 0;
}
