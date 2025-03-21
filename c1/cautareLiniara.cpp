#include<iostream>

using namespace std;

//Se da un vector prin numarul de elemente si elementele acestuia
//Se citeste un nr x si se cere sa aflam daca se gaseste in vector
//complexitate de timp O(n)

int main(){
	int a[1000], n, x;
	printf("Dati numarul de elemente");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);//scanf("%d",a+i);
	}
	printf("Introduceti elementul cautat");
	scanf("%d",&x);
	for(int i=0;i<n;i++){
		if(a[i]==x){
			printf("Elementul cautat se gaseste pe pozitia %d",i);
			return 0;
		}
	}
	printf("Elementul cautat NU se gaseste in vector");
	return 0;
}