#include<iostream>
#include<stack>
#include<vector>

using namespace std;

template <class T>
struct myStack{
	T v[1000];
	int count=0;
};

template <class T>
struct myStack1{
	vector<T> v;
};

//scriu functia cu bool pentru a verifica daca pot adauga (am totusi o limita de 1000 de elemente)
template <class T>
bool push(T val, myStack<T> *s){
	if(s->count<1000){
		s->v[s->count]=val;
		s->count++;
		return true;
	}
	return false;
}

template <class T>
void push(T val, myStack1<T> *s){
	s->v.push_back(val);
}

//aici nu folosesc template, e independent de tipul stivei
template <class T>
bool empty(myStack<T> *s){
	return s->count==0;
}

template <class T>
bool empty(myStack1<T> *s){
	return s->v.empty();
}

template <class T>
bool pop(myStack<T> *s){
	if(s->count>0){
		s->count--;
		return true;
	}
	return false;
}

template <class T>
bool pop(myStack1<T> *s){
	if(!(s->v.empty())){
		s->v.pop_back();
		return true;
	}
	return false;
}

template <class T>
T top(myStack<T>* s){
	return s->v[s->count-1];
}

template <class T>
T top(myStack1<T>* s){
	return s->v[s->v.size()-1];
}



int main(){
	stack<int> STLStack;
	myStack<int> myStackImplementation;
	myStack1<int> anotherWayOfImplementation;

	STLStack.push(5);
	push(5,&myStackImplementation);
	push(5,&anotherWayOfImplementation);
	STLStack.push(1);
	push(1,&myStackImplementation);
	push(1,&anotherWayOfImplementation);
	STLStack.push(2);
	push(2,&myStackImplementation);
	push(2,&anotherWayOfImplementation);
	STLStack.push(4);
	push(4,&myStackImplementation);
	push(4,&anotherWayOfImplementation);

	while(!STLStack.empty()){
		cout<<STLStack.top()<<" ";
		STLStack.pop();
	}
	cout<<"\n";
	while(!empty(&myStackImplementation)){
		cout<<top(&myStackImplementation)<<" ";
		pop(&myStackImplementation);
	}
	cout<<"\n";
	while(!empty(&anotherWayOfImplementation)){
		cout<<top(&anotherWayOfImplementation)<<" ";
		pop(&anotherWayOfImplementation);
	}
	cout<<"\n";

	return 0;
}