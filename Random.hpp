#pragma once
#include <Header.h>



namespace random
{
	

	template<template<typename>typename Dist, typename T>
	static T generate(const T& min, const T& max)
	{
		std::random_device rd{};
		std::mt19937 gen{ rd() };
		auto dist{ Dist<T>{ min, max } };
		return dist(gen);
	}
	template<typename Dist>
	constexpr static decltype(auto) generate(const size_t& size)
	{
		return[=]<typename T>(T min, T max)
		{
			std::vector<T> out(size);
			std::generate(std::begin(out), std::end(out),
						  [&]
						  {
							  return gen<Dist>(min, max);
						  }
						  );
			return out;
		};
	}
}