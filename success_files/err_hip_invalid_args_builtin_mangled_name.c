
__global__ void kern1();
int y;

void fun1() {
  int x;
  const char *p;
  p = __builtin_get_device_side_mangled_name(); // expected-error {{invalid arguments to 'hip' built-in function}}
}
