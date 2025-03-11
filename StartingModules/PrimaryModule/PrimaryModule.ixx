export module PrimaryModule;

export import std;

export namespace PrimaryModule
{
	class HelloToWhom
	{
	private:
		const std::string exclamation_{ "!" };
		const std::string hello_{ "Hello " };
		const std::string world_{ "World!" };
		std::string who_{};

		auto Set(const std::string& _) noexcept -> auto
		{
			return _.empty() ? world_ : _ + exclamation_;
		}

	public:
		explicit HelloToWhom(const std::optional<std::string>& _ = std::nullopt) :
			who_{ Set(_.value_or(std::string{})) }
		{
		}

		auto SalutationWithAcknowledgement() noexcept -> const std::string
		{
			return hello_ + who_;
		}
	};
}
