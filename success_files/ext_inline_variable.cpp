
// expected-error@-1 {{duplicate member 'v1'}}
//   expected-note@#cwg727-Collision-int-int {{in instantiation of template class 'cwg727::Collision<int, int>' requested here}}
//   expected-note@#cwg727-v1-T {{previous}}

template<typename T>
struct Collision {
    static inline int v1;  // first declaration
    static inline int v1;  // duplicate declaration
};
