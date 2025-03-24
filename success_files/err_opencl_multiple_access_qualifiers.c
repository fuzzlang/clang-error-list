
typedef write_only image1d_t img1d_wo;

kernel void k7(read_only img1d_wo img){} // expected-error {{multiple access qualifiers}}
