#include<iostream>

using namespace std;

int a_count, b_count, c_count;
int a_tija[10], b_tija[10], c_tija[10];

void showTije() {
	cout << "A: ";
	for (int i = 1; i <= a_count; i++) {
		cout << a_tija[i] << " ";
	}
	cout << "\n";
	cout << "B: ";
	for (int i = 1; i <= b_count; i++) {
		cout << b_tija[i] << " ";
	}
	cout << "\n";
	cout << "C: ";
	for (int i = 1; i <= c_count; i++) {
		cout << c_tija[i] << " ";
	}
	cout << "\n";
}

void mst(char sursa, char destinatie) {
	cout << "inainte de mutare\n";
	showTije();
	int* sursa_count=&a_count, * destinatie_count=&a_count, * sursa_tija=a_tija, * destinatie_tija=a_tija;
	if (sursa == 'A') {
		sursa_count = &a_count;
		sursa_tija = a_tija;
	}
	else if (destinatie == 'A') {
		destinatie_count = &a_count;
		destinatie_tija = a_tija;
	}
	if (sursa == 'B') {
		sursa_count = &b_count;
		sursa_tija = b_tija;
	}
	else if (destinatie == 'B') {
		destinatie_count = &b_count;
		destinatie_tija = b_tija;
	}
	if (sursa == 'C') {
		sursa_count = &c_count;
		sursa_tija = c_tija;
	}
	else if (destinatie == 'C') {
		destinatie_count = &c_count;
		destinatie_tija = c_tija;
	}
	cout << "mutam elementul " << sursa_tija[*sursa_count] << " de pe tija " << sursa << " pe tija " << destinatie << "\n";
	*destinatie_count += 1;
	destinatie_tija[*destinatie_count] = sursa_tija[*sursa_count];
	*sursa_count -= 1;
	cout << "dupa mutare\n";
	showTije();
	cout << "\n\n\n";
}

void muta(int n, char sursa, char destinatie, char auxiliar) {
	if (n == 1) {
		mst(sursa, destinatie); return;
	}
	muta(n - 1, sursa, auxiliar, destinatie);
	mst(sursa, destinatie);
	muta(n - 1, auxiliar, destinatie, sursa);
}

int main() {
	a_count = 4;
	a_tija[1] = 4;
	a_tija[2] = 3;
	a_tija[3] = 2;
	a_tija[4] = 1;
	muta(4, 'A', 'B', 'C');
	return 0;
}