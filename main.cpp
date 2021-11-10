#include <cstdint>
#include <array>
#include <exception>

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
	SPAZIO,
	ACEELERAZIONE,
	PULSAZIONE,
	FREQUENZA,
	TEMPO,
	AMPIEZZA,
	VELOCITA
};

using error = std::exception;

auto find0(arr a){
	for (auto& i : a) {
		if (i == 0) return i;
	}
	throw "Nessuna variabile da calcolare";
}

auto spazio(arr a) {

}

int main (){
int64_t spazio, accelerazione, pulsazione, frequenza, tempo, ampiezza, velocità; 
//input da ui di Android?
arr varInserita = { 0 }; 
//array che ricorda se un valore è inserito da utente o meno


return 0;
}
