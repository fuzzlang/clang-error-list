
namespace otherstd { // expected-note 2{{'otherstd' declared here}} \
  using namespace std; 
}

using namespace othestd; // expected-error{{no namespace named 'othestd'; did you mean 'otherstd'?}}
