
__extension__ typedef __SIZE_TYPE__ size_t;
namespace std { struct bad_alloc {}; }

inline void* operator new(size_t) throw(std::bad_alloc); // expected-error {{'operator new' declared inline}}

int main() {
    return 0;
}
