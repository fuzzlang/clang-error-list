
void fn(int i, int = ({ 1; })); // expected-error {{default argument may not use a GNU statement expression}}
