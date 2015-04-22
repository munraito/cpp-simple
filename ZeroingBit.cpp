#include <iostream>
#include <string>
using namespace std;

string getBinaryForm(int num){ //этой функцией получаем двоичную форму записи числа
	if (num == 0) return to_string(0); //для случая когда вводится ноль
	string tmp;
	while (num){ //пока число не обнулится, добавляем в строку остатки от деления на 2
		tmp = to_string(num % 2) + tmp;
		num /= 2;
	}
	return tmp;
}
int resetBit(int number, short n) { //этой функцией зануляем произвольный бит. Число - number, бит который надо занулить - n
	int mask = 1 << n; //сдвиг одного бита на n позиций влево
	mask = ~mask; // создаем маску, в которой установлены все биты, кроме n
	number = number & mask; //побитовым И применяем маску к числу, на выходе получаем число с зануленным n
	return number;
}

int main(int argc, char **argv){
	setlocale(LC_ALL, "Russian");
	if (argc < 3) {
		cout << "Введено недостаточно аргументов (" << argc - 1 << ")." << endl;
		return 0;
	}
	unsigned int number = atoi(argv[1]);
	unsigned short n = atoi(argv[2]);
	cout << "Число " << number << ", в двоичной форме: " << getBinaryForm(number) << endl;

	cout << "Зануляем " << n << "-й бит" << endl;
	number = resetBit(number, n);

	cout << "Результат: " << number << ", в двоичной форме: " << getBinaryForm(number) << endl;
	cout << endl;
	return 0;
}
