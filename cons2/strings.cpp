#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

int main(){

	char s[]="abcdhbfds";
	char* s2=strchr(s,'h');
	printf("%s\n",s2);
	string s1="abcbfdskhrweiohnfdsklnfdsil";
	cout<<s1<<"\n";


	const char* s1p = s1.c_str();
	s1p=strchr(s1p,'o');
	cout<<*s1p<<"\n";
	printf("%s\n",s1p);

	return 0;
}