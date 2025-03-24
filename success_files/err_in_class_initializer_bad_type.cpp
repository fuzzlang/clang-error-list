
#define CONST const

class C2b {
  template<typename U> static int Data; 
  template<typename U> static U *const Data<U*> = (U*)(0); // expected-error {{static data member of type 'int *const'}}
};

template<typename U> U *const C2b::Data<U*>;
template int *const C2b::Data<int*>; // expected-note {{in instantiation of static data member 'non_const_init::pointers::C2b::Data<int *>' requested here}}
