
class S {
public:
    template<typename T> static int A; // expected-note {{here}}
};

template<typename T>
void f() {
    typename T::template A<int> a; // expected-error {{template name refers to non-type template 'S::template A'}}
}

int main() {
    f<S>(); 
}
