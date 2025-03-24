
template void g0(int); // expected-error {{function cannot be defined in an explicit instantiation; if this declaration is meant to be a function definition, remove the 'template' keyword}}
template void g0(int) { } 
