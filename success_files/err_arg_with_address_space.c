
// expected-error@+1 {{parameter may not be qualified with an address space}}
float foo2(groupshared float a) {
    return a;
}
