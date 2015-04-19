#include <iostream>
using namespace std;

bool sumOfSquares(int numb){ //этой функцией узнаем, можно ли разложить число на сумму квадратов двух других
	for (int i = 1; i < numb; i++) {
		int i2 = i*i;
		for (int j = i; j < numb; j++) {
			if (i2 + j*j == numb) return true;
			}
		}
	return false;
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2) {
		cout << "Введено недостаточно аргументов (" << argc - 1 << ")." << endl;
		return 0;
	}
	int n = atoi(argv[1]);
	if (n > 0) {
		if (sumOfSquares(n)) cout << "Число " << n << " можно представить в виде суммы квадратов двух целых чисел" << endl;
		else cout << "Число " << n << " нельзя представить в виде суммы квадратов двух целых чисел" << endl;
	}
	else cout << "Введите положительное число" << endl;
	return 0;
}
