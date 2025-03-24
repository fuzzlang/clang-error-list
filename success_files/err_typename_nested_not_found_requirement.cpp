
namespace boost {
    template<bool, typename = void> struct enable_if {};
    template<typename T> struct enable_if<true, T> { typedef T type; };
}

template<typename T>
struct NonTemplateFunction {
    typename boost::enable_if<sizeof(T) == 4, int>::type f(); // expected-error{{failed requirement 'sizeof(char) == 4'; 'enable_if' cannot be used to disable this declaration}}
};

NonTemplateFunction<char> NTFC; // expected-note{{here}}
