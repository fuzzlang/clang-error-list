
@interface MyClass
@property(assign, nullable_result) id p; // expected-error{{unknown property attribute 'nullable_result'}}
@end
