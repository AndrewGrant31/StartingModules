module PrimaryModule;

import std;

namespace PrimaryModule
{
	auto SayHello::Set ( const std::string& _ ) noexcept -> auto
	{
		return _.empty ( ) ?
			world_ :
			( _.ends_with ( exclamation_ ) ?
				_ :
				_ + exclamation_ );
	}

	SayHello::SayHello (
		const std::optional<std::string>& _ ) :
		who_ { Set ( _.value_or ( std::string{} ) ) }
	{

	}

	auto SayHello::Get ( ) noexcept -> const std::string
	{
		return hello_ + who_;
	}
}