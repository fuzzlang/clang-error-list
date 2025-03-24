
export module my_module;

module :private;

export int priv; // expected-error {{export declaration cannot be used in a private module fragment}}
