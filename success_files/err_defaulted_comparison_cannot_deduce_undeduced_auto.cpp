
template <typename... Ts>
struct A {};

// Example function template that triggers the error
template <typename Ordering, typename... Types>
void f() {
    using T = decltype(A<Types...>() <=> A<Types...>()); // expected-error {{different type}}
    void(A<Types...>() <=> A<Types...>()); // trigger synthesis of body
}

// Explicit instantiations to check the error
template void f<std::strong_ordering>();
template void f<std::strong_ordering, int>();
template void f<std::strong_ordering, int, double>();

template void f<std::weak_ordering, char>();
template void f<std::weak_ordering, char, int>();
template void f<std::weak_ordering, int, char>();

template void f<std::partial_ordering, float>();
template void f<std::partial_ordering, char, float>();
template void f<std::partial_ordering, int, float>();
template void f<std::partial_ordering, float, char>();
template void f<std::partial_ordering, float, int>();
template void f<std::partial_ordering, char, float, int>();

// Make sure we trigger return type deduction for a callee 'operator<=>'
namespace PR44723 {
    // Simple structure with custom comparison operator
    template<int> struct a {
        friend constexpr auto operator<=>(const a &lhs, const a &rhs) {
            return std::strong_ordering::equal;
        }
    };

    struct b {
        friend constexpr auto operator<=>(const b &, const b &) = default;
        a<0> m_value;
    };
    std::strong_ordering cmp_b = b() <=> b();

    struct c {
        auto operator<=>(const c&) const&; // expected-note {{selected 'operator<=>' for base class 'c' declared here}}
    };

    struct d : c { // expected-note {{base class 'c' declared here}}
        friend auto operator<=>(const d&, const d&) = default; // #d
    };
}
