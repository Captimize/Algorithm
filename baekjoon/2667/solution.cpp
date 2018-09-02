#include <iostream>
#include <queue>
#define MAX 30
using namespace std;
int N;
char map[MAX][MAX];
bool visit[MAX][MAX];
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
struct compare {
	inline bool operator() (const int &n1, const int &n2) {
		return n1 > n2;
	}
};
struct Node {
	int row, col;
};
priority_queue<int, vector<int>, compare> pq;
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c > N - 1) return true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j] == '1') {
				int res = 0;
				queue<Node> q;
				q.push({ i,j });
				visit[i][j] = 1;
				while (!q.empty()) {
					Node u = q.front(); q.pop();
					res++;
					for (int k = 0; k < 4; k++) {
						int nextRow = u.row + dRow[k];
						int nextCol = u.col + dCol[k];

						if (range(nextRow, nextCol))continue;
						if (visit[nextRow][nextCol]) continue;
						if (map[nextRow][nextCol] == '1') {
							
							visit[nextRow][nextCol] = 1;
							q.push({ nextRow, nextCol });
						}
					}
				}
				pq.push(res);
			}
		}
	}
	
	cout << pq.size() << "\n";
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}