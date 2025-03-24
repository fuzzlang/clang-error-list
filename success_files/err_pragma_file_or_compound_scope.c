
float func_04(int x, float y) {
  if (x)
    return y + 2;
  #pragma STDC FENV_ACCESS ON // expected-error{{'#pragma STDC FENV_ACCESS' can only appear at file scope or at the start of a compound statement}}
  return x + y;
}
