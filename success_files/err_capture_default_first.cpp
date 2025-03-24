
namespace misplaced_capture_default {
void Test() {
  int i = 0;
  
  [i, &] {};   // expected-error {{capture default must be first}}
  
}
} // namespace misplaced_capture_default
