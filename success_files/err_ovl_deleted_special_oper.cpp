
namespace cwg1891 { // Reproducing iserr_ovl_deleted_special_oper
#if __cplusplus >= 201103L
  void test() {
    auto a = [] { return 42; };
    a = a; // This should generate the error "cannot be assigned because its copy assignment operator is implicitly deleted"
  }
#endif
}
