int* ciur(int n){
	int* ret=(int*)malloc(n);
	bool* isPrime=(int*) malloc(n+1);

	ret[1]=2;
	ret[0]=1;
	int primeCandidate=3;
	for(;primeCandidate*primeCandidate<=n;primeCandidate+=2){
		if(isPrime[primeCandidate]==false){
			ret[0]++;
			ret[ret[0]]=primeCandidate;
			for(int j=primeCandidate*primeCandidate;j<=n;j+=(primeCandidate<<1)){
				isPrime[j]=true;
			}
		}
	}

	for(;primeCandidate<=n;primeCandidate+=2){
		if(!isPrime[primeCandidate]){
			ret[0]++;
			ret[ret[0]]=primeCandidate;
		}
	}

	return ret;
}