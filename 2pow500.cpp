#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
	const short N = 500;
	short buf = 0, res = 0;
	vector<short> compNumb;
	compNumb.push_back(2);
	for (int i = 0; i < N - 1; i++) {
		for (int rank = 0; rank < compNumb.size(); rank++){
			res = compNumb[rank] * 2;
			compNumb[rank] = buf + res % 10;
			if (res > 9) buf = res / 10;
			else buf = 0;

			if (rank == compNumb.size() - 1 && res > 9) {
				compNumb.push_back(res / 10);
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
