#pragma once

#include "equation_solver.cpp"
#ifndef NDEBUG
#include <iostream>
#endif

class out {
public:
	auto& operator <<(iarr output) { //stampare o su console o su Android
		for (auto& i : output) {
#ifdef ANDROID

#elif !defined(NDEBUG)
			std::cout << i;
#else
#error la funzione out << non è definita
#endif
		}
		return *this;
	}
}out;

class in {
public:
	barr& a;
	auto& operator >>(int64_t input) { //input o da console o da Android
#ifdef ANDROID

#elif !defined(NDEBUG)
		std::cin >> input;
#else
#error la funzione in >> non è definita
#endif
		a[input] = true;
		return *this;
	}
}in;