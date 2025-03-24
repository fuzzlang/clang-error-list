
typedef struct { int x[8]; } svint8_t;

int main() {
  svint8_t init_int8;
  __real init_int8; // expected-error {{invalid type 'svint8_t'}}
  return 0;
}
