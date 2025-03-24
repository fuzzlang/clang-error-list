
module;

// This import is expected to cause an error as it is in the global module fragment.
import :part; // expected-error {{module partition imports cannot be in the global module fragment}}

export module f;
