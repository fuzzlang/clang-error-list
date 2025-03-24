
template<typename T> void capture(const T&);

class NonCopyable {
  NonCopyable(const NonCopyable&); // expected-note 2 {{implicitly declared private here}}
public:
  void foo() const;
};

void capture_by_copy(NonCopyable nc) {
  (void)[nc] { }; // expected-error{{capture of variable 'nc' as type 'NonCopyable' calls private copy constructor}}
}
