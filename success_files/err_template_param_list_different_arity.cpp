
template<typename T> T v; // expected-error {{too few template parameters in template redeclaration}}
template<typename T, typename U> T v; // Correct redeclaration with different arity
