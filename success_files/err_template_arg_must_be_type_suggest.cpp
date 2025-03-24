
namespace missing_typename {
    template <class T1, class T2> struct pair {}; // expected-note 7 {{template parameter is declared here}}

    template <class T1, class T2>
    struct map {
        typedef T1* iterator;
    };

    template <class T>
    class ExampleClass1 {
        struct ExampleItem;

        struct ExampleItemSet {
            typedef ExampleItem* iterator;
            ExampleItem* operator[](unsigned);
        };

        void foo() {
            // expected-error@+2 {{template argument for template type parameter must be a type; did you forget 'typename'?}}
            pair<ExampleItemSet::iterator, int> elt;
        }
    };
} // namespace missing_typename
