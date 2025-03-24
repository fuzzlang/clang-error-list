
constexpr int ForStmt() {
  for (int n = 0; n < 10; ++n) {} // beforecxx14-error {{statement not allowed in constexpr function}}
  return 0;
}
