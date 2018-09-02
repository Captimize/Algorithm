#include <iostream>
#define MAX 1001
using namespace std;
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N; cin >> N;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int a, b, c; cin >> a >> b >> c;
			if (a < 0 && b < 0 && c < 0) continue;

			ans += max(a, max(b, c));
		}
		cout << ans << "\n";
	}
}