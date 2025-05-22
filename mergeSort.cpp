#include <iostream>
#include <cstdint>
#include <cstring>
using namespace std;


void merge(int* v1, int* v2, int* dest, int l1, int l2){
	int i1=0, i2=0, k=0;
	while(i1<l1&&i2<l2){
		if(v1[i1]<=v2[i2]){
			dest[k++]=v1[i1++];
		}
		else{
			dest[k++]=v2[i2++];
		}
	}
	while(i1<l1){
		dest[k++]=v1[i1++];
	}
	while(i2<l2){
		dest[k++]=v2[i2++];
	}
}

int aux[100];

void mergeSort(int* v, int start, int stop){
	if(start==stop){
		return;
	}
	int m=start+(stop-start)/2;
	mergeSort(v, start, m);
	mergeSort(v, m+1, stop);
	merge(v+start, v+m+1, aux, m-start+1, stop-m);
	// cout<<start<<" "<<stop<<":";
	// for(int i=start;i<=stop;i++){
	// 	cout<<v[i]<<" ";
	// }
	// cout<<"\n";
	memcpy(v+start, aux, (stop-start+1)*sizeof(int));
	// for(int i=start;i<=stop;i++){
	// 	cout<<v[i]<<" ";
	// }
	// cout<<"\n";
	// for(int i=0, j=start;j<=stop;i++,j++){
	// 	cout<<aux[i]<<" ";
	// }
	// cout<<"\n";
}

int main(){
	int v[10]={3,5,7,6,2,8,10,9,1,4};
	mergeSort(v, 0, 9);
	for(int i=0;i<10;i++){
		std::cout<<v[i]<<" ";
	}
	std::cout<<"\n";
	return 0;
}