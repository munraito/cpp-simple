#include <iostream>
using namespace std;

int getDigit(int n, int k) {
	int res;
	for (int i = 0; i < k; n /= 10, i++)
		res = n % 10;
	return res;
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Russian");
	int n, k;
	if (argc < 3) {
		cout << "Введено недостаточно аргументов (" << argc - 1 << ")." << endl;
		return 0;
	}
	n = atoi(argv[1]);
	k = atoi(argv[2]);
	if (k > 0) 
		cout << k <<" цифра числа "<< n <<": " << getDigit(n, k) << endl;
	else 
		cout << "Некорректный ввод K" << endl;
	return 0;
}
