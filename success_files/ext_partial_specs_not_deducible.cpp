
// expected-error@-1 {{ISO C++ specifies that qualified reference to 'W' is a constructor name rather than a template name in this context, despite preceding 'template' keyword}}
template<typename W>
void wt_test() {
    typename W::W::X w2ax;
    typename W::template W<int>::X w4x;
    TTy<typename W::WBase> tt4;
    TT<W::template WBase> tt5;

    W w;
    (void)w.W::W::n;
    (void)w.W::template W<int>::n;
    (void)w.template W<int>::W::n;
    (void)w.template W<int>::template W<int>::n;
}

template void wt_test<W<int> >(); // #cwg1310-W-int

namespace cwg1315 { // cwg1315: partial
  template <int I, int J> struct A {};
  template <int I> struct A<I + 5, I * 2> {};
}
