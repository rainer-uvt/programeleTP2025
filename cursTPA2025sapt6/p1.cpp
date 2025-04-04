#include<iostream>
using namespace std;

int f(int i){
	return i*i;
}

int calc(int* v, int n){
	int s=0, retVal=0;
	for(int i=0;i<n;i++){
		s+=v[i];
		retVal+=f(i)*s;
	}
	return retVal;
}