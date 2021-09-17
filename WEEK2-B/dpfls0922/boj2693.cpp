//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[10];
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		for (int i = 0; i < 10; i++)
			cin >> a[i];
		sort(a, a + 10);
		cout << a[7] << "\n";
	}
	return 0;
}