
struct NotConvertible{} NC;

constexpr int returns_3() { return 3; }

int main() {
    int array[5];

    // expected-error@+1{{OpenACC sub-array lower bound evaluated to negative value -1}}
    #pragma acc parallel private(array[returns_3() - 4 : ])
    {
        while (true);
    }

    return 0;
}
