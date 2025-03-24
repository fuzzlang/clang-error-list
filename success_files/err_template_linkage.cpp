
extern "C" template<char...> void operator "" _b(); // expected-error {{must have C++ linkage}}

template<char... Chars>
void operator "" _b() {
}
