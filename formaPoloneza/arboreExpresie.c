#include<stdio.h>

struct element{
	char isOperator; //1-operator, 0-not operator (value)
	int val; //number if isOperator==false; 1=add, 2=minus, 3=*, 4=/, 5=^
};

struct nod{
	struct nod *left, *right;
	struct element el;	
};


int myPow(int a, int b){
	int r=1;
	for(int i=1;i<=b;i++){
		r*=a;
	}
	return r;
}

int calc(struct nod* n){
	if(n->el.isOperator){
		int l=calc(n->left);
		int r=calc(n->right);
		switch(n->el.val){
		case 1: return l+r;
		case 2: return l-r;
		case 3: return l*r;
		case 4: return l/r;
		case 5: return myPow(l,r);
		}
	}
	return n->el.val;
}

int main(){
	return 0;
}