
namespace cwg1518 { // cwg1518: 4
#if __cplusplus >= 201103L
struct Z0 { // #cwg1518-Z0
  explicit Z0() = default; // #cwg1518-Z0-ctor
};
struct Z {
  explicit Z(); // #cwg1518-Z-ctor
  explicit Z(int); // #cwg1518-Z-int
  explicit Z(int, int); // #cwg1518-Z-int-int
};

Z0 a;
Z0 b{};
Z0 c = {}; // since-cxx11-error@-1 {{chosen constructor is explicit in copy-initialization}}
//   since-cxx11-note@#cwg1518-Z0-ctor {{explicit constructor declared here}}

int main() {
    return 0;
}
#endif
}
