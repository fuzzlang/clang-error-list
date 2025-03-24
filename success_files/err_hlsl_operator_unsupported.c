
struct MyStruct {
    int X;
};

int main() {
    MyStruct F;
    // expected-error@+1 {{pointers are unsupported in HLSL}}
    int MyStruct::*Member = &F.X;

    return 0;
}
