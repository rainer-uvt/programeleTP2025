#include<iostream>

using namespace std;

//Se da un vector prin numarul de elemente si elementele acestuia
//Se afiseaza vectorul sortat
//complexitate de timp medie=worst case = best case O(n*n)

int main(){
	int a[1000], n, x;
	printf("Dati numarul de elemente");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a[i]);//scanf("%d",a+i);
	}

	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		}
	}

	for(int i=0;i<n;i++){
		printf("%d ",a[i]);//scanf("%d",a+i);
	}
	printf("\n");
	return 0;
}