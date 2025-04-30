#include<cstdio>
#include<queue>

using namespace std;

int vecini[2][8]={{1,0,-1,0,-1,-1,1,1},{0,1,0,-1,-1,1,-1,1},};
int nrVecini=4;

bool inMatrice(int m, int n, int x, int y){
	return (x<m&&y<n&&x>=0&&y>=0);
}

void fill(int* a, int m, int n, int x, int y, int valueToFillWith){
	int* liniaXDinA = a+x*n;
	if(liniaXDinA[y]==valueToFillWith){
		return;
	}
	liniaXDinA[y]=valueToFillWith;
	for(int i=0;i<nrVecini;i++){
		int newx=x+vecini[0][i], newy=y+vecini[1][i];
		if(inMatrice(m,n,newx,newy)){
			fill(a,m,n,newx,newy,valueToFillWith);
		}
	}
}


void fillIterativ(int* a, int m, int n, int x, int y, int valueToFillWith){
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		if(inMatrice(m,n,p.first,p.second)&&a[p.first*n+p.second]!=valueToFillWith){
			a[p.first*n+p.second]=valueToFillWith;
			for(int i=0;i<nrVecini;i++){
				q.push({p.first+vecini[0][i], p.second+vecini[1][i]});
			}
		}
	}
}

int main(){
	return 0;
}