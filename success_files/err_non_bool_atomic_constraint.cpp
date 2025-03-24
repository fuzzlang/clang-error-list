
struct B1 { };

int func() { }

template<typename T> requires (func())
void myFunction() { }
