#pragma once

#include <type_traits>

using namespace std;

namespace manager
{
	template<typename Type>
	class Singleton
	{
	public:
		static Type& Instance()
		{
			static_assert(is_base_of<Singleton, Type>::value);

			static Type SingleInstance;
			return SingleInstance;
		}
		virtual ~Singleton() = default;
	protected:
		Singleton() = default;

	private:
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(Singleton&&) = delete;
	};
}