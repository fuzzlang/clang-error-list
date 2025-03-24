
struct AnIncompleteType;

static_assert(!__is_pod(AnIncompleteType)); // expected-error {{incomplete type}}
