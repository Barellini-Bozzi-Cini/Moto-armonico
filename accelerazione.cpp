#include <iostream>
#include <math.h>   
using namespace std;

int main (){
double amp, time, puls, ang;

cout<<"\n**Calcolo dell'accelerazione'**";
cout<<"\nInserire ampiezza in **: "; //unità di misura
cin>>amp;
amp=amp*-1;
cout<<"\nInserire tempo in **: ";//unità di misura
cin>>time;
cout<<"\nInserire pulsazione in **: ";//unità di misura
cin>>puls;
ang= cos (puls*time);
cout<<"Accelerazione: "<<amp*puls*puls*ang<<"metri/secondo^2"; //controllo unità di misura
//ritorno al menù precedente?
return 0;
}
