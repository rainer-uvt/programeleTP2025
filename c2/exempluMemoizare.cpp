#include<iostream>

using namespace std;

//Se da un vector prin numarul de elemente si elementele acestuia (elemente POZITIVE de valoare cel mult 1000000)
//Se calculeaza XOR pe (left..right), avand memoizare
//exista si metode mai bune de a calcula (e.g. sirul sumelor XOR partiale)



int mem[1000][1000];

int calc(int* v, int start, int stop){
	if(mem[start][stop]!=-1){
		return mem[start][stop];
	}
	int x=0;
	for(int i=start; i<=stop;i++){
		x^=v[i];
	}
	mem[start][stop]=x;
	return x;
}

int main(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			mem[i][j]=-1;
		}
	}
	int a[1000], n, x, sa, so;
	printf("Dati numarul de elemente");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);//scanf("%d",a+i);
	}

	printf("Dati numarul de calcule pe care doriti sa-l efectuati");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Dati limitele calcului pe care doriti sa-l efectuati");
		scanf("%d %d", &sa, &so);
		printf("%d\n", calc(a,sa,so));
	}
	
	return 0;
}