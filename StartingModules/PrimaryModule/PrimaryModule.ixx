export module PrimaryModule;

export import std;

export namespace PrimaryModule
{
	class SayHello
	{
	private:
		const std::string exclamation_{ "!" };
		const std::string hello_{ "Hello " };
		const std::string world_{ "World!" };
		std::string who_ { };

		auto Set(const std::string& _) noexcept -> auto
		{
			return _.empty() ?
				world_ :
				(_.ends_with(exclamation_) ?
					_ :
					_ + exclamation_);
		}

	public:
		explicit SayHello ( const std::optional<std::string>& _ = std::nullopt ) :
			who_{ Set(_.value_or(std::string{})) }
		{

		}

		auto Get ( ) noexcept -> const std::string
		{
			return hello_ + who_;
		}
	};
}