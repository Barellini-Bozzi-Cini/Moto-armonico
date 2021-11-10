#include <iostream>
using namespace std;

int main (){
int scelta;
const float pi=3.1416;

cout<<"\n**Calcolo della pulsazione**";
cout<<"\nDati a disposizione?"
<<"\n1) Frequenza"
<<"\n2) Periodo"
<<endl;

cin>>scelta;

switch (scelta) {
case 1:
	double freq;
	cout<<"\nInserire valore frequenza in Hz: ";//inserire unità di misura
	cin>>freq;
	cout<<"Pulsazione: "<<2*pi*freq<<" **"; //unità da sistemare
	break;
	
case 2:
	double time;
	cout<<"\nInserire valore Periodo in **: "; //inserire unità di misura
	cin>>time;
	cout<<"Pulsazione: "<<2*pi/time<<" **"; //unità da sistemare
	break;
	
default:

	cout<<"\nUscita"; //inserire ritorno alla schermata precedente
}

return 0;
}
