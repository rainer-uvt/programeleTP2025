#include<iostream>
#include<stack>

using namespace std;

// a se vedea https://en.wikipedia.org/wiki/McCarthy_91_function
//mai ales recurenta simpla de 2 variabile

int a[100];

int mp(int n){
	if(n>=12){
		return n-1;
	}
	if(a[n]>0){
		return a[n];
	}
	int x=mp(n+2);
	x=mp(x);
	a[n]=x;
	return x;
}

int mannaPnuelli(int n){
	if(n>=12){
		return n-1;
	}
	return mannaPnuelli(mannaPnuelli(n+2));
}

int mpStack(int x){
	stack<int> st;
	st.push(x);
	while(!st.empty()){
		int x=st.top();
		if(x<12){
			st.push(x+2);
		}
		else{
			st.pop();
			if(st.empty()){
				return x-1;
			}
			else{
				st.pop();
				st.push(x-1);
			}
		}
	}
	return -1;
}

int main(){
	for(int i=12;i<=20;i++){
		a[i]=i-1;
	}
	for(int i=0;i<12;i++){
		a[i]=mp(i);
	}
	for(int i=0;i<20;i++){
		// printf("%d %d %d\n",a[i],mannaPnuelli(i), mpStack(i));
		cout<<i<<" "<<a[i]<<" "<<mannaPnuelli(i)<<" "<<mpStack(i)<<"\n";
	}
	return 0;
}