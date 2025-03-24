
void* operator new(__SIZE_TYPE__ size, void* ptr);
void* operator new[](__SIZE_TYPE__ size, void* ptr);

typedef int __attribute__((address_space(1))) int_1;

void test_delete(int_1 *ip1) {
    delete ip1; // expected-error{{'delete' cannot delete objects of type 'int' in address space '1'}}
}
