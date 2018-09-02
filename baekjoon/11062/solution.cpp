#include <iostream>
#define MAX 1001
#define INF 987654321
using namespace std;
int N;
int score[MAX];
int D[MAX][MAX][2];
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline int p(int l, int r, int turn) {
	if (l > r) return 0;
	if (D[l][r][turn] != 0) return D[l][r][turn];

	if (!turn) {
		D[l][r][turn] = -INF;
		D[l][r][turn] = max(D[l][r][turn], p(l + 1, r, 1) + score[l]);
		D[l][r][turn] = max(D[l][r][turn], p(l, r - 1, 1) + score[r]);
	}
	else {
		D[l][r][turn] = INF;
		D[l][r][turn] = min(D[l][r][turn], p(l + 1, r, 0));
		D[l][r][turn] = min(D[l][r][turn], p(l, r - 1, 0));
	}
	return D[l][r][turn];
}
int main(void) {
	ios_base::sync_with_stdio(0);  cin.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (register int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				D[i][j][0] = 0;
				D[i][j][1] = 0;
			}
		}
		for (int i = 0; i < N; i++) cin >> score[i];

		cout << p(0, N - 1, 0) << "\n";
	}
}