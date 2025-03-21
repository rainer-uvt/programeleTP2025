#include<iostream>

using namespace std;

//Se da un vector prin numarul de elemente si elementele acestuia SORTATE CRESCATOR
//Se citeste un nr x si se cere sa aflam daca se gaseste in vector
//complexitate de timp O(log2(n))

int main(){
	int a[1000], n, x;
	printf("Dati numarul de elemente");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);//scanf("%d",a+i);
	}
	printf("Introduceti elementul cautat");
	scanf("%d",&x);
	int start=0, stop=n-1;
	while(start<=stop){
		int m=start+(stop-start)/2;
		if(a[m]==x){
			printf("Elementul cautat se gaseste pe pozitia %d",m);
			return 0;
		}
		if(a[m]>x){
			stop=m-1;
		}
		else{
			start=m+1;
		}
	}
	printf("Elementul cautat NU se gaseste in vector");
	return 0;
}