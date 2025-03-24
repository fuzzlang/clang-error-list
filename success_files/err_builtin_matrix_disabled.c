
// RUN: %clang_cc1 %s -triple i686-apple-darwin -verify -fsyntax-only

// Matrix types are disabled by default.

#if __has_extension(matrix_types)
#error Expected extension 'matrix_types' to be disabled
#endif

typedef float fx3x3_t __attribute__((matrix_type(3, 3)));
