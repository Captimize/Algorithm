#include <iostream>
using namespace std;
int N;
int apple;
int ans;
bool map[5][5];
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r> 4 || c > 4) return true;
	return false;
}
void Dfs(int row, int col, int consume) {
	if (row == 4 && col == 4) {
		if (consume == apple) {
			ans++;
		}
		return;
	}

	for (int j = 0; j < 4; j++) {
		int nextRow = row + dRow[j];
		int nextCol = col + dCol[j];

		if (range(nextRow, nextCol)) continue;
		if (map[nextRow][nextCol]) continue;

		map[nextRow][nextCol] = 1;
		//print();
		Dfs(nextRow, nextCol, consume + 1);
		map[nextRow][nextCol] = 0;
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		map[a - 1][b - 1] = 1;
	}
	apple = 25 - N;
	map[0][0] = 1;

	Dfs(0, 0, 1);

	cout << ans;
}