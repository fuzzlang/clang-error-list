
template<typename T> extern T v1; // expected-note {{previous template declaration is here}}
template<int I> int v1;           // expected-error {{template parameter has a different kind in template redeclaration}}
