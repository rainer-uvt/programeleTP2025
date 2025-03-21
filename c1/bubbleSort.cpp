#include<iostream>

using namespace std;

//Se da un vector prin numarul de elemente si elementele acestuia
//Se afiseaza vectorul sortat
//complexitate de timp medie O(n*log2(n))
//complexitate de timp worst case O(n*n)
//complexitate de timp best case O(n)

int main(){
	int a[1000], n, x;
	printf("Dati numarul de elemente");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);//scanf("%d",a+i);
	}

	bool toDo=true;
	while(toDo){
		toDo=false;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				x=a[i];
				a[i]=a[i+1];
				a[i+1]=x;
				toDo=true;
			}
		}
	}

	for(int i=0;i<n;i++){
		printf("%d ",a[i]);//scanf("%d",a+i);
	}
	printf("\n");
	return 0;
}