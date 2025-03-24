
alignas(4) int n1; // expected-error {{redeclaration has different alignment requirement (8 vs 4)}}
alignas(8) int n1; // expected-error {{redeclaration has different alignment requirement (8 vs 4)}}
