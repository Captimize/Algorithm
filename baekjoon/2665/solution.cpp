#include <iostream>
#include <queue>
#include <string.h>
#define MAX 51
#define INF 987654321
using namespace std;
struct Node {
	int row, col;
};
queue<Node> q;
char map[MAX][MAX];
int D[MAX][MAX];
int N;
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c > N - 1) return true;
	return false;
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			D[i][j] = INF;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i];
	init();
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
				if (map[nextRow][nextCol] == '0') {
					if (D[nextRow][nextCol] > D[u.row][u.col] + 1) {
						D[nextRow][nextCol] = D[u.row][u.col] + 1;
						q.push({ nextRow, nextCol });
 					}
				}
				else {//벽이 없는 공간이냐?
					if (D[nextRow][nextCol] > D[u.row][u.col] ) {
						D[nextRow][nextCol] = D[u.row][u.col] ;
						q.push({ nextRow, nextCol });
					}
				}
			}
		}
	}
	cout << D[N - 1][N - 1];
}