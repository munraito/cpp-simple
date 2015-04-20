#include <iostream>
#include <math.h>

using namespace std;


int main(){
	setlocale(LC_ALL, "Russian");
	int number, n, i = 0, decimal = 0;
	cin >> number;
	int* bitMassive = new int;
	
	for (i; number != 0; number /= 2, i++) {
		bitMassive[i] = number % 2;
		cout << i << "-й бит: " << bitMassive[i] << endl;
	} 
	cout << "Какой бит занулить?" << endl; cin >> n;
	bitMassive[n] = 0; 
	cout << "Результат в двоичной форме: ";
	for (int j = 0; j <= i; j++){
		cout << bitMassive[i-j];
		
		if (bitMassive[j] == 1) {
			decimal += pow(2, j);
		}
	}
	cout << endl;
	cout << "Результат в десятичной форме: " << decimal << endl;
	delete[] bitMassive;
	return 0;
}
