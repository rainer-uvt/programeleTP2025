#include<iostream>
#include<fstream>
using namespace std;

int v[100010];
int dp[100010];
int prevPoz[100010];

pair<int,int> lis(int n, int* a){
	dp[0]=1;
	prevPoz[0]=-1;
	int retVal=1, lastPoz=0;
	for(int i=1;i<n;i++){
		int m=0, p=-1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				if(dp[j]>m){
					m=dp[j];
					p=j;
				}
			}
		}
		m++;
		dp[i]=m;
		prevPoz[i]=p;
		if(m>retVal){
			retVal=m;
			lastPoz=i;
		}
	}
	return {retVal,lastPoz};
}

void show(int p, ofstream& fout){
	if(prevPoz[p]!=-1){
		show(prevPoz[p], fout);
	}
	fout<<v[p]<<" ";
}

int main(){
	ifstream fin("scmax.in");
	ofstream fout("scmax.out");
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>v[i];
	}
	pair<int,int> p=lis(n,v);
	fout<<p.first<<"\n";
	show(p.second, fout);
	// fout<<"\b\n";
	fin.close();
	fout.close();
}