
enum SystemEnum
{
    a = 0,
    b = 1,
};

void testValueInRangeOfEnumerationValuesInSystemHeader()
{
    // expected-error {{constexpr variable 'x1' must be initialized by a constant expression}}
    constexpr SystemEnum x1 = static_cast<SystemEnum>(123);
}
