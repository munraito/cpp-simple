#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

static const unsigned BIT_LENGTH = 8;

int main(){
	setlocale(LC_ALL, "Russian");
	ifstream fin("input.txt", ios::binary); //входной файл
	ofstream fout("spoiled mjr.txt", ios::binary); //мажорированный и зашумленный результат


	if (!fin.is_open()){
		cout << "Файл не может быть открыт" << endl;
		return 0;
	}

	bitset<BIT_LENGTH> Copy1, Copy2, Copy3;

	fin.seekg(0, fin.end); //перемещаем указатель на конец файла 
	int size = fin.tellg(); //вычислили размер
	fin.seekg(0, fin.beg); //возвращаем в начало
	cout << "Размер файла: " << size << " байт"<< endl;

	char* bytes = new char[size];
	fin.read(bytes, size); //заполняем массив символами из файла 
	fin.close(); 

	for (int i = 0; i < size; i++) {
		Copy1 = bytes[i], Copy2 = bytes[i], Copy3 = bytes[i];
		Copy2.flip(4); Copy3.flip(2); Copy3.flip(7); Copy1.flip(0); Copy1.flip(6); //"испортили" некоторые биты данного набора
		cout << "Байт " << i << ": " << bytes[i] << endl;
		fout << static_cast<char>(Copy1.to_ulong()) << static_cast<char>(Copy2.to_ulong()) << static_cast<char>(Copy3.to_ulong()) << endl; //заполнили новый файл значениями 
	}
	//закрытие файлов и освобождение памяти
	fout.close();
	delete[] bytes;
	return 0;
}
