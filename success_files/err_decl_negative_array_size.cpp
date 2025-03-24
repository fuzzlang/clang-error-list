
namespace Array {
  void g() {
    const int m = -1;
    [] { 
      int arr[m]; // expected-error{{negative size}} 
    } ();
  }
}
