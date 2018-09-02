#include <iostream>
#include <queue>
#include <string>
#define MAX 101
using namespace std;
struct Node {
	int row, col; 
};
int N, M, K;
int p;
int D[MAX][MAX][81];
char map[MAX][MAX];
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
string input;
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c > M - 1) return true;
	return false;
}
inline int Dfs(int row, int col, int idx) {
	if (idx == input.size()-1) {
		return 1;
	}
	if (D[row][col][idx] != -1) return D[row][col][idx];

	if (D[row][col][idx] == -1) {
		D[row][col][idx] = 0;
		for (int j = 0; j < 4; j++) {
			for (int h = 1; h <= K; h++) {
				int nextRow = row + dRow[j] * h;
				int nextCol = col + dCol[j] * h;

				if (range(nextRow, nextCol)) continue;
				if (map[nextRow][nextCol] == input[idx + 1]) {
					D[row][col][idx] += Dfs(nextRow, nextCol, idx + 1);
				}
			}

		}
	}
	
	return D[row][col][idx];
}


int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> map[i];
	cin >> input;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < M; j++) {
			for (register int k = 0; k < input.length(); k++) {
				D[i][j][k] = -1;
			}
		}
	}
	int res = 0;
	for (register int i = 0; i < N; i++) {

		for (register int j = 0; j < M; j++) {
			if (map[i][j] == input[0]) {
				res += Dfs(i, j, 0);
			}
		}
	}
	cout << res << "\n";
}