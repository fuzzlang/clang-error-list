
template<typename ...Types = int> // expected-error{{template parameter pack cannot have a default argument}}
void func() {
}

int main() {
    func();
    return 0;
}
