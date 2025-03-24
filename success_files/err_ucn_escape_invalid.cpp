
namespace cwg559 { // expected-error@-1 {{'operator new' cannot be declared inside a namespace}}
    void operator new(size_t size);
}

namespace cwg560 { // cwg560: 2.9
    wchar_t x = L'\uD7FF';
    wchar_t y = L'\xD7FF';
    wchar_t z = L'\uD800'; // expected-error@-1 {{invalid universal character name escape}}
}
