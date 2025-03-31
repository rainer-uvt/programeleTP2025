#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int caz;
string inputFiles[2]={"day15.txt", "day15_test.txt"};
int inputLength[2]={800,15};

int get(string& s){
	int x=0;
	for(int i=10;i<s.length();i++){
		x=10*x+(s[i]-'0');
	}
	return x;
}

struct treeNode{
	int val;
	string s;
	treeNode *left, *right;
};

void add(treeNode* r, int val){
	if(val<r->val){
		if(r->left==NULL){
			r->left=(treeNode*) malloc(sizeof(treeNode));
			r->left->val=val;
			r->left->left=NULL;
			r->left->right=NULL;
		}
		else{
			add(r->left,val);
		}
	}
	else{
		if(r->right==NULL){
			r->right=(treeNode*) malloc(sizeof(treeNode));
			r->right->val=val;
			r->right->left=NULL;
			r->right->right=NULL;			
		}
		else{
			add(r->right,val);
		}
	}
}

void add(treeNode* r, int val, int currentDepth, vector<int>& vec, int& maxDepth, string& s){
	if(val<r->val){
		if(r->left==NULL){
			r->left=(treeNode*) malloc(sizeof(treeNode));
			r->left->val=val;
			//necessary only for part 2
			r->left->s=s;
			r->left->left=NULL;
			r->left->right=NULL;
			if(currentDepth==maxDepth){
				maxDepth++;
				vec.push_back(val);
			}
			else{
				vec[currentDepth+1]+=val;
			}
		}
		else{
			add(r->left,val,currentDepth+1,vec,maxDepth,s);
		}
	}
	else{
		if(r->right==NULL){
			r->right=(treeNode*) malloc(sizeof(treeNode));
			r->right->val=val;
			//necessary only for part 2
			r->right->s=s;
			r->right->left=NULL;
			r->right->right=NULL;
			if(currentDepth==maxDepth){
				maxDepth++;
				vec.push_back(val);
			}
			else{
				vec[currentDepth+1]+=val;
			}
		}
		else{
			add(r->right,val,currentDepth+1,vec,maxDepth,s);
		}
	}
}

void addAndShow(treeNode* r, int val){
	if(val==r->val){
		return;
	}
	cout<<r->s<<"-";
	if(val<r->val){
		if(r->left==NULL){
			r->left=(treeNode*) malloc(sizeof(treeNode));
			r->left->val=val;
			r->left->left=NULL;
			r->left->right=NULL;
		}
		else{
			addAndShow(r->left,val);
		}
	}
	else{
		if(r->right==NULL){
			r->right=(treeNode*) malloc(sizeof(treeNode));
			r->right->val=val;
			r->right->left=NULL;
			r->right->right=NULL;			
		}
		else{
			addAndShow(r->right,val);
		}
	}
}

void solveDay15(){
	cin>>caz;
	ifstream fin(inputFiles[caz]);
	string s;
	getline(fin,s);
	int val=get(s);
	//necessary only for part 2
	s=s.substr(0,7);
	treeNode *root = (treeNode*) malloc(sizeof(treeNode));
	vector<int> v;
	int maxDepth=1;
	v.push_back(0);
	v.push_back(val);
	root->val=val;
	//necessary only for part 2
	root->s=s;
	root->left=NULL;
	root->right=NULL;
	for(int i=1;i<inputLength[caz];i++){
		getline(fin,s);
		val=get(s);
		s=s.substr(0,7);
		add(root,val,1,v,maxDepth,s);
	}
	int maxSum=0;
	for(int i=1;i<=maxDepth;i++){
		maxSum=max(maxSum, v[i]);
	}
	cout<<maxSum<<" "<<maxDepth<<" "<<maxSum*maxDepth<<"\n";
	addAndShow(root,500000);
	cout<<"\n";
	string s1, s2;
	getline(fin,s1);
	getline(fin,s1);
	getline(fin,s2);
	int x1=get(s1), x2=get(s2);
	s1=s1.substr(0,7);
	s2=s2.substr(0,7);
	addAndShow(root,x1);
	cout<<"\n";
	addAndShow(root,x2);
}

int main(){
	solveDay15();
	return 0;
}