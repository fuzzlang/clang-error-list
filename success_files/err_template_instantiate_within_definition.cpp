
namespace PR18907 {
template <typename>
class C : public C<int> {}; // expected-error{{within its own definition}}
}
