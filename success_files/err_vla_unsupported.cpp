
struct NonPOD { NonPOD(int); };
typedef NonPOD NonPODAr[10];
typedef NonPOD NonPODArNB[];

void is_bounded_array(int n) {
    int t32[n];
    (void)__is_bounded_array(decltype(t32)); // expected-error{{variable length arrays are not supported in '__is_bounded_array'}}
}
