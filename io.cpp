#pragma once

#include <type_traits>
#ifndef NDEBUG
#include <iostream>
#endif

class Out {
public:
	template <typename t> inline auto& operator <<(t output) { //stampare o su console o su Android
#ifdef ANDROID

#elif !defined(NDEBUG)
			std::cout << output;
#else
#error la funzione out << non è definita
#endif
		return *this;
	}
}out;

class In {
public:
	template <typename t> inline auto& operator >>(t input) { //input o da console o da Android
#ifdef ANDROID

#elif !defined(NDEBUG)
		std::cin >> input;
#else
#error la funzione in >> non è definita
#endif
		return *this;
	}
}in;