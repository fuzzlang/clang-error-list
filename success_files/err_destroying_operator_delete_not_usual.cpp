
namespace std {
    using size_t = decltype(sizeof(0));
    enum class align_val_t : size_t;
    
    struct destroying_delete_t {
        struct __construct { explicit __construct() = default; };
        explicit destroying_delete_t(__construct) {}
    };

    inline constexpr destroying_delete_t destroying_delete(destroying_delete_t::__construct());
}

struct A {
    void operator delete(A*, std::destroying_delete_t, int); // expected-error {{destroying operator delete can have only an optional size and optional alignment parameter}}
};
