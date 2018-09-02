#include<iostream>
#define MAX 10001
#define ll unsigned long long
using namespace std;

int N;
int res;
ll D[MAX];
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	int idx = 2;
	D[1] = 1;
	D[2] = 2;
	
	for (register int i = 3; i <= 10000; i++) {
		D[i] = D[i - 2] + idx;
		if (i % 3 == 2) {
			idx++;
		}
	}
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		cout << D[N] << "\n";
	}
}
