
void print();

template<typename ...Args>
void init_capture_pack_multi(Args ...args) {
  [as(args...)] {} (); // expected-error {{initializer missing for lambda capture 'as'}} expected-error {{multiple}}
}

template void init_capture_pack_multi(); // expected-note {{instantiation}}
template void init_capture_pack_multi(int);
template void init_capture_pack_multi(int, int); // expected-note {{instantiation}}
