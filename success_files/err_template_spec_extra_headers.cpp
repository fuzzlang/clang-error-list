
template<a> // expected-error +{{}}
struct int_;

template<a> // expected-error +{{}}
template<int, typename T1, typename>
struct ac {
    typedef T1 ae;
};

template<class> struct aaa {
    typedef ac<1, int, int>::ae ae; // expected-error +{{}}
};

template<class> struct state_machine {
    typedef aaa<int>::ae aaa;
    int start() {
        ant(0);
    }
    
    template<class>
    struct region_processing_helper {
        template<class, int=0>
        struct In;
        
        template<int my>
        struct In<a::int_<aaa::a>, my>; // expected-error +{{}}
        
        template<class Event>
        int process(Event) {
            In<a::int_<0>> a; // expected-error +{{}}
        }
    }; // expected-error +{{}}
    
    template<class Event>
    int ant(Event) {
        region_processing_helper<int>* helper;
        helper->process(0); // expected-error +{{}}
    }
};

int a() {
    state_machine<int> p;
    p.ant(0);
}
