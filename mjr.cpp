#include <iostream>
#include <bitset>
#include <string>

using namespace std;
static const unsigned BIT_LENGTH = 8;

string getMajorForm(string byte){
	string tripleByte;
	for (int i=0; i < 3; i++){
		tripleByte += byte + " ";
	}
	return tripleByte;
}

int main(){
	setlocale(LC_ALL, "Russian");
	string byte = "11";
	string tripleByte = getMajorForm(byte);
	cout << tripleByte <<endl;
	bitset<BIT_LENGTH> a[5];
	for (int i=0; i < byte.length(); i++){
		a[i] = atoi(byte.c_str());
	} 
	cout << byte << " в двоичной " << a << endl;

	cout << "В десятичной: " << a.to_ulong() << endl;

	return 0;
}
