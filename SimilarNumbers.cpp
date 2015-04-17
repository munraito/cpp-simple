#include <iostream>
using namespace std;

int getSimilar(int numb){ //функция нахождения одинаковых цифр в числе
	int count[10], allCount = 0, res;
	for (int i = 0; i < 10; i++) {
		count[i] = 0;
	}
	for (int i = 0; (numb != 0 && i < 10); numb /= 10, i++){ //здесь мы отделяем цифры от числа и считаем количество их вхождений
			res = numb % 10;
			if (count[res] < 2) {
				count[res]++;
				if (count[res] > 1) allCount++;
			}
	}
	return allCount;
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Russian");
	unsigned int n;
	if (argc < 2) {
		cout << "Введено недостаточно аргументов (" << argc - 1 << ")." << endl;
		return 0;
	}
	n = atoi(argv[1]);
	cout << "Число " << n << endl;
	if (n >= 0) {
		cout << "В числе повторяется " << getSimilar(n) << " одинаковых цифр(ы)" << endl;
	}
	else cout << "Некорректный ввод n" << endl;
	return 0;
}
