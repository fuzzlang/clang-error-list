
void f() {}

template<typename T>
void g(T) {}

int main() {
    // expected-error@-1 {{address of overloaded function 'g' cannot be cast to type 'void'}}
    //   expected-note@#cwg115-g-int {{candidate function template}}
    //   expected-note@#cwg115-g {{candidate function template}}
    
    &g;  
}
