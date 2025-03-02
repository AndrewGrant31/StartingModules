export module PrimaryModule;

export import std;

#pragma region Public
export namespace PrimaryModule
{
	class SayHello
	{
	private:
#pragma region Cannot be seen by the outside world
		const std::string exclamation_ { "!" };
		const std::string hello_ { "Hello " };
		const std::string world_ { "World!" };
		std::string who_ { };

		auto Set ( const std::string& _ ) noexcept -> auto;
#pragma endregion

	public:
#pragma region Can be seen by the outside world
		explicit SayHello ( const std::optional<std::string>& _ = std::nullopt );

		auto Get ( ) noexcept -> const std::string;
#pragma endregion
	};
}
#pragma endregion


