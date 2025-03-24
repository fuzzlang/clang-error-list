
int (*f7)(int n [[carries_dependency]]); // expected-error {{'[[carries_dependency]]' attribute only allowed on parameter in a function declaration}}

int f(int a [[carries_dependency]]) { // expected-error {{'[[carries_dependency]]' attribute only allowed on parameter in a function declaration}}
    return a;
}
