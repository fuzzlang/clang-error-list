
struct AmbiguousConvert {
    operator int() { return 0; }
    operator short() { return 0; }
};

void test() {
#pragma acc parallel num_gangs(AmbiguousConvert())
}
