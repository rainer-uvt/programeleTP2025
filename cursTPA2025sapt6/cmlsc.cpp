#include<iostream>
#include<string>

using namespace std;

int dp[1000][1000];

int cmlsc(string& s1, string& s2){
	int l1=s1.length(), l2=s2.length();
	for(int i=0;i<=l1;i++){
		dp[i][0]=0;
	}
	for(int i=1;i<=l2;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[l1][l2];
}

int levinshtein(string& s1, string& s2){
	int l1=s1.length(), l2=s2.length();
	for(int i=0;i<=l1;i++){
		dp[i][0]=i;
	}
	for(int i=1;i<=l2;i++){
		dp[0][i]=i;
	}
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]));
			}
		}
	}
	return dp[l1][l2];
}
int main(){
	string s1="lalalalala", s2="alalalal";
	cout<<cmlsc(s1,s2)<<"\n";
	cout<<levinshtein(s1,s2)<<"\n";
	return 0;
}