#include <cstdint>
#include <list>

using namespace std;

#include "io.cpp"
#include "equation_solver.cpp"

int main (){
iarr dati;
barr varInserita = { 0 }; //barray che ricorda se un valore Ë inserito da utente o meno
in.a = varInserita;
//******************input da ui di Android******************


list<void*> reCalc;

calcAfter(&funzione::posizione, varInserita, reCalc);
calcAfter(&funzione::velocit‡, varInserita, reCalc);
calcAfter(&funzione::accelerazione, varInserita, reCalc);
calcAfter(&funzione::pulsazione, varInserita, reCalc);
calcAfter(&funzione::periodo, varInserita, reCalc);
calcAfter(&funzione::velocit‡MAx, varInserita, reCalc);
calcAfter(&funzione::accelerazioneMAx, varInserita, reCalc);

for (;reCalc.size()!=0;) {
	for (auto& i : reCalc) {
		calcAfter(i, varInserita, reCalc);
	}
}

return 0;
}
