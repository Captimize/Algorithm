#include <iostream>
#include <queue>
#define MAX 101
#define INF 987654321
using namespace std;
struct Node {
	int row, col;
};
int N, M;
bool map[MAX][MAX];
int D[MAX][MAX];
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
queue<Node> q;
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c >M - 1) return true;
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		char t[MAX];
		cin >> t;
		for (int j = 0; j < M; j++) {
			if (t[j] == '1') {
				map[i][j] = 1;
			}
			D[i][j] = INF;
		}
	}

	q.push({ 0,0 });
	D[0][0] = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			Node u = q.front(); q.pop();

			for (int j = 0; j < 4; j++) {
				int nextRow = u.row + dRow[j];
				int nextCol = u.col + dCol[j];

				if (range(nextRow, nextCol)) continue;
				if (map[nextRow][nextCol] == 1) {
					if (D[nextRow][nextCol] > D[u.row][u.col] + 1) {
						D[nextRow][nextCol] = D[u.row][u.col] + 1;
						q.push({ nextRow, nextCol });
					}
				}
				else {
					if (D[nextRow][nextCol] > D[u.row][u.col]) {
						D[nextRow][nextCol] = D[u.row][u.col];
						q.push({ nextRow, nextCol });
					}
				}
			}
		}
	}
	cout << D[N-1][M-1] << "\n";
}