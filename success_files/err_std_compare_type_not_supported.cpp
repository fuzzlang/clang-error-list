
namespace std {
inline namespace __1 {
struct partial_ordering {
  unsigned value;
};
} // namespace __1
} // namespace std

auto missing_member_test() {
// expected-error@+1 {{standard library implementation of 'std::partial_ordering' is not supported; member 'equivalent' is missing}}
  return (1.0 <=> 1.0);
}
