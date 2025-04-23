#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct element{
	bool isOperator; //1-operator, 0-not operator (value)
	int val; //number if isOperator==false; 1=add, 2=minus, 3=*, 4=/, 5=^, 6=(, 7=)
};

struct nod{
	nod *left, *right;
	element el;	
};


int myPow(int a, int b){
	int r=1;
	for(int i=1;i<=b;i++){
		r*=a;
	}
	return r;
}

int calc(nod* n){
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

int calcPoloneza(element a[], int n){
	stack<int> st;
	for(int i=0;i<n;i++){
		if(a[i].isOperator){
			int r=st.top();
			st.pop();
			int l=st.top();
			st.pop();
			switch(a[i].val){
			case 1: l+=r; break;
			case 2: l-=r; break;
			case 3: l*=r; break;
			case 4: l/=r; break;
			default: l=myPow(l,r);
			}
			st.push(l);
		}
		else{
			st.push(a[i].val);
		}
	}
	return st.top();
}

int calcPoloneza(vector<element>& v){
	stack<int> st;
	for(element& el:v){
		if(el.isOperator){
			int r=st.top();
			st.pop();
			int l=st.top();
			st.pop();
			switch(el.val){
			case 1: l+=r; break;
			case 2: l-=r; break;
			case 3: l*=r; break;
			case 4: l/=r; break;
			default: l=myPow(l,r);
			}
			st.push(l);
		}
		else{
			st.push(el.val);
		}
	}
	return st.top();
}


void arboreToPol(nod* n, element a[], int& poz){
	if(n->el.isOperator){
		arboreToPol(n->left, a, poz);
		arboreToPol(n->right, a, poz);
		a[poz++]=n->el;
	}
	else{
		a[poz++]=n->el;
	}
}

nod* polToArbore(element a[], int n){
	nod **noduri = (nod**) malloc(n*sizeof(nod*));
	for(int i=0;i<n;i++){
		noduri[i] = (nod*) malloc(sizeof(nod));
		noduri[i]->el=a[i];
		if(a[i].isOperator){
			noduri[i]->right=noduri[i-1];
			noduri[i-1]=NULL;
			for(int j=i-2;j>=0;j--){
				if(noduri[j]!=NULL){
					noduri[i]->left=noduri[j];
					noduri[j]=NULL;
					j=-1;
				}
			}
		}
	}
	return noduri[n-1];
}

nod* polToArboreUsingStack(vector<element>& v){
	stack<nod*> st;
	for(element e: v){
		nod* nn = (nod*) malloc(sizeof(nod));
		nn->el=e;
		if(!e.isOperator){
			nn->left=NULL;
			nn->right=NULL;
		}
		else{
			nn->right=st.top();
			st.pop();
			nn->left=st.top();
			st.pop();
		}
		st.push(nn);
	}
	return st.top();
}


int expresieToAtomi(string& s, element a[]){
	int x=0, n=0;
	for(char c:s){
		cout<<c<<" ";
		cout.flush();
		if(c=='+'){
			n++;
			a[n].isOperator=true;
			a[n].val=1;
			// n++;
		}
		else if(c=='-'){
			n++;
			a[n].isOperator=true;
			a[n].val=2;
			// n++;
		}
		else if(c=='*'){
			n++;
			a[n].isOperator=true;
			a[n].val=3;
			// n++;
		}
		else if(c=='/'){
			n++;
			a[n].isOperator=true;
			a[n].val=4;
			// n++;
		}
		else if(c=='^'){
			n++;
			a[n].isOperator=true;
			a[n].val=5;
			// n++;
		}
		else if(c=='('){
			if(n!=0){
				n++;
			}
			a[n].isOperator=true;
			a[n].val=6;
			// n++;
		}
		else if(c==')'){
			n++;
			a[n].isOperator=true;
			a[n].val=7;
			// n++;
		}
		else{
			if(a[n].isOperator==true){
				n++;
			}
			a[n].isOperator=false;
			a[n].val=10*a[n].val+(c-'0');
		}
	}
	cout<<"\n";
	return n+1;
}

void show(element el){
	if(el.isOperator){
		switch(el.val){
		case 1: cout<<"+"; break;
		case 2: cout<<"-"; break;
		case 3: cout<<"*"; break;
		case 4: cout<<"/"; break;
		case 5: cout<<"^"; break;
		case 6: cout<<"("; break;
		case 7: cout<<")"; break;
		}
	}
	else{
		cout<<el.val;
	}
	cout<<" ";
}

vector<element> expresieToPol(string& s){
	
	element *elemente = (element*) malloc(s.length()*sizeof(element));
	
	int n=expresieToAtomi(s,elemente);
	for(int i=0;i<n;i++){
		show(elemente[i]);
	}
	cout<<"\n";
	cout.flush();
	
	vector<element> formaPoloneza;
	stack<element> operatorStack;
	for(int i=0;i<n;i++){
		show(elemente[i]);
		cout.flush();
		if(elemente[i].isOperator==false){
			formaPoloneza.push_back(elemente[i]);
		}
		else if(elemente[i].val==6){//(
			operatorStack.push(elemente[i]);
		}
		else if(elemente[i].val==7){
			while(operatorStack.top().val!=6){
				formaPoloneza.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.pop();
		}
		else if(elemente[i].val<3){//operatorul curent este adunare sau scadere
			while((!operatorStack.empty())&&operatorStack.top().val<6){
				formaPoloneza.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(elemente[i]);
		}
		else if(elemente[i].val<5){ //opeatorul curent este inmultire sau impartire
			while(!operatorStack.empty()&&(operatorStack.top().val+1)/2==2){
				formaPoloneza.push_back(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(elemente[i]);
		}
		else{
			operatorStack.push(elemente[i]);
		}
	}

	while(!operatorStack.empty()){
		formaPoloneza.push_back(operatorStack.top());
		operatorStack.pop();
	}

	cout<<"\n";
	cout.flush();

	for(element el: formaPoloneza){
		show(el);
	}
	cout<<"\n";
	cout.flush();

	return formaPoloneza;
}


int main(){

	string s;
	getline(cin,s);
	vector<element> fp = expresieToPol(s);
	nod* radacinaArbore = polToArboreUsingStack(fp);
	cout<<calc(radacinaArbore)<<"\n";
	cout<<calcPoloneza(fp)<<"\n";

	return 0;
}