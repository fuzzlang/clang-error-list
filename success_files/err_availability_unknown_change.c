
int i [[clang::availability(this, should = 1.0)]]; // expected-error {{'should' is not an availability stage; use 'introduced', 'deprecated', or 'obsoleted'}}
