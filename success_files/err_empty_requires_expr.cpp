
// RUN: %clang_cc1 -std=c++2a -x c++ %s -verify

bool r1 = requires () { 
    // Expecting an error here due to empty requires expression
};
