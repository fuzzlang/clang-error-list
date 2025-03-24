
struct Struct1 {
    void MemberFunction(); // expected-note {{'MemberFunction' declared here}}
};

void TestNonMemberToMember() {
    Struct1 st;
    [[clang::musttail]]         // expected-note {{tail call required by 'musttail' attribute here}}
    return st.MemberFunction(); // expected-error {{non-member function cannot perform a tail call to non-static member function 'MemberFunction'}}
}
