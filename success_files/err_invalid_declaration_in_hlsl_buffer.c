
// expected-error@+2 {{invalid declaration inside cbuffer}}
cbuffer MyBuffer {
    template<typename T>
    T foo(T t) { return t; }
}
