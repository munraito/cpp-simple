#include <iostream>
#include <bitset>

using namespace std;
static const unsigned BIT_LENGTH = 32;


int main(){
	setlocale(LC_ALL, "Russian");
	int number, n;
	cin >> number;
	cout << number << endl;
	bitset<BIT_LENGTH> a = number;
	cout << number << " в двоичной " << a << endl;

	cout << "Какой бит занулить?" << endl;
	cin >> n;
	a.reset(n);

	cout << "Результат в двоичной: " << a << endl;
	cout << "В десятичной: " << a.to_ulong() << endl;

	return 0;
}
