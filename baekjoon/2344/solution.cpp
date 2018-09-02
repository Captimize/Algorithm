#include <iostream>
#define MAX 1002
using namespace std;
int N, M;
int board[MAX][MAX];
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
inline bool range(int r, int c) {
	if (r < 1 || c < 1 || r > N  || c > M) return true;
	return false;
}
inline int getMirror(int row, int col, int direction) {
	if (board[row][col] > 0) {
		return board[row][col];
	}
	if (board[row][col]<0) {
		if (direction == 0) {
			direction = 3;
		}
		else if (direction == 1) {
			direction = 2;
		}
		else if (direction == 2) {
			direction = 1;
		}
		else {
			direction = 0;
		}
	}

	int nextRow = row + dRow[direction];
	int nextCol = col + dCol[direction];
	
	return getMirror(nextRow, nextCol, direction);
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (register int i = 1; i <= N; i++) {
		for (register int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				board[i][j] = -1;
			}
		}
	}

	int direction = 0;
	int idx = 1;
	int token = 1;
	while (idx <= N) {
		board[idx++][0] = token++;
	}
	idx = 1;
	while (idx <= M) {
		board[N+1][idx++] = token++;
	}
	idx = N;
	while (idx >= 1) {
		board[idx--][M+1] = token++;
	}
	idx = M;
	while (idx >= 1) {
		board[0][idx--] = token++;
	}

	idx = 1;
	while (idx <= N) {
		cout << getMirror(idx++, 1, 3) << " ";
	}
	idx = 1;
	while (idx <= M) {
		cout << getMirror(N, idx++, 0) << " ";
	}
	idx = N;
	while (idx >= 1) {
		cout << getMirror(idx--, M, 1) << " ";
	}
	idx = M;
	while (idx >= 1) {
		cout << getMirror(1, idx--, 2) << " ";
	}


}