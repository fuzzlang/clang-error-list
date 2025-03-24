
template <typename T>
class BasicStringPiece {
public:
    BasicStringPiece(T value) {}
};

// Explicit instantiation definition
template class BasicStringPiece<int>;

extern template class BasicStringPiece<int>;  // expected-error {{explicit instantiation declaration (with 'extern') follows explicit instantiation definition (without 'extern')}}
