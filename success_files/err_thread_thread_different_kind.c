
extern thread_local int t17; // expected-note {{previous declaration is here}}
_Thread_local int t17; // expected-error {{thread-local declaration of 't17' with static initialization follows declaration with dynamic initialization}}
