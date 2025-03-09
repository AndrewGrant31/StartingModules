export module PrimaryModule;

export import std;

#pragma region Immutable Variables
namespace ImmutableVariables
{
	template <typename T> requires
		std::same_as<T, std::string> or
		std::same_as<T, std::string_view>
		class Immutable
	{
	private:
		const T exclamation_{ "!" };
		const T hello_{ "Hello " };
		const T world_{ "World!" };

	public:
		T Exclamation{ exclamation_ };
		T Hello{ hello_ };
		T World{ world_ };
	};
}
#pragma endregion Immutable Variables
#pragma region Mutable Variables
namespace MutableVariables
{
	template <typename T> requires
		std::same_as<T, std::string> or
		std::same_as<T, std::string_view>
		class Mutable
	{
	private:
		T value_;

	public:
		explicit Mutable(const T& _) :
			value_{ _ }
		{

		}

		T Value{ value_ };
	};
}
#pragma endregion Mutable Variables

#pragma region Public
export namespace PrimaryModule
{
	class SayHello
	{
	private:
		std::unique_ptr<MutableVariables::Mutable<std::string>> who_uptr;
		std::unique_ptr<ImmutableVariables::Immutable<std::string>> immutable_uptr{
			std::make_unique<ImmutableVariables::Immutable<std::string>>()};

		auto Exclamation() noexcept -> const auto
		{
			return immutable_uptr->Exclamation;
		}
		auto Hello() noexcept -> const auto
		{
			return immutable_uptr->Hello;
		}
		auto World() noexcept -> const auto
		{
			return immutable_uptr->World;
		}
		auto Who() noexcept -> const auto
		{
			return who_uptr->Value;
		}

		auto Set(const std::string& _) noexcept -> auto
		{
			return _.empty() ?
				World() :
				(_.ends_with(Exclamation()) ?
					_ :
					_ + Exclamation());
		}

	public:
		explicit SayHello(const std::optional<std::string>& _ = std::nullopt) :
			who_uptr{ 
			std::make_unique < MutableVariables::Mutable<std::string>>(
			Set(_.value_or(std::string{}))) }
		{

		}

		auto SalutationWithAcknowledgement() noexcept -> const std::string
		{
			return  Hello() + Who();
		}

	};
}
#pragma endregion Public