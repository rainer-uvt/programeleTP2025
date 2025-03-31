#include<stdio.h>

int main(){
	int a=2,b=3;
	printf("%u %u\n",&a, &b);
	printf("%p %p\n",&a, &b);
	printf("%x %x\n",&a, &b);
	int *p=&a;
	void* p1=&a;
	printf("%u %p %x\n",p,p,p);
	printf("%d\n", *p);
	p++;
	p1++;
	printf("%u %p %x\n",p,p,p);
	printf("%d\n",*p);
	printf("%u %p %x\n",p1,p1,p1);
	printf("%d\n",*((int*)p1));
	int c=50331648;
	printf("%x\n", c);
	void* h=main;
	printf("%p\n",h);
	return 0;
}