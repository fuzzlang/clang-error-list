
template<template<typename T> class X> struct A; // expected-note 2{{previous template template parameter is here}}

template<typename T> void f(int);

A<f> *a9; // expected-error{{must be a class template}}
