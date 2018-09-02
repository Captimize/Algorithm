#include <iostream>
#include <string>
#define MAX 1003003
using namespace std;
int N;
bool prime[MAX];
inline bool isPalidrome(int t) {
	string c = to_string(t);
	int c_size = c.size();
	for (int i = 0; i < c_size / 2  ; i++) {
		if (c[i] != c[c_size - 1 - i]) return false;
	}
	return true;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	prime[0] = 1; prime[1] = 1;
	for (int i = 2; i <= MAX; i++) {
		if (!prime[i]) {
			for (int j = i + i; j <= MAX; j += i) {
				prime[j] = true;
			}
		}
	}
	cin >> N;
	for (int j = N; j <= MAX; j++) {
		if (!prime[j]) {
		
			if (isPalidrome(j)) {
				cout << j << "\n"; return 0;
			}
		}
	}
	//if prime[i] is a false, that is a prime number
}