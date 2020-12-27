#pragma once

#include <type_traits>

namespace manager
{
	template<typename Type>
	class Singleton
	{
	public:
		static Type& Instance()
		{
			static_assert(std::is_base_of<Singleton, Type>::value);

			static Type SingleInstance;
			return SingleInstance;
		}
		virtual ~Singleton() = default;
	protected:
		Singleton() = default;

	private:
		//èdï°ñhé~
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(Singleton&&) = delete;
	};
}