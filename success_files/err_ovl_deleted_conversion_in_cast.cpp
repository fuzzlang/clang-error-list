
struct Noncopyable {
    Noncopyable() = default;
    Noncopyable(const Noncopyable&) = delete; // Deleted copy constructor
    Noncopyable& operator=(const Noncopyable&) = delete; // Deleted copy assignment
};

int main() {
    Noncopyable nc1;
    Noncopyable sc2 = static_cast<Noncopyable>(nc1); // expected-error {{deleted}}
    return 0;
}
