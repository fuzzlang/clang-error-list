
void example_function() {
    __int128 *addr;
    int sum = 0;

    sum += __builtin_arm_ldrex(addr); // expected-error {{__int128 is not supported on this target}} expected-error {{address argument to load or store exclusive builtin must be a pointer to 1,2,4 or 8 byte type}}
}
