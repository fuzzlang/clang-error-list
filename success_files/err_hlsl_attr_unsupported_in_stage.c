
// expected-error@+2 {{attribute 'SV_GroupIndex' is unsupported in 'pixel' shaders}}
[shader("pixel")]
void pixel(int GI : SV_GroupIndex) {}
