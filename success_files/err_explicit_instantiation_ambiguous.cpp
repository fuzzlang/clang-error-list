
namespace cwg275 {
namespace N {

template<class T> void g(T) {}

} // namespace N

using namespace N;

template<class T> void g(T) {}

template void g(int); // expected-error {{partial ordering for explicit instantiation of 'g' is ambiguous}}
// expected-note@#cwg275-g {{explicit instantiation candidate function 'cwg275::g<int>' template here [with T = int]}}
// expected-note@#cwg275-N-g {{explicit instantiation candidate function 'cwg275::N::g<int>' template here [with T = int]}}

} // namespace cwg275
