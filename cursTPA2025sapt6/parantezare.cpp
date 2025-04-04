#include<iostream>
#include<fstream>

using namespace std;

long long dims[1000];
long long dp[1000][1000];

long long getC(int i){
	return dims[i+1];
}

long long getR(int i){
	return dims[i];
}

long long din(int n){
	for(int i=1;i<=n;i++){
		dp[i][i]=0LL;
		dp[i][i+1]=getR(i)*getC(i)*getC(i+1);
	}
	for(int lungimeInterval=3;lungimeInterval<=n;lungimeInterval++){
		int stopInterval=lungimeInterval;
		for(int startInterval=1;stopInterval<=n;startInterval++,stopInterval++){
			long long inm=getR(startInterval)*getC(stopInterval);
			dp[startInterval][stopInterval]=dp[startInterval+1][stopInterval]+inm*getC(startInterval);
			for(int k=startInterval+1;k<stopInterval;k++){
				long long x=dp[startInterval][k]+dp[k+1][stopInterval]+inm*getC(k);
				dp[startInterval][stopInterval]=min(dp[startInterval][stopInterval],x);
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=i;j<=n;j++){
	// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
	// 	}
	// }
	return dp[1][n];
}

int main(){
	ifstream fin("podm.in");
	ofstream fout("podm.out");
	int n;
	fin>>n;
	for(int i=1;i<=n+1;i++){
		fin>>dims[i];
	}
	// cout<<"gata\n";
	// cout.flush();
	fout<<din(n);
	fin.close();
	fout.close();
	return 0;
}