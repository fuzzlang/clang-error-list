
void f(); // expected-note 11{{candidate function}}
void f(int); // expected-note 11{{candidate function}}

int main() {
    { 
        bool b = static_cast<void (*)(char)>(f); // expected-error{{address of overloaded function}} 
    }
    return 0;
}
