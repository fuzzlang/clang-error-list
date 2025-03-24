
class A {
    template<typename T> static T wrong_inst_undefined; // expected-note {{refers here}}
    template<typename T> static T wrong_inst_defined = T(10); // expected-error {{non-const static data member must be initialized out of line}}
    template<typename T> static T wrong_inst_out_of_line;
};

template const int A::wrong_inst_undefined<const int>; // expected-error {{undefined}}
template int A::wrong_inst_defined<int>; // expected-note {{in instantiation of static data member 'non_const_init::A::wrong_inst_defined<int>' requested here}}
template int A::wrong_inst_out_of_line<int>; // expected-error {{undefined}} 
