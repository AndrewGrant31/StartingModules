import std;

import PrimaryModule;

auto main ( int argc, char* argv [ ] ) -> int
{
	auto helloToWhom { std::make_unique<PrimaryModule::HelloToWhom> (
		argc == 2 ?
		std::string{argv [ 1 ] } :
		std::string {}
	) };

	std::println ( "{}", helloToWhom->SalutationWithAcknowledgement ( ) );
}
