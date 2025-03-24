
namespace cwg650 { // cwg650: aligned_too_great
  // expected-error@-1 {{'alignas' out of bounds}}
  alignas(0x200000001) int n; // The alignment specified is greater than the maximum alignment.
}
