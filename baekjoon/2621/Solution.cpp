#include <iostream>
#include <algorithm>
using namespace std;
char color[5];
int number[5];
inline bool linear() {
	for (int i = 1; i < 5; i++) {
		if (number[i] != number[i - 1] + 1)return false;
 	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++) {
		char a, int b;
		cin >> a >> b;
		color[i] = a;
		number[i] = b;
	}
	int ans = 0;
	sort(number, number + 5);
	if (color[0] == color[1] == color[2] == color[3] == color[4]) {
		//숫자가 연속적인가
		if (linear()) {
			cout << number[4] + 900 << "\n";
		}
		else {
			cout << number[4] + 600 << "\n";
		}
		return 0;
	}
	else {
		for (int i = 1; i < 5; i++) {

		}
	}
}