unsigned int inversareBitiPozitiiPareCuImpare(unsigned int x){
	unsigned int masca1=0, masca2=0;
	unsigned int m1=0x33, m2=0x66;
	for(int i=0;i<sizeof(int);i++){
		masca1=masca1<<8;
		masca2=masca2<<8;
		masca1&=m1;
		masca2&=m2;
	}
	unsigned int x1=m1&x, x2=m2&x;
	x1<<=1;x2>>=1;
	return (x1|x2);
}

int modulo2(int x){
	return (x&1);
}

int modulo4(int x){
	return (x&3);
}

int modulo8(int x){
	return (x&7);
}

void permisiuniUtilizatori(char* permisiuni, int n){ //4 permisiuni per utilizator, un char poate tine 2 utilizatori
	//fac o mica presupunere, aceea ca pentru un utilizator nou fac reset de toate permisiunile, ca sa nu fac un check pt nr impar de utilizatori
	//1-read, 2-write, 3-execute, 4-rename
	int k=(n+1)/2;
	for(int i=0;i<k;i++){
		permisiuni[i]|=0x2;
		permisiuni[i]^=0x40;
	}
}

unsigned int inversareNibble(unsigned int x){
	unsigned int ret=0;
	for(int i=0;i<sizeof(int);i++){
		masca1=(0xF)<<(8*i);
		masca2=(0xF0)<<(8*i);
		masca1&=x;
		masca2&=x;
		masca1<<=4;
		masca2>>=4;
		ret|=(masca1|masca2);
	}
	return ret;
}