#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

static const unsigned BIT_LENGTH = 8;

int main(){
	setlocale(LC_ALL, "Russian");
	ifstream file("input.txt", ios::binary);
	ofstream fout("mjr.txt", ios::binary);
	bitset<BIT_LENGTH> Copy1, Copy2, Copy3;

	if (!file.is_open()){
		cout << "Файл не может быть открыт" << endl;
		return 0;
	}
	file.seekg(0, file.end); //перемещаем указатель на конец файла 
	int size = file.tellg(); //вычислили размер
	file.seekg(0, file.beg); //возвращаем в начало
	cout << "Размер файла: " << size << " байт\n";
	char* bytes = new char[size];
	file.read(bytes, size);
	for (int i = 0; i < size; i++)
	{
		Copy1 = bytes[i], Copy2 = bytes[i], Copy3 = bytes[i];
		cout << "Байт "<< i << ": "<< (int*)bytes[i]<<endl;
		cout << "Копии: " << Copy1 << " " << Copy2 << " " << Copy3 << endl;
		//fout << Copy1.to_string() << Copy2.to_string() << Copy3.to_string();
		//fout << bytes[i] << bytes[i] << bytes[i];
	}

	file.close();
	fout.close();
	delete[] bytes;
	return 0;
}
