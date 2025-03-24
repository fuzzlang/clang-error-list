
#define __counted_by(f) __attribute__((counted_by(f)))

struct no_found_count_not_in_substruct {
  unsigned long flags;
  unsigned char count; // expected-note {{'count' declared here}}
  struct A {
    int dummy;
    int array[] __counted_by(count); // expected-error {{'counted_by' field 'count' isn't within the same struct as the annotated flexible array}}
  } a;
};
