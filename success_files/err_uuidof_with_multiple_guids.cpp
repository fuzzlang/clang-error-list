
namespace PR16911 {
  struct __declspec(uuid("{12345678-1234-1234-1234-1234567890aB}")) uuid;
  struct __declspec(uuid("{12345678-1234-1234-1234-1234567890aB}")) uuid2;

  template <typename T, typename T2>
  struct thing {
  };

  const struct _GUID *y = &__uuidof(thing<uuid2, uuid>); // expected-error{{cannot call operator __uuidof on a type with multiple GUIDs}}
}
