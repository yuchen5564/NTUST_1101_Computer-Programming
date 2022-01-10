#include <iostream>
using namespace std;

void Towers(int n, char a, char b, char c) {	//(n,a,b,c)=(層數,起點柱,其他柱,終點柱)
	if (n == 1) {
		cout << "Move disk " << n << " from" << a << " to " << c << endl;
	} 
	else {
		Towers(n - 1, a, c, b);
		//Towers(n, a, b, c);
		cout << "Move disk " << n << " from" << a << " to " << c << endl;
		Towers(n - 1, b, a, c);


	}
}/*
void Towers(int n, char A, char B, char C) {
	if (n == 1) {
		printf("Move sheet %d from %c to %c\n",n, A, C);
	}
	else {
		Towers(n - 1, A, C, B);
		Towers(1, A, B, C);
		Towers(n - 1, B, A, C);
	}
}*/

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	Towers(n, 'A', 'B', 'C');
	cout << endl;


}