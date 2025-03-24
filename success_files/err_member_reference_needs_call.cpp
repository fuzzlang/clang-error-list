
namespace FuncInMemberExpr {
  struct Vec {
    int size();
  };
  
  Vec fun1();
  
  int test1() {
    return fun1.size(); // expected-error {{base of member reference is a function; perhaps you meant to call it with no arguments}}
  }
}
