
struct Empty {};
constexpr Empty e = {Empty()};

struct BoolPair {
  bool first;
  bool second;
};

struct Ints {
  int a = 20;
  int b = 30;
  bool c = true;
  BoolPair bp = {true, false};
  int numbers[3] = {1,2,3};

  static const int five = 5;
  static constexpr int getFive() {
    return five;
  }

  constexpr int getTen() const {
    return 10;
  }
};

static_assert(Ints::getFive() == 5, "");

constexpr Ints ints;
static_assert(ints.a == 20, "");
static_assert(ints.b == 30, "");
static_assert(ints.c, "");
static_assert(ints.getTen() == 10, "");
static_assert(ints.numbers[0] == 1, "");
static_assert(ints.numbers[1] == 2, "");
static_assert(ints.numbers[2] == 3, "");

constexpr const BoolPair &BP = ints.bp;
static_assert(BP.first, "");
static_assert(!BP.second, "");
static_assert(ints.bp.first, "");
static_assert(!ints.bp.second, "");

constexpr Ints ints2{-20, -30, false};
static_assert(ints2.a == -20, "");
static_assert(ints2.b == -30, "");
static_assert(!ints2.c, "");

constexpr Ints getInts() {
  return {64, 128, true};
}
constexpr Ints ints3 = getInts();
static_assert(ints3.a == 64, "");
static_assert(ints3.b == 128, "");
static_assert(ints3.c, "");

constexpr Ints ints4 = {
  .a = 40 * 50,
  .b = 0,
  .c = (ints.a > 0),

};
static_assert(ints4.a == (40 * 50), "");
static_assert(ints4.b == 0, "");
static_assert(ints4.c, "");
static_assert(ints4.numbers[0] == 1, "");
static_assert(ints4.numbers[1] == 2, "");
static_assert(ints4.numbers[2] == 3, "");

constexpr Ints ints5 = ints4;
static_assert(ints5.a == (40 * 50), "");
static_assert(ints5.b == 0, "");
static_assert(ints5.c, "");
static_assert(ints5.numbers[0] == 1, "");
static_assert(ints5.numbers[1] == 2, "");
static_assert(ints5.numbers[2] == 3, "");

struct Ints2 {
  int a = 10;
  int b; // Missing initialization
};
constexpr Ints2 ints22; // both-error {{without a user-provided default constructor}}

constexpr Ints2 I2 = Ints2{12, 25};
static_assert(I2.a == 12, "");
static_assert(I2.b == 25, "");

class C {
  public:
    int a;
    int b;

  constexpr C() : a(100), b(200) {}

  constexpr C get() const {
    return *this;
  }
};

constexpr C c;
static_assert(c.a == 100, "");
static_assert(c.b == 200, "");

constexpr C c2 = C().get();
static_assert(c2.a == 100, "");
static_assert(c2.b == 200, "");

constexpr const C &c3 = C().get();

class D {
public:
  unsigned a : 4;
  constexpr D() : a(15) {}
  constexpr D get() const {
    return *this;
  }
};
constexpr const D &d4 = D().get();

constexpr int getB() {
  C c;
  int &j = c.b;

  j = j * 2;

  return c.b;
}
static_assert(getB() == 400, "");

constexpr int getA(const C &c) {
  return c.a;
}
static_assert(getA(c) == 100, "");

constexpr const C* getPointer() {
  return &c;
}
static_assert(getPointer()->a == 100, "");

constexpr C RVOAndParams(const C *c) {
  return C();
}
constexpr C RVOAndParamsResult = RVOAndParams(&c);

constexpr C RVOAndParams(int a) {
  return C();
}
constexpr C RVOAndParamsResult2 = RVOAndParams(12);

class Bar { // both-note {{definition of 'Bar' is not complete}}
public:
  constexpr Bar(){}
  constexpr Bar b; // both-error {{cannot be constexpr}} 
};
