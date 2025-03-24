
#define ALIGNED(x) __attribute__((aligned(x)))

typedef ALIGNED(2) struct {
    char a[3];
} aligned_before_struct;

static_assert(sizeof(aligned_before_struct)       == 3, "");
static_assert(sizeof(aligned_before_struct[1])    == 4, ""); // expected-error {{size of array element}}
static_assert(sizeof(aligned_before_struct[2])    == 6, ""); // expected-error {{size of array element}}
static_assert(sizeof(aligned_before_struct[2][1]) == 8, ""); // expected-error {{size of array element}}
static_assert(sizeof(aligned_before_struct[1][2]) == 6, ""); // expected-error {{size of array element}}
