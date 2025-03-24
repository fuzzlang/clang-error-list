
void some_short() {}
int some_int() { return 0; }
long some_long() { return 0; }
enum SomeE { VALUE1, VALUE2 };

void test() {
    #pragma acc parallel num_gangs(some_short(), some_int(), some_long(), SomeE::VALUE1)
    {
        // Code block
    }
}
