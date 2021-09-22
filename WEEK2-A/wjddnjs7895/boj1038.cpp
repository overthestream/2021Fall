#define _SRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	long long num = 0;
	int counting = 0;
	while (counting < N) {
		if (num > 9876543210) {
			num = -1;
			break;
		}
		num += 1;
		string str = to_string(num);
		int flag = 1;
		for (int i = 0; i < str.length() - 1; ++i) {
			if (str[i] <= str[i + 1]) {
				if (str[i] != '9') {
					str[i] += 1;
					for (int j = i + 1; j < str.length(); ++j)
						str[j] = '0';
					num = stoll(str);
					num -= 1;
				}
				flag = 0;
				break;
			}
		}
		if (flag) {
			counting += 1;
		}
	}
	printf("%lld\n", num);

}