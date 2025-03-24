
constexpr int i = 42; // Initialize 'i' as it is used in the bit cast

constexpr char c = __builtin_bit_cast(char, i); // expected-error@+1{{__builtin_bit_cast source size does not equal destination size (4 vs 1)}}
