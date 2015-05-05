#include <iostream>
#include <bitset>
#include <string>

using namespace std;
static const unsigned BIT_LENGTH = 8;

int main(){
	setlocale(LC_ALL, "Russian");
	int byte = 0xFF;
	bitset<BIT_LENGTH> Copy1 = byte, Copy2 = byte, Copy3 = byte, finalByte;

	cout << "Переданный байт: " << (int *)byte << endl;
	cout << "Копии: " << Copy1 << " " << Copy2 << " " << Copy3 << endl;

	Copy2.flip(4); Copy3.flip(2); Copy3.flip(7); Copy1.flip(0); Copy1.flip(6);
	cout << "Копии битов с ошибками: " << Copy1 << " " << Copy2 << " " << Copy3 << endl;
	cout << "В шестнадцатеричной: " << (int *)Copy1.to_ulong() << " " << (int *)Copy2.to_ulong() << " " << (int *)Copy3.to_ulong() << endl;

	for (int i = 0; i < BIT_LENGTH; i++){
		if ((Copy1.test(i) && Copy2.test(i)) || (Copy1.test(i) && Copy3.test(i)) || (Copy2.test(i) && Copy3.test(i))) finalByte.set(i);
	}
	cout << "Изначальный набор битов: " << finalByte << endl;
	cout << "В шестнадцатеричной: " << (int *)finalByte.to_ulong() << endl;

	return 0;
}
