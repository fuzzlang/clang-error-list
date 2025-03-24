
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++14 %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++98 %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++11 %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++14 %s -fdelayed-template-parsing
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++98 %s -fdelayed-template-parsing
// RUN: %clang_cc1 -fsyntax-only -verify -std=c++11 %s -fdelayed-template-parsing

template<class T1, typename T2> struct foo : 
    UnknownBase<T1,T2> // expected-error {{no template named 'UnknownBase'}}
{ };
