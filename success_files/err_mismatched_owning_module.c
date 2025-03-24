
#ifndef NO_GLOBAL
module;
extern int var; // expected-note {{previous declaration is here}}
int func(); // expected-note {{previous declaration is here}}
struct str; // expected-note {{previous declaration is here}}
using type = int;

template<typename> extern int var_tpl; // expected-note {{previous declaration is here}}
template<typename> int func_tpl(); // expected-note {{previous declaration is here}}
template<typename> struct str_tpl; // expected-note {{previous declaration is here}}
template<typename> using type_tpl = int; // expected-note {{previous declaration is here}}

typedef int type;
namespace ns { using ::func; }
namespace ns_alias = ns;
#endif

export module M;

#ifdef EXPORT
export {
#endif

extern int var; // expected-error {{declaration of 'var' in module M follows declaration in the global module}}
