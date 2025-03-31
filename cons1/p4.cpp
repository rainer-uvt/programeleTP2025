#include<iostream>

void func(int a, int b, int*c, int* v, int v1[], int& d){
	printf("%x %x %x %x %x %x %x\n",&a, &b, &c, c, v, v1, &d);
}

int main(){
	int a=2, b=3, v[5]={0,0,0,0,0};
	printf("%x %x %x\n",&a, &b, v);
	func(a,b,&a,v,v, a);
	return 0;
}