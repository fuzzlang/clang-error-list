
@interface Radar7861841 {
@public
  int x;
}
@property (assign) int y;
@end

int f0(Radar7861841 *a) { return a.x; } // expected-error {{property 'x' not found on object of type 'Radar7861841 *'; did you mean to access instance variable 'x'}}
