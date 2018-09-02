#include <iostream>
#include <queue>	
#define MAX 101
using namespace std;
bool map[MAX][MAX];
bool D[MAX][MAX][5];
int N, M;		
struct robot {
	int row, col, direction, cnt;
};
queue<robot> q;
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline bool range(int r, int c) {
	if (r < 1 || c < 1 || r >N || c > M) return true;
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	int a, b, c;
	cin >> a >> b >> c;
	q.push({ a,b,c,0 });
	D[a][b][c] = 1;
	cin >> a >> b >> c;

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			robot r = q.front(); q.pop();
			if (r.row == a && r.col == b && r.direction == c) {
				cout << r.cnt << "\n";
				return 0;
			}
			//change direction
			if (r.direction == 1) { //µ¿ÂÊ
				if (!D[r.row][r.col][2]) {
					D[r.row][r.col][2] = 1;
					q.push({ r.row, r.col, 2, r.cnt + 2 });
				}
				if (!D[r.row][r.col][3]) {
					D[r.row][r.col][3] = 1;
					q.push({ r.row, r.col, 3, r.cnt + 1 });
				}
				if (!D[r.row][r.col][4]) {
					D[r.row][r.col][4] = 1;
					q.push({ r.row, r.col, 4, r.cnt + 1 });
				}
			}
			else if (r.direction == 2) {//¼­
				if (!D[r.row][r.col][1]) {
					D[r.row][r.col][1] = 1;
					q.push({ r.row, r.col, 1, r.cnt + 2 });
				}
				if (!D[r.row][r.col][3]) {
					D[r.row][r.col][3] = 1;
					q.push({ r.row, r.col, 3, r.cnt + 1 });
				}
				if (!D[r.row][r.col][4]) {
					D[r.row][r.col][4] = 1;
					q.push({ r.row, r.col, 4, r.cnt + 1 });
				}
			}
			else if (r.direction == 3) {//³²
				if (!D[r.row][r.col][2]) {
					D[r.row][r.col][2] = 1;
					q.push({ r.row, r.col, 2, r.cnt + 1 });
				}
				if (!D[r.row][r.col][1]) {
					D[r.row][r.col][1] = 1;
					q.push({ r.row, r.col, 1, r.cnt + 1 });
				}
				if (!D[r.row][r.col][4]) {
					D[r.row][r.col][4] = 1;
					q.push({ r.row, r.col, 4, r.cnt + 2 });
				}
			}
			else if (r.direction == 4) { //ºÏ
				if (!D[r.row][r.col][2]) {
					D[r.row][r.col][2] = 1;
					q.push({ r.row, r.col, 2, r.cnt + 1 });
				}
				if (!D[r.row][r.col][3]) {
					D[r.row][r.col][3] = 1;
					q.push({ r.row, r.col, 3, r.cnt + 2 });
				}
				if (!D[r.row][r.col][1]) {
					D[r.row][r.col][1] = 1;
					q.push({ r.row, r.col, 1, r.cnt + 1 });
				}
			}

			for (int k = 1; k <= 3; k++) {
				int nextRow = r.row;
				int nextCol = r.col;
				if (r.direction == 1) nextCol += k;
				else if (r.direction == 2) nextCol -= k;
				else if (r.direction == 3) nextRow += k;
				else if (r.direction == 4) nextRow -= k;

				if (range(nextRow, nextCol)) break;
				if (map[nextRow][nextCol]) break;
				if (D[nextRow][nextCol][r.direction]) continue;

				D[nextRow][nextCol][r.direction] = 1;
				q.push({ nextRow, nextCol, r.direction , r.cnt + 1 });
			}
		}
	}

}