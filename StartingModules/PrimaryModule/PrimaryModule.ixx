export module PrimaryModule;

export import std;

export namespace PrimaryModule
{
	class SayHello
	{
	private:

		std::string who_ { };

		auto Set(const std::string& _) noexcept -> auto;

	public:
		explicit SayHello ( const std::optional<std::string>& _ = std::nullopt );

		auto Get ( ) noexcept -> const std::string;
	};
}

module : private;

const std::string exclamation_{ "!" };
const std::string hello_{ "Hello " };
const std::string world_{ "World!" };

auto PrimaryModule::SayHello::Set(const std::string& _) noexcept -> auto
{
	return _.empty() ?
		world_ :
		(_.ends_with(exclamation_) ?
			_ :
			_ + exclamation_);
}

PrimaryModule::SayHello::SayHello(
	const std::optional<std::string>& _) :
	who_{ Set(_.value_or(std::string{})) }
{

}

auto PrimaryModule::SayHello::Get() noexcept -> const std::string
{
	return hello_ + who_;
}


