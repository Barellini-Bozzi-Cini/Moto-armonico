#include "equation_solver.cpp"
#include <limits>

int main (){
arr dati;
barr varInserita = { 0 }; //bool array che ricorda se un valore è inserito da utente o meno
std::list<double(*)(arr, barr, int)> reCalc;

#ifndef NDEBUG
char cmd = 0;
int num;

std::cout << "Menu:\n 1. posizione\n 2. velocità\n 3. accelerazione\n 4. pulsazione\n 5. periodo\n 6. velocità massima";
std::cout << "\n 7. accelerazione massima\n 8. calcolare\n 9. uscire\n";
do {
std::cout << "scegliere:";
std::cin >> cmd;
	if (!std::cin) {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	std::cout << "errore input!\n";
	}
	else if (cmd < 9) {
		std::cout << "Inserire valore: ";
		std::cin >> num;
		dati[cmd-1] = num;
		varInserita[cmd-1] = true;
	}
	else if (cmd == 9) {
		std::cout << "Programma terminato";
		return 0;
	}
} while (cmd != 8);
#endif

//******************input da ui di Android******************


calcAfter(&formula::posizione, dati, varInserita, reCalc);
calcAfter(&formula::velocità, dati, varInserita, reCalc);
calcAfter(&formula::accelerazione, dati, varInserita, reCalc);
calcAfter(&formula::pulsazione, dati, varInserita, reCalc);
calcAfter(&formula::periodo, dati, varInserita, reCalc);
calcAfter(&formula::velocitàMax, dati, varInserita, reCalc);
calcAfter(&formula::accelerazioneMax, dati, varInserita, reCalc);

for (;reCalc.size()!=0;) {
	for (auto& i : reCalc) {
		calcAfter(i, dati, varInserita, reCalc);
	}
}

return 0;
}
