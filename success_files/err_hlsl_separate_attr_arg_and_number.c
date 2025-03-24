
cbuffer C : register(b 2) {
}

// expected-error@+1 {{wrong argument format for hlsl attribute, use b2 instead}}
cbuffer C : register(b 2) {} 
