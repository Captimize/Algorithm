#include <iostream>
#define MAX 21
using namespace std;
int N;
int D[MAX];
int A[MAX];
int maxValue;
inline int max(int a, int b) {
	return a > b ? a : b;
}
void Dfs(int cur, int res, int health) {
	if (health <= 0) return;
	if (cur > N - 1) {
		maxValue = max(maxValue, res);
		return;
	}
	Dfs(cur + 1, res + A[cur], health - D[cur]);
	Dfs(cur + 1, res, health);
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (register int i = 0; i < N; i++) cin >> D[i];
	for (register int i = 0; i < N; i++) cin >> A[i];

	Dfs(0, 0, 100);

	cout << maxValue;
}