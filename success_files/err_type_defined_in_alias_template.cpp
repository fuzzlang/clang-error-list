
template<typename Z> 
using S = struct { int n; }; // expected-error {{cannot be defined}}

S<int> myStruct; // This line may cause errors due to the previous definition.
