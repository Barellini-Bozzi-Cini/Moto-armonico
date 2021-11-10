#include <cstdint>
#include <cmath>
#include <array>
#include <list>
#include <varargs.h>

#ifndef NDEBUG // definito in cmake di default
#define DEBUG
#endif

#ifdef DEBUG
#include <iostream>
#endif

using namespace std;

// s = A cos(wt)
// v = -Aw sin(wt)
// a = -Aw^2 cos(wt)
// T = 1/f
// w = 2pigreco/T

class out {
public:
	template <typename t> void operator <<(t output) { //stampare o su console o con Android
#ifdef ANDROID

#elif defined(DEBUG)
	cout << output;
#else
#error la funzione out non è definita
#endif
	}
}out;

constexpr double pi = 3.141592654;
constexpr int lenght = 7; //numero di variabili int64_t

using barr = std::array<bool, lenght>;
using iarr = std::array<int64_t, lenght>;

enum variabili{
	SPAZIO=0,
	ACEELERAZIONE,
	PULSAZIONE,
	FREQUENZA,
	TEMPO,
	AMPIEZZA,
	VELOCITA
};

enum exception {
	NO_VARIABLE=0, //nessuna incognita
	MORE_VARIABLES, //più incognite
	UNRECOGNIZED //errore non gestito
};

auto find0(barr a, int lenght, variabili c...){
	int b = 0;
	int i;
	va_list args;
	va_start(args, c);
	for (i = 0; i < lenght; i++) {
		if (a[va_arg(args, variabili)] == false) ++b;
	}
	if (b == 0) throw NO_VARIABLE;
	else if (b > 1) throw MORE_VARIABLES;
	return i;
}

namespace funzione {
	auto spazio(iarr a, barr b) {
		int index;
		try {
			index = find0(b, 4, SPAZIO, AMPIEZZA, PULSAZIONE, TEMPO);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case SPAZIO: //trovare spazio
			return a[AMPIEZZA] * cos(a[PULSAZIONE] * a[TEMPO]);
			break;
		case AMPIEZZA: //trovare ampiezza
			return a[SPAZIO]/ cos(a[PULSAZIONE] * a[TEMPO]);
			break;
		case PULSAZIONE: //trovare pulsazione
			return acos(a[SPAZIO] / a[AMPIEZZA]) / a[TEMPO];
			break;
		case TEMPO: //trovare tempo
			acos(a[SPAZIO] / a[AMPIEZZA]) / a[PULSAZIONE];
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto velocità(iarr a, barr b) {
		int index;
		try {
			index = find0(b);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case : //trovare spazio
			return ;
			break;
		case : //trovare ampiezza
			return ;
			break;
		case : //trovare pulsazione
			return ;
			break;
		case : //trovare tempo
			return ;
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto accelerazione(iarr a, barr b) {
		int index;
		try {
			index = find0(b);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case : //trovare spazio
			return ;
			break;
		case : //trovare ampiezza
			return ;
			break;
		case : //trovare pulsazione
			return ;
			break;
		case : //trovare tempo
			return ;
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto periodo(iarr a, barr b) {
		int index;
		try {
			index = find0(b);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case : //trovare spazio
			return ;
			break;
		case : //trovare ampiezza
			return ;
			break;
		case : //trovare pulsazione
			return ;
			break;
		case : //trovare tempo
			return ;
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto pulsazione(iarr a, barr b) {
		int index;
		try {
			index = find0(b);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case : //trovare spazio
			return ;
			break;
		case : //trovare ampiezza
			return ;
			break;
		case : //trovare pulsazione
			return ;
			break;
		case : //trovare tempo
			return ;
			break;
		default: throw UNRECOGNIZED;
		}
	}
}

template <typename t> void calcAfter(t (*a)(iarr b, barr c)) { // se non ci sono abbastanza dati per calcolare allora si salva un puntatore dell'equazione in una lista e si spera che i dati siano calcolati da altre equazioni
	extern list<void*> recalc;
	extern barr varInserita;
	try {
		a(varInserita);
	}
	catch (int e) {
		if (e == MORE_VARIABLES) {
			recalc.push_front(&a);
		}
		else if (e == UNRECOGNIZED) {
			out << "\nErrore non riconosciuto!\n";
		}
	}
}

int main (){
iarr dati; 
//input da ui di Android?
barr varInserita = { 0 };
//barray che ricorda se un valore è inserito da utente o meno
list<void*> recalc;

calcAfter(&funzione::spazio);
calcAfter(&funzione::velocità);
calcAfter(&funzione::accelerazione);
calcAfter(&funzione::periodo);
calcAfter(&funzione::pulsazione);
 
//TODO Calcolo di funzioni in recalc

return 0;
}
