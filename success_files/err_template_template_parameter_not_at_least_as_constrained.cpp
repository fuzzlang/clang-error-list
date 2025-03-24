
// RUN:  %clang_cc1 -std=c++2a -verify %s

template<typename T> concept C = T::f(); // #C
template<typename T> concept D = C<T> && T::g();
template<typename T> concept F = T::f(); // #F
template<template<C> class P> struct S1 { }; // #S1

template<C> struct X { };

template<D> struct Y { }; // #Y
template<typename T> struct Z { };
template<F> struct W { }; // #W

S1<X> s11;
S1<Y> s12; // This line should trigger the error
