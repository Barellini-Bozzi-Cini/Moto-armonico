#include <iostream>
using namespace std;

int main (){
int scelta;
const float pi=3.1416;

cout<<"\n**Calcolo del periodo**";
cout<<"\nDati a disposizione?"
<<"\n1) Frequenza"
<<"\n2) Velocita' angolare"
<<endl;

cin>>scelta;

switch (scelta) {
	case 1:
		double freq;
		cout<<"\nInserire valore frequenza in **: ";//inserire unità di misura
		cin>>freq;
		cout<<"Periodo: "<<1/freq<<" secondi"; //unità da sistemare
		break;
		
	case 2:
		double vela;
		cout<<"\nInserire valore velocita' angolare in **: "; //inserire unità di misura
		cin>>vela;
		cout<<"Periodo: "<<2*pi/vela<<" secondi"; //unità da sistemare
		break;
		
	default:
	
		cout<<"\nUscita"; //inserire ritorno alla schermata precedente
}

return 0;
}
