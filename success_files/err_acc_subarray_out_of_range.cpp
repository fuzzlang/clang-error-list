
struct NotConvertible{} NC;

constexpr int returns_3() { return 3; }

void Func(int i) {
    int array[5];

    // expected-error@+1{{OpenACC sub-array length evaluated to a value (6) that would be out of the range of the subscripted array size of 5}}
#pragma acc parallel private(array[i:returns_3() + 3]) {
        while (true);
    }
}

int main() {
    Func(5);
    return 0;
}
