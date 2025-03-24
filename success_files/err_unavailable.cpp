
struct New3 {
    New3();
    
    void *operator new[](__SIZE_TYPE__) __attribute__((unavailable)); // expected-note{{explicitly marked unavailable here}}
};

template<class C>
void* object_creator() {
    return new C(); // expected-error{{'operator new[]' is unavailable}}
}

template void *object_creator<New3[4]>(); // expected-note{{instantiation}}
