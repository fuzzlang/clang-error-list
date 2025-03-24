
struct nontrivial
{
  nontrivial() {}
};

nontrivial needs_trivial_ctor __attribute__((loader_uninitialized));
