
struct nod{
	nod *prev, *next;
	int val;
};

nod* front, *back;

int getLast(){
	if(back!=NULL){
		return back->val;
	}
	return -1; //eroare, lista goala
}

int getFirst(){
	if(front!=NULL){
		return back->val;
	}
	return -1; //eroare, lista goala
}

int getLastAndDelete(){
	if(back!=NULL){
		int ret=back->val;
		if(back->prev==NULL){ //lista cu un singur element
			int ret=back->val;
			delete(back);
			front=NULL;
			back=NULL;
			return ret;
		}
		back=back->prev;
		delete(back->next);
		return ret;
	}
	return -1; //eroare, lista goala
}

int getFrontAndDelete(){
	if(front!=NULL){
		int ret=front->val;
		if(front->next==NULL){ //lista cu un singur element
			int ret=back->val; //pot scrie asta pe o lista de un singur element, unde front si back coincid
			delete(back);
			front=NULL;
			back=NULL;
			return ret;
		}
		front=front->next;
		delete(front->prev);
		return ret;
	}
	return -1; //eroare, lista goala
}

void addFront(int val){
	nod *n=malloc(sizeof(nod));
	n->val=val;
	n->next=front;
	n->prev=NULL;
	if(front==NULL){
		back=n;
	}
	else{
		front->prev=n;
	}
	front=n;
}

void addBack(int val){
	nod *n=malloc(sizeof(nod));
	n->val=val;
	n->next=NULL;
	n->prev=back;
	if(back==NULL){
		front=n;
	}
	else{
		back->next=n;
	}
	back=n;
}