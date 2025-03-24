
namespace cwg727 {
    template<typename T, typename U> struct Collision {
        template<typename> static int v1;
        // expected-error@-1 {{duplicate member 'v1'}}
        template<> int v1<T>; // #cwg727-v1-T
        template<> int v1<U>; 
    };

    Collision<int, int> c; // #cwg727-Collision-int-int
}
