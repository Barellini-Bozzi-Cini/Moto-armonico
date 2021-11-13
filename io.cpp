#pragma once

#ifndef NDEBUG
#include <iostream>
#endif

class out {
public:
	template <typename t> auto& operator <<(t output) { //stampare o su console o su Android
#ifdef ANDROID

#elif !defined(NDEBUG)
			std::cout << i;
#else
#error la funzione out << non è definita
#endif
		return *this;
	}
}out;

class in {
public:
	template <typename t> auto& operator >>(t input) { //input o da console o da Android
#ifdef ANDROID

#elif !defined(NDEBUG)
		std::cin >> input;
#else
#error la funzione in >> non è definita
#endif
		return *this;
	}
}in;