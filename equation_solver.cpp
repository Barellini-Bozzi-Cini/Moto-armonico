#pragma once

#include "io.cpp"

#include <cmath>
#include <list>
#include <array>
#include <varargs.h>

constexpr double pi = 3.141592653589793238;

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

constexpr int lenght = variabili::VELOCITA; //numero di variabili

using barr = std::array<bool, lenght>;
using arr = std::array<double, lenght>;

enum eccezioni : unsigned char {
	NO_VARIABLE = 0, //nessuna incognita
	MORE_VARIABLES, //pi˘ incognite
	UNRECOGNIZED //errore non gestito
};

namespace formula {

// x = A cos(wt)
// v = -Aw sin(wt)
// a = -Aw^2 cos(wt) = -xw^2
// w = 2pigreco/T
// T = 1/f
// a_max = Aw^2 => cos(wt) = -1 => wt = 180 = 2pi
// v_max = Aw	=> sin(wt) = -1 => wt = 270 = -30 = -pi/6

	auto find0 (barr a, int lenght, variabili c...) {
		int b = 0;
		int i;
		va_list args;
		va_start(args, c);
		for (i = 0; i < lenght; i++) {
			if (a[va_arg(args, variabili)] == false) ++b;
		}
		if (b == 0) throw eccezioni::NO_VARIABLE;
		else if (b > 1) throw eccezioni::MORE_VARIABLES;
		a[i] = true;
		return i;
	}
	auto posizione(arr a, barr b, int index) {
		try {
			index = find0(b, 4, variabili::POSIZIONE, variabili::AMPIEZZA, variabili::PULSAZIONE, variabili::TEMPO);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case variabili::POSIZIONE: //trovare spazio
			return a[variabili::AMPIEZZA] * cos(a[variabili::PULSAZIONE] * a[variabili::TEMPO]);
			break;
		case variabili::AMPIEZZA: //trovare ampiezza
			return a[variabili::POSIZIONE] / cos(a[variabili::PULSAZIONE] * a[variabili::TEMPO]);
			break;
		case variabili::PULSAZIONE: //trovare pulsazione
			return acos(a[variabili::POSIZIONE] / a[variabili::AMPIEZZA]) / a[variabili::TEMPO];
			break;
		case variabili::TEMPO: //trovare tempo
			return acos(a[variabili::POSIZIONE] / a[variabili::AMPIEZZA]) / a[variabili::PULSAZIONE];
			break;
		default: throw eccezioni::UNRECOGNIZED;
		}
	}
	auto velocit‡(arr a, barr b, int index) {
		try {
			index = find0(b, 4, variabili::VELOCITA, variabili::AMPIEZZA, variabili::PULSAZIONE, variabili::TEMPO);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case variabili::AMPIEZZA: //trovare ampiezza
			return a[variabili::VELOCITA]/(-a[variabili::PULSAZIONE]*sin(a[variabili::PULSAZIONE]*a[variabili::TEMPO]));
			break;
		case variabili::PULSAZIONE: //trovare pulsazione
			throw eccezioni::MORE_VARIABLES; //non so risolvere equazioni con il seno quindi attendo la risoluzione di w=2pi/t
			break;
		case variabili::TEMPO: //trovare tempo
			return asin(a[variabili::VELOCITA]/(-a[variabili::AMPIEZZA]*a[variabili::PULSAZIONE]))/a[variabili::PULSAZIONE];
			break;
		default: throw eccezioni::UNRECOGNIZED;
		}
	}
	auto accelerazione(arr a, barr b, int index) {
		try {
			index = find0(b, 3, variabili::POSIZIONE, variabili::ACCELERAZIONE, variabili::PULSAZIONE);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case variabili::POSIZIONE: //trovare spazio
			return a[ACCELERAZIONE] / -pow(a[PULSAZIONE], 2);
			break;
		case variabili::ACCELERAZIONE: //trovare accelerazione
			return -a[POSIZIONE]*pow(a[PULSAZIONE], 2);
			break;
		case variabili::PULSAZIONE: //trovare pulsazione
			return sqrt(a[variabili::ACCELERAZIONE]/-a[variabili::POSIZIONE]);
			break;
		default: throw eccezioni::UNRECOGNIZED;
		}
	}
	auto pulsazione(arr a, barr b, int index) {
		try {
			index = find0(b, 1, variabili::PULSAZIONE, variabili::PERIODO);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case variabili::PULSAZIONE: //trovare pulsazione
			return 2*pi/a[variabili::PERIODO];
			break;
		case variabili::PERIODO: //trovare pulsazione
			return 2*pi/a[variabili::PULSAZIONE];
			break;
		default: throw eccezioni::UNRECOGNIZED;
		}
	}
	auto periodo(arr a, barr b, int index) {
		try {
			index = find0(b, 2, variabili::PERIODO, variabili::FREQUENZA);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case variabili::PERIODO: //trovare periodo
			return 1/a[variabili::FREQUENZA];
			break;
		case variabili::FREQUENZA: //trovare frequenza
			return 1/a[variabili::PERIODO];
			break;
		default: throw eccezioni::UNRECOGNIZED;
		}
	}
	auto velocit‡Max(arr a, barr b, int index) {
		try {
			index = find0(b, 2, variabili::AMPIEZZA, variabili::PULSAZIONE, variabili::VELOCITA_MAX);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case variabili::VELOCITA_MAX: //trovare velocit‡ max
			return a[variabili::AMPIEZZA]*a[variabili::PULSAZIONE];
			break;
		case variabili::AMPIEZZA: //trovare ampiezza
			return a[variabili::VELOCITA_MAX]/a[variabili::PULSAZIONE];
			break;
		case variabili::PULSAZIONE: //trovare pulsazione
			return a[variabili::VELOCITA_MAX] / a[variabili::AMPIEZZA];
			break;
		default: throw eccezioni::UNRECOGNIZED;
		}
	}
	auto accelerazioneMax(arr a, barr b, int index) {
		try {
			index = find0(b, variabili::AMPIEZZA, variabili::PULSAZIONE, variabili::ACCELERAZIONE_MAX);
		}
		catch (int e) {
			throw e;
		}
		switch (index) {
		case variabili::AMPIEZZA: //trovare ampiezza
			return a[variabili::ACCELERAZIONE_MAX]/pow(a[variabili::PULSAZIONE],2);
			break;
		case variabili::PULSAZIONE: //trovare pulsazione
			return sqrt(a[variabili::ACCELERAZIONE_MAX] / a[variabili::AMPIEZZA]);
			break;
		case variabili::ACCELERAZIONE_MAX: //trovare accelerazione max
			return a[variabili::AMPIEZZA]*pow(a[variabili::PULSAZIONE], 2);
			break;
		default: throw eccezioni::UNRECOGNIZED;
		}
	}
}

