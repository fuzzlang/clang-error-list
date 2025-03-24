
#if __cplusplus >= 201103L
#define static_assert(...) __extension__ _Static_assert(__VA_ARGS__)
#endif

static_assert(true, "This should not cause any error");

#define MACRO(...) \
    static_assert(sizeof(__VA_ARGS__) > 0, "variadic macro test")

MACRO();
