#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	double a;
	cout << fixed << setprecision(3);
	while(cin>>a){
		double semicirculo, areaQ, inferior, meio;
		double AScircular, ASScircular, preta, cinza, branca;
		double Htriangulo, Atriangulo;
		semicirculo = ((M_PI*(pow(a,2))/4));
		//cout << "semicirculo - " << semicirculo << endl;
		areaQ = a*a;
		//cout << "area - " << areaQ << endl;
		inferior = areaQ - semicirculo;
		//cout << "inferior - " << inferior << endl;
		meio = areaQ - (2*inferior);
		//cout <<" meio - " << meio << endl;
		Htriangulo = (a/2) * sqrt(3);
		Atriangulo = a*Htriangulo;
		AScircular = ((M_PI*(pow(a,2)/3)));
		ASScircular =  AScircular - (Atriangulo);
		AScircular += ASScircular;
		AScircular /= 2;
		//cout << "AScircular" << AScircular << endl;;
		preta = AScircular - meio;
		cinza = (inferior - (2*preta));
		branca = (areaQ - (4*cinza + 4*preta));
		cout << branca << " " << cinza*4 << " " << preta*4 << endl;
	}
	
	
	return 0;
}
