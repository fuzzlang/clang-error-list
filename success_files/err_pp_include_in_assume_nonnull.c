
#pragma clang assume_nonnull begin

#include "nullability-pragmas-3.h" // expected-error{{cannot #include files inside '#pragma clang assume_nonnull'}}

#pragma clang assume_nonnull end
