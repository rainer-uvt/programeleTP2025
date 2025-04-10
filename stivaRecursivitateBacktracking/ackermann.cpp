#include<iostream>
#include<stack>

using namespace std;

// a se vedea https://en.wikipedia.org/wiki/McCarthy_91_function
//mai ales recurenta simpla de 2 variabile

int a[6][100000];

int ack(int x, int y){
	if(x==0){
		return y+1;
	}
	if(x<6&&y<100000&&a[x][y]!=0){
		return a[x][y];
	}
	if(y==0){
		int v=ack(x-1,1);
		a[x][y]=v;
		return v;
	}
	int v1=ack(x,y-1);
	int v2=ack(x-1,v1);
	int v3=ack(x-1, ack(x,y-1));
	if(v2!=v3){
		cout<<"\nrec:  "<<v2<<" "<<v3<<"\n";
	}
	a[x][y]=v2;
	return v2;
}

int ackStack(int x, int y){
	stack<pair<int,int>> st;
	st.push({x,y});
	while(!st.empty()){
		pair<int,int> p=st.top();
		if(p.first!=0&&p.second!=0){
			st.push({p.first,p.second-1});
		}
		else if(p.first==0){
			st.pop();
			if(st.empty()){
				return p.second+1;
			}
			else{
				pair<int,int> p1=st.top();
				st.pop();
				st.push({p1.first-1, p.second+1});
			}
		}
		else{
			st.pop();
			st.push({p.first-1,1});
		}
	}
	return 0;
}

int main(){
	for(int i=0;i<=3;i++){
		for(int j=0;j<=4;j++){
			cout<<ack(i,j)<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n";cout<<"\n";
	// cout<<ackStack(0,1);
	// return 0;
	for(int i=0;i<=3;i++){
		cout<<i<<":\n";
		for(int j=0;j<=4;j++){
			cout<<ack(i,j)<<" "<<ackStack(i,j)<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}