
class CLASS {
public:
    void swap(CLASS &other) noexcept(noexcept(swap(*this, other))); // expected-error {{too many arguments}} expected-note {{declared here}}
};
