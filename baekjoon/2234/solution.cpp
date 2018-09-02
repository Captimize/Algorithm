#include <iostream>
#include <queue>
#include <vector>
#define MAX 55
#define MMAX 2500
using namespace std;
struct Node {
	int row, col;
};
int N, M;
int map[MAX][MAX];
int val[MMAX];
int visit[MAX][MAX];
const int dRow[] = {0,-1,0,1};
const int dCol[] = {-1,0,1,0};
int maxValue;
int integrated;
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c > M - 1) return true;
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int a1 = 0;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				a1++;
				queue<Node> q;
				visit[i][j] = a1;
				q.push({ i,j });
				int space = 0;
				while (!q.empty()) {
					Node u = q.front();  q.pop();
					space++;
					for (register int j = 0; j < 4; j++) {
						int nextRow = u.row + dRow[j];
						int nextCol = u.col + dCol[j];

						if (range(nextRow, nextCol)) continue;
						if (visit[nextRow][nextCol])continue;
						if ((1 << j) & map[u.row][u.col]) continue;;//벽이 있는 경우

						visit[nextRow][nextCol] = a1;
						q.push({ nextRow, nextCol });
					}
				}
				val[a1] = space;
				maxValue = max(maxValue, space);
			}
		}
	}
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < M; j++) {
			if (visit[i][j] != visit[i][j + 1]) {
				//방번호가다르다면

				integrated = max(val[visit[i][j]] + val[visit[i][j + 1]], integrated);
			}
			if (visit[i][j] != visit[i + 1][j]) {
				integrated = max(val[visit[i][j]] + val[visit[i + 1][j]], integrated);
			}
		}
	}

	cout << a1 << "\n" << maxValue << "\n" << integrated << "\n";
}