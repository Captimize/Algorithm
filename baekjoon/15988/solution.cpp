#include <iostream>
#define MAX 1000001
#define ll unsigned long long
#define MODULER 1000000009
using namespace std;
ll number[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	number[0] = 1;
	number[1] = 1;
	number[2] = 2;
	number[3] = 4;

	for (register int i = 4; i <= 1000000; i++) {
		number[i] = (number[i - 2] + number[i - 1] + number[i-3]) % MODULER;
	}
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		cout << number[N] << "\n";
	}
}