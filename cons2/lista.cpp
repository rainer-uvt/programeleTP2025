#include<iostream>
#include<vector>
using namespace std;


struct nodSimply{
	int val;
	nodSimply *next;
};

nodSimply *head;

int getLastElementAndDeleteItsNodeFromGlobal(){
	nodSimply *temp=head;
	if(temp==NULL){
		return -1;
	}
	if(temp->next==NULL){
		int retVal=temp->val;
		head=NULL;
		free(temp);
		return retVal;
	}
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	int retVal=temp->next->val;
	free(temp->next);
	temp->next=NULL;
	return retVal;
}

int getLastElementAndDeleteItsNodeFromLocal(nodSimply **head){
	nodSimply *temp=*head;
	if(temp==NULL){
		return -1;
	}
	if(temp->next==NULL){
		int retVal=temp->val;
		*head=NULL;
		free(temp);
		return retVal;
	}
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	int retVal=temp->next->val;
	free(temp->next);
	temp->next=NULL;
	return retVal;
}

void addFirstFromGlobal(int x){
	nodSimply *newNode = (nodSimply*) malloc(sizeof(nodSimply));
	newNode->val=x;
	newNode->next=head;
	head=newNode;
}

void addFirstFromLocal(int x, nodSimply **localReceivedHead){
	nodSimply *newNode = (nodSimply*) malloc(sizeof(nodSimply));
	newNode->val=x;
	newNode->next=*localReceivedHead;
	*localReceivedHead=newNode;
}

nodSimply* deleteAllElementsWithGivenValue(int x, nodSimply* head){
	while(head!=NULL && head->val==x){
		nodSimply *nh = head;
		head=head->next;
		free(nh);
	}
	if(head==NULL){
		return head;
	}

	nodSimply* temp=head;
	while(temp->next!=NULL){
		if(temp->next->val==x){
			nodSimply *t = temp->next;
			temp->next=t->next;
			free(t);
		}
		else{
			temp=temp->next;
		}
	}
	return head;
}

nodSimply* deleteAllElementsWithGivenValue1(int x, nodSimply* head){
	nodSimply *temp=head;
	while(temp!=NULL&&temp->next!=NULL){
		if(temp->next->val==x){
			nodSimply* t=temp->next;
			temp->next=t->next;
			free(t);
		}
		else{
			temp=temp->next;
		}
	}
	if(head!=NULL){
		if(head->val!=x){
			return head;
		}
		else{
			temp=head->next;
			free(head);
			return temp;
		}
	}
	return NULL;
}

void deleteAllElementsWithGivenValue(int x, nodSimply** head){
	nodSimply *localHead=*head;
	while(localHead!=NULL && localHead->val==x){
		nodSimply *nh = localHead;
		localHead=localHead->next;
		free(nh);
	}
	if(localHead==NULL){
		return;
	}

	nodSimply* temp=localHead;
	while(temp->next!=NULL){
		if(temp->next->val==x){
			nodSimply *t = temp->next;
			temp->next=t->next;
			free(t);
		}
		else{
			temp=temp->next;
		}
	}
	*head=localHead;
}

struct nodDoubly{
	int x;
	nodDoubly *prev, *next;
};

void deleteFromDoublyWithLocalReference(nodDoubly** last, nodDoubly** head){
	nodDoubly *localLast=*last;
	if(*last==NULL){
		return;
	}
	if(*last==*head){
		free(*last);
		last=NULL;
		head=NULL;
	}
	nodDoubly* temp=localLast->prev;
	free(*last);
	*last=temp;
}



int main(){

	vector<int> v;
	v.push_back(5);
	cout<<v[0]<<"\n";;
	v.pop_back();
	cout<<v.size()<<"\n";;

	vector<int> vv(5);
	vv[0]=1;
	vv.push_back(6);
	for(int i:vv){
		cout<<i<<" ";
	}
	cout<<"\n";
	vv.pop_back();
	for(int i:vv){
		cout<<i<<" ";
	}
	cout<<"\n";
	cout<<vv.size();
	cout<<"\n";

	return 0;
}