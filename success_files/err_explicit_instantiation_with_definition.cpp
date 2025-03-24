
template void f1<int>(int); // expected-error {{explicit template instantiation cannot have a definition; if this definition is meant to be an explicit specialization, add '<>' after the 'template' keyword}}
template void f1<int>(int) { }
