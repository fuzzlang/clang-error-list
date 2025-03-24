
namespace test6 {
  void foo(int arr[]) {  // expected-note {{declared here}}
    for (auto i : arr) { } // expected-error {{cannot build range expression with array function parameter 'arr' since parameter with array type 'int[]' is treated as pointer type 'int *'}}
  }
}
