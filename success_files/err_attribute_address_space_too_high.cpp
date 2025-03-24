
__attribute__((address_space(8388587))) int *bounds; // expected-error {{address space is larger than the maximum supported (8388586)}}
