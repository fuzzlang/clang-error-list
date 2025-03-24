
cbuffer c : register(b0, s2) { // expected-error@+1 {{invalid space specifier 's2' used; expected 'space' followed by an integer, like space1}}
    float4 color;
};
