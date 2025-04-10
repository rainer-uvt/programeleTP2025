#include<stdio.h>

int sumaN(int n){
	if(n==1){
		return 1;
	}
	return n+sumaN(n-1);
}

int produsN(int n){
	if(n==1){
		return 1;
	}
	return n*produsN(n-1);
}

int sumaCifrelor(int n){
	if(n<10){
		return n;
	}
	return n%10+sumaCifrelor(n/10);
}

int mannaPnuelli(int n){
	if(n>=12){
		return n-1;
	}
	return mannaPnuelli(mannaPnuelli(n+2));
}

int cmmdc(int a, int b){
	if(b>a){
		return cmmdc(b,a);
	}
	int c=a%b;
	return c==0?b:cmmdc(b,c);
}

int cmmdc1(int a, int b){
	if(b>a){
		return cmmdc1(b,a);
	}
	int c=a-b;
	return c==0?b:cmmdc1(a-b,b);	
}

int fibo(int n){
	if(n<2){
		return n;
	}
	return fibo(n-2)+fibo(n-1);
}

int inversareCifre(int n, int& p10){
	if(n<10){
		p10=10;
		return n;
	}
	int r=inversareCifre(n/10, p10);
	r=p10*(n%10)+r;
	p10*=10;
	return r;
}

pair<int,int> inversareCifre(int n){
	if(n<10){
		return {n,10};
	}
	pair<int,int> r1=inversareCifre(n);
	return {n%10+r1.first, 10*r1.second};
}

void inversareCifre1(int n, int& r){
	int r1=0;
	inversareCifre1(n/10,r1);
	r=10*r+r1;
}

int main(){
	int a=sumaN(10);
	printf("%d\n",a);
	a=produsN(8);
	printf("%d\n",a);
	a=sumaCifrelor(123567);
	printf("%d\n",a);
	a=cmmdc(101,103);
	printf("%d\n",a);
	a=fibo(10);
	printf("%d\n",a);
	int r=0;
	a=inversareCifre(123567, r);
	printf("%d\n",a);
	r=0;
	a=inversareCifre(123567, r);
	printf("%d\n",a);
	return 0;
}