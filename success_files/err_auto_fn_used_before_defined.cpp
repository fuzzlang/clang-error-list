
struct Conv1 {
  operator auto(); // expected-note {{declared here}}
} conv1;

int conv1a = conv1; // expected-error {{function 'operator auto' with deduced return type cannot be used before it is defined}}
