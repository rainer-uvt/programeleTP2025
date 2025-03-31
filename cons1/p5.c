#include<stdio.h>

int f(int* f1(int*), int* a){
	return f1(a);
}

int f2(int* a){
	printf("%d\n", *a);
	return ((*a)+1);
}

void main(){
	int* func=f2;
	int a=3;
	printf("%d\n",f(func,&a));
}