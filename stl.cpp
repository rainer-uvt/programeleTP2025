#include<map>
#include<unordered_map>
#include<stack>
#include<vector>
#include<iostream>

using namespace std;


int main(){
	vector<int> v;
	v.push_back(5);
	v.push_back(7);
	cout<<v[0]<<" "<<v[1]<<"\n";
	cout.flush();
	v.pop_back();
	v[1]=3;
	cout<<v[0]<<" "<<v[1]<<"\n";

	vector<int> v1(300,5);
	cout.flush();

	stack<int> s;
	s.push(5);
	cout<<s.top()<<"\n";
	s.pop();


	map<int,int> ma;
	map<int,int>::iterator it;
	map<char,int> mc;
	map<char,int>::iterator itMC;
	unordered_map<int,int> maU;
	unordered_map<int,int>::iterator itU;

	int n,x;
	char y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>y;
		x=y-'0';
		it=ma.find(x);
		if(it==ma.end()){
			ma[x]=1;
		}
		else{
			it->second++;
		}
		itMC=mc.find(y);
		if(itMC==mc.end()){
			mc[y]=1;
		}
		else{
			itMC->second++;
		}
		itU=maU.find(x);
		if(itU==maU.end()){
			maU[x]=1;
		}
		else{
			itU->second++;
		}
		v.push_back(x);
	}

	for(it=ma.begin();it!=ma.end();it++){
		cout<<it->first<<" "<<it->second<<"\n";
		// int i = reinterpret_cast<int>(it);
		// cout<<i<<"\n";
		printf("%p\n",it);
	}
	cout<<"\n";
	for(itU=maU.begin();itU!=maU.end();itU++){
		cout<<itU->first<<" "<<itU->second<<"\n";
	}
	cout<<"\n";
	for(itMC=mc.begin();itMC!=mc.end();itMC++){
		cout<<itMC->first<<" "<<itMC->second<<"\n";
		// int i = reinterpret_cast<int>(itMC);
		// cout<<i<<"\n";
		printf("%p\n",itMC);
	}
	cout<<"\n";


	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
		printf("%p\n",it);
	}


	return 0;
}