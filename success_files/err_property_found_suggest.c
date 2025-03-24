
@interface Radar7861841 {
@public
  int x;
}
@property (assign) int y;
@end

int f1(Radar7861841 *a) { return a->y; } // expected-error {{property 'y' found on object of type 'Radar7861841 *'; did you mean to access it with the "." operator?}}
