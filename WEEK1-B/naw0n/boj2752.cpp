#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int array[3];
	int input;

	for (int i = 0; i < 3; i++) {
		cin >> input;
		array[i] = input;
	}
	
	sort(array, array + 3);
	for (int i = 0; i < 3; i++) {
		cout << array[i] << " ";
	}
}