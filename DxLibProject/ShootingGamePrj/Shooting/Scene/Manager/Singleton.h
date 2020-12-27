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
			//TypeがSingletonを継承しているかを確認する
			static_assert(std::is_base_of<Singleton, Type>::value);

			static Type SingleInstance;
			return SingleInstance;
		}
		Singleton() = default;
		virtual ~Singleton() = default;

	private:
		//重複防止
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(Singleton&&) = delete;
	};
}