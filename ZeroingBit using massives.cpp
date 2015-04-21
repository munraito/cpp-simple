#include <iostream>
#include <math.h>

using namespace std;

int howMuchBits(int number){ //функция, которой находим длину числа в битах
	int i = 0, bit;
	for (i; number != 0; number /= 2, i++){
		bit = number % 2;
		cout << i << "-й бит: " << bit << endl;
	}
	return i;
}

int main(int argc, char **argv){
	setlocale(LC_ALL, "Russian"); 
	if (argc < 3) {
		cout << "Введено недостаточно аргументов (" << argc - 1 << ")." << endl;
		return 0;
	}
	int number = atoi(argv[1]), n = atoi(argv[2]), decimal = 0; 
	cout << "Число " << number << endl;
	int bitLength = howMuchBits(number);
	int* bitMassive = new int[bitLength];
	for (int i = 0; i < bitLength; number /= 2, i++){ //заносим в дин. массив bitMassive значения битов
		bitMassive[i] = number % 2;
	}
	if (n >= bitLength) {
		cout << "Введите номер бита от 0 до " << bitLength - 1 << endl;
		return 0;
	}
	cout << "Зануляем бит " << n << endl;
	bitMassive[n] = 0;
	cout << "Результат в двоичной форме: ";
	for (int i = 1; i <= bitLength; i++){ 
		cout << bitMassive[bitLength - i]; //просто выводим ранее полученный массив с зануленным элементом задом-наперед
		if (bitMassive[i] == 1) decimal += pow(2, i); //если бит установлен, то 
	}
	cout << endl <<"Результат в десятичной форме: " << decimal << endl;
	
	delete[] bitMassive;
	return 0;
}
