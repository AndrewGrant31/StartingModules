import PrimaryModule;

import std;

auto main ( int argc, char* argv [ ] ) -> int
{
	auto sayHello { std::make_unique<PrimaryModule::SayHello> (
		argc == 2 ?
		std::string{argv [ 1 ] } :
		std::string {}
	) };

	std::println ( "{}", sayHello->Get ( ) );
}
