#include<iostream>

using namespace std;

struct tija{
	int contor=0;
	int elemente[10];
};

tija a, b, c;

void afiseazaTije(){
	cout<<"tija A: ";
	for(int i=1;i<=a.contor;i++){
		cout<<a.elemente[i]<<" ";
	}
	cout<<"\n";
	cout<<"tija B: ";
	for(int i=1;i<=b.contor;i++){
		cout<<b.elemente[i]<<" ";
	}
	cout<<"\n";
	cout<<"tija C: ";
	for(int i=1;i<=c.contor;i++){
		cout<<c.elemente[i]<<" ";
	}
	cout<<"\n";
}

void msd(tija& sursa, tija& destinatie){
	cout<<"inainte de mutare:\n";
	afiseazaTije();
	int dimensiunePiatra = sursa.elemente[sursa.contor];
	sursa.contor--;
	destinatie.contor++;
	destinatie.elemente[destinatie.contor]=dimensiunePiatra;
	cout<<"dupa mutare:\n";
	afiseazaTije();
	cout<<"\n\n";
}

void muta(int n, tija& sursa, tija& destinatie, tija& auxiliar){
	if(n==1){
		msd(sursa, destinatie);
	}
	else{
		muta(n-1, sursa, auxiliar, destinatie);
		msd(sursa, destinatie);
		muta(n-1, auxiliar, destinatie, sursa);
	}
}

int main(){
	a.contor=4;
	a.elemente[1]=4;
	a.elemente[2]=3;
	a.elemente[3]=2;
	a.elemente[4]=1;
	muta(4, a, b, c);
	return 0;
}