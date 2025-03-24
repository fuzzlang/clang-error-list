
typedef struct S1 __attribute__ ((NSObject)) S1Type; // expected-error {{'NSObject' attribute is for pointer types only}}

int main() {
    S1Type s; // Just to have a function, but this won't compile
    return 0;
}
