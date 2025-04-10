#include<cstdio>
#include<iostream>


//ma astept ca daca f1.nivel==f2.nivel atunci &(f1.x)=&(f2.x)
//ma astept ca daca (&(f1.x)-&(f2.x)) sa fie un multiplu de (f1.nivel-f2.nivel)

using namespace std;

int fibo(int n, int callFrom, int nivel){
	if(n<2){
		return n;
	}
	int x=fibo(n-1,n,nivel+1)+fibo(n-2,n,nivel+1);
	cout<<n<<" "<<callFrom<<" "<<nivel<<" "<<&x<<" "<<&n<<"\n";
	return x;
}

int main(){
	int x=fibo(6,100,1);
	cout<<x<<" "<<&x<<"\n";
	return 0;
}
