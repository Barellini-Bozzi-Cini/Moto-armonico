#include <cstdint>
#include <array>
#include <varargs.h>
using namespace std;

// s = A cos(wt)
// v = -Aw sin(wt)
// a = -Aw^2 cos(wt)
// T = 1/f
// w = 2pigreco/T

constexpr double pi = 3.141592654;
constexpr int lenght = 7; //numero di variabili int64_t

using arr = std::array<bool, lenght>;

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
	MORE_VARIABLES //più incognite
};

auto find0(arr a, variabili c...){
	int b=0;
	int i;
	va_list args;
	va_start(args, c);
		for (i = 0; i < a.size(); i++) {
		if (a[i] == 0) ++b;
	}
	if (b == 0) throw NO_VARIABLE;
	else if (b > 1) throw MORE_VARIABLES;
	return i;
}

auto spazio(arr a) {
	int index;
	try {
		index = find0(a, SPAZIO, AMPIEZZA, PULSAZIONE, TEMPO);
	}
	catch (int e) {
		throw e;
	}
	switch (index) {
	case SPAZIO:
		break;
	case AMPIEZZA:
		break;
	case PULSAZIONE:
		break;
	case TEMPO:
		break;
	}
}
int main (){
int64_t spazio, accelerazione, pulsazione, frequenza, tempo, ampiezza, velocità; 
//input da ui di Android?
arr varInserita = { 0 }; 
//array che ricorda se un valore è inserito da utente o meno


return 0;
}
