
namespace GH83267 {
template<>
auto decltype([](auto a){})::operator()(int a) const { // expected-error{{lambda call operator should not be explicitly specialized or instantiated}}
    return 0; 
}
}
