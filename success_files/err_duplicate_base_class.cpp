
class G_copy {};
class A {};
class G_copy_2 {};

class H : public G_copy, public A, public G_copy { // expected-error{{base class 'G_copy' (aka 'G') specified more than once as a direct base class}}
};
