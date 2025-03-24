
auto SC1 = [&]() static {}; // expected-error {{a static lambda cannot have any captures}}
