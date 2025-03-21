#include<iostream>

using namespace std;

//Se da un vector prin numarul de elemente si elementele acestuia SORTATE CRESCATOR
//Se citeste un nr x si se cere sa aflam daca se gaseste in vector
//complexitate de timp O(log2(n))

int find(int* v, int start, int stop, int x){
	if(start>stop){
		return -1;
	}
	int m=start+(stop-start)/2;
	if(v[m]==x){
		return m;
	}
	if(v[m]>x){
		return find(v,start,m-1,x);
	}
	return find(v,m+1,stop,x);
}

int main(){
	int a[1000], n, x;
	printf("Dati numarul de elemente");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);//scanf("%d",a+i);
	}
	printf("Introduceti elementul cautat");
	scanf("%d",&x);
	x=find(a,0, n-1);
	if(x>-1){
		printf("Elementul cautat se gaseste pe pozitia %d",x);
	}
	else{
		printf("Elementul cautat NU se gaseste in vector");
	}
	return 0;
}