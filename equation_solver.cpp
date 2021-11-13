#include <cmath>
#include <array>
#include <varargs.h>

constexpr double pi = 3.141592654;

enum variabili : unsigned char {
	POSIZIONE = 0,
	ACCELERAZIONE,
	PULSAZIONE,
	FREQUENZA,
	TEMPO,
	AMPIEZZA,
	VELOCITA_MAX,
	ACCELERAZIONE_MAX,
	PERIODO,
	VELOCITA
};

constexpr int lenght = VELOCITA; //numero di variabili int64_t

using barr = std::array<bool, lenght>;
using iarr = std::array<int64_t, lenght>;

enum exceptions : unsigned char {
	NO_VARIABLE = 0, //nessuna incognita
	MORE_VARIABLES, //più incognite
	UNRECOGNIZED //errore non gestito
};

auto find0(barr a, int lenght, variabili c...) {
	int b = 0;
	int i;
	va_list args;
	va_start(args, c);
	for (i = 0; i < lenght; i++) {
		if (a[va_arg(args, variabili)] == false) ++b;
	}
	if (b == 0) throw NO_VARIABLE;
	else if (b > 1) throw MORE_VARIABLES;
	a[i] = true;
	return i;
}

namespace funzione {

// x = A cos(wt)
// v = -Aw sin(wt)
// a = -Aw^2 cos(wt) = -xw^2
// w = 2pigreco/T
// T = 1/f
// a_max = Aw^2 inoltre cos(wt) = -1 => wt = 180 = 2pi
// v_max = Aw	inoltre sin(wt) = -1 => wt = 270 = -30 = -pi/6

	auto posizione(iarr a, barr b) {
		int index;
		try {
			index = find0(b, 4, POSIZIONE, AMPIEZZA, PULSAZIONE, TEMPO);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case POSIZIONE: //trovare spazio
			return a[AMPIEZZA] * cos(a[PULSAZIONE] * a[TEMPO]);
			break;
		case AMPIEZZA: //trovare ampiezza
			return a[POSIZIONE] / cos(a[PULSAZIONE] * a[TEMPO]);
			break;
		case PULSAZIONE: //trovare pulsazione
			return acos(a[POSIZIONE] / a[AMPIEZZA]) / a[TEMPO];
			break;
		case TEMPO: //trovare tempo
			acos(a[POSIZIONE] / a[AMPIEZZA]) / a[PULSAZIONE];
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto velocità(iarr a, barr b) {
		int index;
		try {
			index = find0(b, 4, VELOCITA, AMPIEZZA, PULSAZIONE, TEMPO);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case AMPIEZZA: //trovare ampiezza
			return a[VELOCITA]/(-a[PULSAZIONE]*sin(a[PULSAZIONE]*a[TEMPO]));
			break;
		case PULSAZIONE: //trovare pulsazione
			throw MORE_VARIABLES; //non so risolvere equazioni con il seno quindi attendo la risoluzione di w=2pi/t
			break;
		case TEMPO: //trovare tempo
			return asin(a[VELOCITA]/(-a[AMPIEZZA]*a[PULSAZIONE]))/a[PULSAZIONE];
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto accelerazione(iarr a, barr b) {
		int index;
		try {
			index = find0(b, 3, POSIZIONE, ACCELERAZIONE, PULSAZIONE);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case POSIZIONE: //trovare spazio
			return a[ACCELERAZIONE] / -pow(a[PULSAZIONE], 2);
			break;
		case ACCELERAZIONE: //trovare accelerazione
			return -a[POSIZIONE]*pow(a[PULSAZIONE], 2);
			break;
		case PULSAZIONE: //trovare pulsazione
			return sqrt(a[ACCELERAZIONE]/-a[POSIZIONE]);
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto pulsazione(iarr a, barr b) {
		int index;
		try {
			index = find0(b, 1, PULSAZIONE, PERIODO);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case PULSAZIONE: //trovare pulsazione
			return 2*pi/a[PERIODO];
			break;
		case PERIODO: //trovare pulsazione
			return 2*pi/a[PULSAZIONE];
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto periodo(iarr a, barr b) {
		int index;
		try {
			index = find0(b, 2, PERIODO, FREQUENZA);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case PERIODO: //trovare periodo
			return 1/a[FREQUENZA];
			break;
		case FREQUENZA: //trovare frequenza
			return 1/a[PERIODO];
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto velocitàMAx(iarr a, barr b) {
		int index;
		try {
			index = find0(b);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case : //trovare periodo
			return ;
			break;
		case : //trovare frequenza
			return ;
			break;
		default: throw UNRECOGNIZED;
		}
	}
	auto accelerazioneMAx(iarr a, barr b) {
		int index;
		try {
			index = find0(b);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case : //trovare 
			return ;
			break;
		case : //trovare 
			return ;
			break;
		default: throw UNRECOGNIZED;
		}
	}
}

template <typename t> void calcAfter(t(*a), barr b, list<void*> recalc) { // se non ci sono abbastanza dati per calcolare allora si salva un puntatore dell'equazione in una lista e si spera che i dati siano calcolati da altre equazioni
	try {
		a(b);
	}
	catch (int e) {
		if (e == MORE_VARIABLES) {
			recalc.push_front(&ab;
		}
		else if (e == UNRECOGNIZED) {
			out << "\nErrore non riconosciuto!\n";
		}
	}
}