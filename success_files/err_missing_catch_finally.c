
void test() {
    @try { // expected-error {{@try statement without a @catch and @finally clause}}
    }
}
