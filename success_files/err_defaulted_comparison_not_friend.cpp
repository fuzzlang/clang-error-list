
struct S3 {};                                      // expected-note{{here}}
bool operator==(S3 const &, S3 const &) = default; // expected-error{{not a friend}}
