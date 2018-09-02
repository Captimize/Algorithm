#include <iostream>
using namespace std;
int science[4];
int society[2];
int maxValue;

inline int max(int a, int b) {
	return a > b ? a : b;
}
void Dfs(int cur, int m, int score) {
	if (cur > 4) return;
	if (m == 3) {
		maxValue = max(maxValue, score);
		return;
	}
	Dfs(cur + 1, m + 1, score + science[cur]);
	Dfs(cur + 1, m, score);
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 4; i++) cin >> science[i];
	for (int i = 0; i < 2; i++) cin >> society[i];

	Dfs(0, 0, 0);
	maxValue += max(society[0], society[1]);
	cout << maxValue << '\n';
}