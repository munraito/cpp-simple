#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	const short N = 10;
	short buf = 0, res = 0;
	vector<char> compNumb;
	compNumb.push_back(2); //начинаем с того, что заносим 2 в первый элемент
	for (int i = 0; i < N - 1; i++) { //пробегаем по всему числу, по принципу - один элемент массива = один разряд
		for (int rank = 0; rank < compNumb.size(); rank++){ //каждую итерацию цикла заменяем все предыдущие разряды (аналогия - вычисление столбиком)
			
			res = compNumb[rank] * 2; 
			compNumb[rank] = buf + res % 10; 
			if (res > 9) buf = res / 10;
			else buf = 0;

			if (rank == compNumb.size() - 1 && res > 9) { //этим условием переходим на следующий разряд числа
				compNumb.push_back(1);
				buf = 0;
				break;
			}
		}
	}
	//ofstream fout("result.txt");
	for (int i = compNumb.size() - 1; i > -1; i--){
		compNumb[i] += 48; //прибавляем ascii-код нуля, чтобы вывести все в цифрах
		cout << compNumb[i];
	}
	//fout.close();
	cout << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;
	cout << endl;
	return 0;
}
