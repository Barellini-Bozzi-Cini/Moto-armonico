#include "io.cpp"
#include "equation_solver.cpp"

int main (){
arr dati;
barr varInserita = { 0 }; //bool array che ricorda se un valore è inserito da utente o meno
std::list<double(*)(arr, barr, int)> reCalc;

#ifndef NDEBUG
uint8_t cmd;
long long num;
out << "Menu:\n1. posizione\n2. velocità\n 3. accelerazione\n 4. pulsazione\n 5. periodo\n 6. velocità massima\n 7. accelerazione massima\n 8. calcolare\n 9. uscire\n";
do {
out << "scegliere:";
in >> cmd;
	if (cmd <= VELOCITA) {
		out << "Inserire valore: ";
		in >> num;
		dati[cmd] = num;
	}
	else if (cmd == 9) {
		out << "Programma terminato";
		return 0;
	}
} while (cmd != 8);
#endif

//******************input da ui di Android******************


calcAfter(&funzione::posizione, dati, varInserita, reCalc);
calcAfter(&funzione::velocità, dati, varInserita, reCalc);
calcAfter(&funzione::accelerazione, dati, varInserita, reCalc);
calcAfter(&funzione::pulsazione, dati, varInserita, reCalc);
calcAfter(&funzione::periodo, dati, varInserita, reCalc);
calcAfter(&funzione::velocitàMax, dati, varInserita, reCalc);
calcAfter(&funzione::accelerazioneMax, dati, varInserita, reCalc);

for (;reCalc.size()!=0;) {
	for (auto& i : reCalc) {
		calcAfter(i, dati, varInserita, reCalc);
	}
}

return 0;
}
