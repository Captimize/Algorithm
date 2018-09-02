#include <iostream>
#include <string.h>
#define MAX 1001
#define INF 987654321
using namespace std;
int N;
int map[MAX][MAX];
int D[4][MAX][MAX];

const int dRow[] = {1, 0};
const int dCol[] = {0, 1};
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c>N - 1) return true;
	return false;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline int Dfs(int row, int col, int color) {
	if (D[color+1][row][col] != -1) return D[color+1][row][col];

	D[color+1][row][col] = 0;
	for (int i = 0; i < 2; i++) {
		int nextRow = row + dRow[i];
		int nextCol = col + dCol[i];

		if (range(nextRow, nextCol)) continue;
		if (map[nextRow][nextCol] == (color + 1) % 3) {
			D[color + 1][row][col] = max(D[color + 1][row][col], Dfs(nextRow, nextCol, (color + 1) % 3)+1);
		}
		else {
			D[color + 1][row][col] = max(D[color + 1][row][col], Dfs(nextRow, nextCol, color));
		}
	}

	return  D[color+1][row][col];
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	memset(D, -1, sizeof(D));
	
	if (map[0][0] == 0) {
		cout << Dfs(0, 0, 0) + 1;
	}
	else {
		cout << Dfs(0, 0, -1);
	}
	//print();
}