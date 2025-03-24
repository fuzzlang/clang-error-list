
namespace DirectRecursiveCheck {
template<class T>
concept NotInf = true;

template<class T>
concept Inf = requires(T& v) { 
  { begin(v) }; // #INF_REQ
};

void begin(NotInf auto& v) { } // #NOTINF_BEGIN

// This lookup should fail, since it results in a recursive check.
// However, this is a 'hard failure'(not a SFINAE failure or constraints
// violation), so it needs to cause the entire lookup to fail.
void begin(Inf auto& v) { } // #INF_BEGIN

struct my_range{ } rng;

void baz() {
    auto it = begin(rng); // #BEGIN_CALL
    // expected-error@#INF_BEGIN {{satisfaction of constraint 'Inf<Inf auto>' depends on itself}}
    // expected-note@#INF_BEGIN {{while substituting template arguments into constraint expression here}}
    // expected-note@#INF_BEGIN_EXPR {{while checking constraint satisfaction for template 'begin<DirectRecursiveCheck::my_range>' required here}}
    // expected-note@#INF_BEGIN_EXPR {{while substituting deduced template arguments into function template 'begin'}}
    // expected-note@#INF_BEGIN_EXPR {{in instantiation of requirement here}}
    // expected-note@#INF_REQ {{while substituting template arguments into constraint expression here}}
    // expected-note@#INF_BEGIN {{while checking the satisfaction of concept 'Inf<DirectRecursiveCheck::my_range>' requested here}}
    // expected-note@#INF_BEGIN {{while substituting template arguments into constraint expression here}}
    // expected-note@#BEGIN_CALL {{while checking constraint satisfaction for template 'begin<DirectRecursiveCheck::my_range>' required here}}
    // expected-note@#BEGIN_CALL {{in instantiation of function template specialization}}
    // expected-error@#BEGIN_CALL {{no matching function for call to 'begin'}}
    // expected-note@#NOTINF_BEGIN {{candidate function}}
    // expected-note@#INF_BEGIN{{candidate template ignored: constraints not satisfied}}
}
} // namespace DirectRecursiveCheck
