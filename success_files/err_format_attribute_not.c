
extern void NSLog2(int format, ...) __attribute__((format(__NSString__, 1, 2))); // expected-error {{format argument not a string type}}

void testFunction() {
    NSLog2(1, "This will cause an error");
}
