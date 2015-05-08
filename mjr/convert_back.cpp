#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

static const unsigned BIT_LENGTH = 8;

int main(){
	setlocale(LC_ALL, "Russian");
	ifstream fin("spoiled mjr.txt", ios::binary); //входной файл
	ofstream fout("output.txt", ios::binary); //результат

	if (!fin.is_open()){
		cout << "Файл не может быть открыт" << endl;
		return 0;
	}
	bitset<BIT_LENGTH> Copy1, Copy2, Copy3, finalByte;

	fin.seekg(0, fin.end); //перемещаем указатель на конец файла 
	long size = fin.tellg(); //вычислили размер
	fin.seekg(0, fin.beg); //возвращаем в начало
	cout << "Размер файла: " << size << " байт" << endl;
	cout << "Нужный размер: " << size / 3 << " байт" << endl;

	char* bytes = new char[size];
	fin.read(bytes, size); //заполняем массив символами из файла 
	fin.close();

	for (int i = 0; i < size; i+=3) {
		Copy1 = bytes[i], Copy2 = bytes[i + 1], Copy3 = bytes[i + 2], finalByte.reset();
		for (int i = 0; i < BIT_LENGTH; i++){ //проверяем каждый бит в байте
			if ((Copy1.test(i) && Copy2.test(i)) || (Copy1.test(i) && Copy3.test(i)) || (Copy2.test(i) && Copy3.test(i))) finalByte.set(i);
		}
		fout << static_cast<char>(finalByte.to_ulong());
	}
	//закрытие файлов и освобождение памяти
	fout.close();
	delete[] bytes;
	return 0;
}

