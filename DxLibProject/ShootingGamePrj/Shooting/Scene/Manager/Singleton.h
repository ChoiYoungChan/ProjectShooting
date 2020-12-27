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
			//Type��Singleton���p�����Ă��邩���m�F����
			static_assert(std::is_base_of<Singleton, Type>::value);

			static Type SingleInstance;
			return SingleInstance;
		}
		Singleton() = default;
		virtual ~Singleton() = default;

	private:
		//�d���h�~
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(Singleton&&) = delete;
	};
}