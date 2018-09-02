#include <iostream>
#define INF 987654321
#define MAX 11
using namespace std;
int N;
int map[MAX][MAX];
bool visit[MAX][MAX];
const int dRow[] = {0, -1, 0, 1, 0};
const int dCol[] = {0, 0, -1, 0, 1};
int minValue;
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline bool check(int row, int col) {
	for (int j = 0; j < 5; j++) {
		int nextRow = row + dRow[j];
		int nextCol = col + dCol[j];

		if (visit[nextRow][nextCol]) return false;
	}
	return true;
}
inline int injection(int row, int col) {
	int res = 0;
	for (int k = 0; k < 5; k++) {
		int nextRow = row + dRow[k];
		int nextCol = col + dCol[k];
		visit[nextRow][nextCol] = 1;
		res += map[nextRow][nextCol];
	}
	return res;
}
inline void rejection(int row, int col) {
	for (int k = 0; k < 5; k++) {
		int nextRow = row + dRow[k];
		int nextCol = col + dCol[k];
		visit[nextRow][nextCol] = 0;
	}
}
void Dfs(int cur, int res) {
	if (minValue <= res) return;
	if (cur == 3) {
		minValue = min(minValue, res);
		return;
	}

	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < N-1; j++) {
			if (check(i, j)) {
				int t= injection(i, j);
				Dfs(cur + 1, res+t);
				rejection(i, j);
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	minValue = INF;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	Dfs(0, 0);
	cout << minValue << "\n";
}