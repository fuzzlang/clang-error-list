
using FuncPtrTy = void (*)();
FuncPtrTy FuncPtrTyArray[2];

void Func(int i, int j) {
    // Expected error: OpenACC sub-array cannot be of function type 'void ()'
#pragma acc parallel private(FuncPtrTyArray[0][0 : 1])
    {
        while (true);
    }
}

int main() {
    Func(1, 2);
    return 0;
}
