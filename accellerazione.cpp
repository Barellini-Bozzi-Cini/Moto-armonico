#include <iostream>
#include <math.h>   
using namespace std;

int main (){
double amp, time, puls, ang;

cout<<"\n**Calcolo dell'accelerazione'**";
cout<<"\nInserire ampiezza in **: "; //unit� di misura
cin>>amp;
amp=amp*-1;
cout<<"\nInserire tempo in **: ";//unit� di misura
cin>>time;
cout<<"\nInserire pulsazione in **: ";//unit� di misura
cin>>puls;
ang= cos (puls*time);
cout<<"Accellerazione: "<<amp*puls*puls*ang<<"metri/secondo^2"; //controllo unit� di misura
//ritorno al men� precedente?
return 0;
}
