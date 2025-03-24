
namespace std {
    struct type_info;
}

class X { virtual ~X(); };
constexpr bool b = requires (X &x) { static_cast<int(*)[(typeid(x), 0)]>(nullptr); }; // expected-error{{constraint variable 'x' cannot be used in an evaluated context}}
