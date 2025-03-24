
#define __counted_by(f)  __attribute__((counted_by(f)))

struct bar;

struct not_a_c99_fam {
  int count;
  struct bar *non_c99_fam[0] __counted_by(count); // expected-error {{'counted_by' on arrays only applies to C99 flexible array members}}
};
