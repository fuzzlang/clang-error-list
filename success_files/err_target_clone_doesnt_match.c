
// expected-error@+3 {{'target_clones' attribute does not match previous declaration}}
// expected-note@-2 {{previous declaration is here}}
// expected-warning@+1 {{version list contains entries that don't impact code generation}}
int __attribute__((target_clones("rng", "fp16fml+fp", "default"))) redecl4(void);
int __attribute__((target_clones("dgh+memtag+rpres+ls64_v", "ebf16+dpb+sha1", "default"))) redecl4(void) { return 1; }
