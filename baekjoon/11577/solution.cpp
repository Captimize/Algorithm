#include <iostream>
#define MAX 100001
using namespace std;
int N, K;
int D[MAX];
int B[MAX];
inline bool check() {
	for (int i = N-1; i >= 0; i--) {
		if (D[i]) return false;
	}
	return true;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			B[0] = D[0] ^ 0;
		}
		else {
			B[i] = D[i] ^ D[i - 1];
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (B[i]) {
			if (i + K <= N) {
				res++;
				B[i] ^= 1;
				B[i + K] ^= 1;
			}
		}
	}
	D[0] = B[0];
	for (int i = 1; i < N; i++) {
		D[i] = B[i] ^ D[i - 1];
	}
	if (check()) {
		cout << res << "\n";
	}
	else cout << "Insomnia" << "\n";
}