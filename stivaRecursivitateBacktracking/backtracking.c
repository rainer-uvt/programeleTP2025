#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void afisare(int* stiva, int n){
	for(int i=0;i<n;i++){
		printf("%d ",stiva[i]);
	}
	printf("\n");
}

void afisareTureSiDame(int* stiva, int n){
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			if(stiva[i]==j){
				printf("|");
			}
			else{
				printf("_");
			}
		}
		printf("\n");
	}
	printf("\n");printf("\n");
}

void permutari1(int* stiva, int n, int poz, void* fctAfisare(int*, int)){
	if(poz==n){
		fctAfisare(stiva,n);
		return;
	}
	for(int i=1;i<=n;i++){
		bool ok=true;
		for(int j=0;j<poz;j++){
			if(stiva[j]==i){
				ok=false;
				break;
			}
		}
		if(ok){
			stiva[poz]=i;
			permutari1(stiva,n,poz+1,fctAfisare);
		}
	}
}

void problemaDamelor(int* stiva, int n, int poz){
	if(n==poz){
		afisareTureSiDame(stiva, n);
		return;
	}
	for(int i=1;i<=n;i++){
		bool ok=true;
		for(int j=0;j<poz;j++){
			if(stiva[j]==i){
				ok=false; j=poz;
			}
			if(abs(i-stiva[j])==poz-j){
				ok=false; j=poz;
			}
		}
		if(ok){
			stiva[poz]=i;
			problemaDamelor(stiva, n, poz+1);
		}
	}
}

void permutari2(int* stiva, int n, int poz, bool* used, void* fctAfisare(int*, int)){
	if(poz==n){
		fctAfisare(stiva,n);
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==false){
			stiva[poz]=i;
			used[i]=true;
			permutari2(stiva,n,poz+1,used,fctAfisare);
			used[i]=false;
		}
	}
}

void aranjamente1(int* stiva, int n, int poz, int k){
	if(poz==k){
		afisare(stiva,k);
		return;
	}
	for(int i=1;i<=n;i++){
		bool ok=true;
		for(int j=0;j<poz;j++){
			if(stiva[j]==i){
				ok=false;
				break;
			}
		}
		if(ok){
			stiva[poz]=i;
			aranjamente1(stiva,n,poz+1,k);
		}
	}
}

void aranjamente2(int* stiva, int n, int poz, bool* used, int k){
	if(poz==k){
		afisare(stiva,k);
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==false){
			stiva[poz]=i;
			used[i]=true;
			aranjamente2(stiva,n,poz+1,used,k);
			used[i]=false;
		}
	}
}

void combinari(int* stiva, int n, int poz, int k){
	if(poz==k){
		afisare(stiva,k);
		return;
	}
	for(int i=(poz==0?1:stiva[poz-1]+1);i<=n;i++){//aici putem pune o conditie de oprire mai buna (i+k-1-poz<=n, daca am calculat corect)
		stiva[poz]=i;
		combinari(stiva,n,poz+1,k);
	}
}

void dame(int* stiva, int n, int poz){
	if(poz==n){
		afisareTureSiDame(stiva,n);
		return;
	}
	for(int i=1;i<=n;i++){
		bool ok=true;
		for(int j=0;j<poz;j++){
			if(stiva[j]==i || abs(poz-j)==abs(i-stiva[j])){
				ok=false;
				break;
			}
		}
		if(ok){
			stiva[poz]=i;
			dame(stiva,n,poz+1);
		}
	}
}

int main(){

	int stiva[10];
	bool used[11];
	void *af1=afisare, *af2=afisareTureSiDame;
	memset(used, 0, 10*sizeof(bool));


	problemaDamelor(stiva, 8, 0);
	return 0;

	//permutari de 5
	printf("perm1\n");
	permutari1(stiva, 5, 0, af1);
	printf("perm2\n");
	permutari2(stiva, 5, 0, used, af1);
	//aranjamente de 5 luate cate 3
	printf("aranj1\n");
	aranjamente1(stiva, 5, 0,3);
	printf("aranj2\n");
	aranjamente2(stiva, 5, 0, used,3);
	//combinari de 5 luate cate 3
	printf("comb\n");
	combinari(stiva, 5, 0,3);
	//problema turelor de 5
	printf("ture\n");
	permutari2(stiva, 5, 0, used, afisareTureSiDame);
	//problema damelor de 5
	printf("dame\n");
	dame(stiva, 5, 0);

	return 0;
}