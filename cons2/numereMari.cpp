#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;


string add(string& s1, string& s2){
	int l1=s1.length(), l2=s2.length(),l;
	l=max(l1,l2);
	vector<char> v1(l,'0'), v2(l,'0'), v3(l+1);
	int i1=0, i2=0;


	for(char c:s1){
		v1[l1-1-i1]=c;
		i1++;
	}
	for(char c:s2){
		v2[l2-1-i2]=c;
		i2++;
	}

	int carry=0;
	for(int i=0;i<l;i++){
		int x=(v1[i]-'0')+(v2[i]-'0')+carry;
		if(x>9){
			carry=1;
			x-=10;
		}
		else{
			carry=0;
		}
		v3[i]='0'+x;
	}

	if(carry){
		v3[l]='1';
		reverse(v3.begin(),v3.end());
		return string(v3.begin(),v3.end());
	}

	reverse(v3.begin(),v3.end()-1);
	return string(v3.begin(),v3.end()-1);
}

string mult(string& s1, string& s2){
	int l1=s1.length(), l2=s2.length(),l;
	l=max(l1,l2);
	vector<char> v1(l), v2(l), v3(l1*l2+1,'0');
	int i1=0, i2=0;


	for(char c:s1){
		v1[l1-1-i1]=c;
		i1++;
	}
	for(char c:s2){
		v2[l2-1-i2]=c;
		i2++;
	}


	int lp=0;

	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			int x=(v1[i]-'0')*(v2[j]-'0')+(v3[i+j]-'0');
			int carry=x/10;
			x%=10;
			v3[i+j]='0'+x;
			lp=max(lp,i+j);
			int k=i+j+1;
			while(carry){
				lp=max(lp,k);
				carry+=v3[k]-'0';
				v3[k]='0'+(carry%10);
				carry/=10;
				k++;
			}
		}
	}
	lp++;
	reverse(v3.begin(),v3.begin()+lp);
	return string(v3.begin(),v3.begin()+lp);

}


int main(){

	string s1, s2;
	cin>>s1;
	cin>>s2;
	cout<<add(s1,s2)<<"\n";
	cout<<mult(s1,s2);


	return 0;
}