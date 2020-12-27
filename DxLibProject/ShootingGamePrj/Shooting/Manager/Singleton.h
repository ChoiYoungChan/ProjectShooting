#pragma once

#include <type_traits>

namespace singleton
{
	template<typename Type> class Singleton
	{
	public:
		static Type& Instance()
		{
			static_assert(std::is_base_of<Singleton, Type>::value);

			static Type instance;
			return instance;
		}
		virtual ~Singleton() = default;

	protected:
		Singleton() = default;
	private:
		Singleton(const Singleton&) = delete;
		Singleton& operator = (const Singleton&) = delete;

		Singleton(const Singleton&&) = delete;
		Singleton&& operator = (const Singleton&&) = delete;
	};
}