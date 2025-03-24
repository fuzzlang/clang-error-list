
namespace {
    // Reproducing the expected-error for the 'annotate' attribute.
    void bir [[clang::annotate("B", {1, 2, 3, 4})]] (); // both-error {{'annotate' attribute requires parameter 1 to be a constant expression}} \
                                                     // both-note {{subexpression not valid in a constant expression}}
}
