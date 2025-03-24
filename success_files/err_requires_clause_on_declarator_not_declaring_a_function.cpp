
void (*pf)() 
  requires true; // expected-error{{trailing requires clause can only be used when declaring a function}}
