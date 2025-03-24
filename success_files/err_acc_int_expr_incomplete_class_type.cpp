
struct Incomplete; // forward declaration
struct NotConvertible {} NC;
struct Incomplete *SomeIncomplete; // #INCOMPLETE
enum E {} SomeE;
enum class E2 {} SomeE2;

void Test() {
    #pragma acc kernels num_workers(*SomeIncomplete) // expected-error@+2{{OpenACC integer expression has incomplete class type 'struct Incomplete'}}
    {
        while(1);
    }
}
