
struct A {
    enum EnumType { Value1, Value2 };
};

using enum A::+; // expected-error {{using enum requires an enum or typedef name}}
