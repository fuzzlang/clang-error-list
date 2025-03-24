
template<typename T> struct Template {};

struct Linkage1 { struct Inner {}; };
typedef struct { struct Inner {}; } Linkage2;

typedef struct {} const NoLinkage1;

extern NoLinkage1 no_linkage1(); // expected-error {{function 'no_linkage1' is used but not defined in this translation unit}}

void use_no_linkage() {
    no_linkage1(); // expected-note {{used here}}
}
