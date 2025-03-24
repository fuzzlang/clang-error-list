
class T {
public:
    template <typename U>
    ~T() {}
};

T t1 = t1.T::~T<int>; // expected-error {{destructor name 'T' does not refer to a template}}