template <typename t> void calcAfter(t a, arr b, barr c, std::list<t> recalc) { // se non ci sono abbastanza dati per calcolare allora si salva un puntatore dell'equazione in una lista e si spera che i dati siano calcolati da altre equazioni
	int index;
	double result;

	try {
		result = (*a)(b, c, index);
	}
	catch (int e) {
		if (e == eccezioni::MORE_VARIABLES) {
			recalc.push_front(a);
		}
		else if (e == eccezioni::UNRECOGNIZED) {
			out << "\nNon in grado di trovare variabili inserite da utete o meno\n";
			return;
		}
	}
	switch (index) {
	case variabili::POSIZIONE:
		out << "posizione: ";
		break;
	case variabili::ACCELERAZIONE:
		out << "accelerazione: ";
		break;
	case variabili::PULSAZIONE:
		out << "pulsazione: ";
		break;
	case variabili::FREQUENZA:
		out << "frequenza: ";
		break;
	case variabili::TEMPO:
		out << "tempo: ";
		break;
	case variabili::AMPIEZZA:
		out << "ampiezza: ";
		break;
	case variabili::VELOCITA_MAX:
		out << "velocit‡ massima: ";
		break;
	case variabili::ACCELERAZIONE_MAX:
		out << "accelerazione massima: ";
		break;
	case variabili::PERIODO:
		out << "periodo: ";
		break;
	case variabili::VELOCITA:
		out << "velocit‡: ";
		break;
	default: out << "Errore nello switch di calcAfter";
		break;
	}
	out << result;
}