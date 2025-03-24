
typedef bool bad __attribute__((__vector_size__(16)));  // expected-error {{invalid vector element type 'bool'}}
