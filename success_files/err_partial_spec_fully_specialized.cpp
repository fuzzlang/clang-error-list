
template <typename, int>
struct Mask;

template <typename, int, bool, typename>
struct StaticArrayImpl;

template <typename Derived_>
struct KMaskBase;

template <typename Derived_>
struct StaticArrayImpl<float, 16, 1, Mask<float, 16>> : KMaskBase<Derived_> {}; // expected-error 0+ {{}}
