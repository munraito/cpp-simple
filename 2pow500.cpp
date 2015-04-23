#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
	const short N = 500;
	int buf = 0, res = 0;
	vector<int> compNumb;
	compNumb.push_back(2); //начинаем с того, что заносим 2 в первый элемент
	for (int i = 0; i < N - 1; i++) { //пробегаем по всему числу, по принципу - один элемент массива = один разряд
		for (int rank = 0; rank < compNumb.size(); rank++){ //каждую итерацию цикла заменяем все предыдущие разряды (аналогия - вычисление столбиком)
			res = compNumb[rank] * 2;
			compNumb[rank] = buf + res % 1000000000;
			if (res > 999999999) buf = res / 1000000000;
			else buf = 0;

			if (rank == compNumb.size() - 1 && res > 999999999) {
				compNumb.push_back(res / 1000000000);
				buf = 0;
				break;
			}
		}
	}
	for (int i = compNumb.size() - 1; i > -1; i--){
		cout << compNumb[i];
	}
	cout << endl;
	cout << "runtime= " << clock() / 1000.0 << endl;
	return 0;
}
