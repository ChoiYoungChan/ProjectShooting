#pragma once

namespace singleton
{
	class Singleton
	{
	public:
		static Singleton& Instance()
		{
			static Singleton instance;

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