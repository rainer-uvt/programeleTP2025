#include<iostream>
#include<stack>
using namespace std;

struct tija{
	string nume;
	stack<int> st;
	void adauga(int x){
		st.push(x);
	}
	int remove(){
		int x=st.top();
		st.pop();
		return x;
	}
};

void msd(tija& sursa, tija& destinatie){
	int x=sursa.remove();
	cout<<"mutam piatra de greutate "<<x<<" de pe tija "<<sursa.nume<<" pe tija "<<destinatie.nume<<"\n";
	destinatie.adauga(x);
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
	tija a,b,c;
	a.nume="A";
	b.nume="B";
	c.nume="C";
	a.adauga(4);
	a.adauga(3);
	a.adauga(2);
	a.adauga(1);
	muta(4,a,b,c);
	return 0;
}