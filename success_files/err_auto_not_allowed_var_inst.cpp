
template <typename T>
auto var1 = T(); // Template declaration with auto

template auto var1<int>; // expected-error {{'auto' variable template instantiation is not allowed}}
