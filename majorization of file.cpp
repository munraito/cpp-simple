#include <iostream>
#include <fstream>

using namespace std;

static const unsigned BIT_LENGTH = 8;

int main(){
	setlocale(LC_ALL, "Russian");
	ifstream fin("input.txt", ios::binary); 
	ofstream fout("mjr.txt", ios::binary);

	if (!fin.is_open()){
		cout << "Файл не может быть открыт" << endl;
		return 0;
	}
	fin.seekg(0, fin.end); //перемещаем указатель на конец файла 
	int size = fin.tellg(); //вычислили размер
	fin.seekg(0, fin.beg); //возвращаем в начало
	cout << "Размер файла: " << size << " байт\n";
	char* bytes = new char[size];
	fin.read(bytes, size);
	for (int i = 0; i < size; i++)
	{
		cout << "Байт " << i << ": " << (int*)bytes[i] << endl;
		fout << bytes[i] << bytes[i] << bytes[i];
	}

	fin.close();
	fout.close();
	delete[] bytes;
	return 0;
}
