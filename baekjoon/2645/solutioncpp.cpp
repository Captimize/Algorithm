#include <iostream>
#include <vector>
#include <queue>
#define MAX 51
#define INF 987654321
using namespace std;
struct Node {
	int row, col;
};
bool map[MAX][MAX];
int D[MAX][MAX];
int start_row, start_col, end_row, end_col;
int N,K,M;
int minValue;
vector<Node> ans1;
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
void print() {
	cout << "-----------------------------" << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j]) {
				cout << "■";
			}
			else {
				cout << "□";
			}
		}
		cout << "\n";
	}
}

inline int min(int a, int b) {
	return a > b ? b : a;
}
inline bool range(int r, int c) {
	if (r < 1 || c < 1 || r > N || c > N) return true;
	return false;
}
void DFS(int row, int col, int res, vector<Node> v) {
	if (minValue < res) return;
	if (row == end_row && col == end_col) {
		if (res < minValue) {
			minValue = res;
			int vSize = v.size();
			ans1.clear();
			for (int i = 0; i < vSize; i++) {
				int a = v[i].row;
				int b = v[i].col;
				ans1.push_back({a,b});
			}
		}
		return;
	}
	D[row][col] = res;
	v.push_back({ row,col });
	for (int j = 0; j < 4; j++) {
		int nextRow = row + dRow[j];
		int nextCol = col + dCol[j];

		if (range(nextRow, nextCol)) continue;
		if (map[nextRow][nextCol] == 1) {
			if (D[nextRow][nextCol] > D[row][col] + K) {
				DFS(nextRow, nextCol, D[row][col] + K, v);
			}
		}
		else {
			if (D[nextRow][nextCol] > D[row][col] + 1) {
				DFS(nextRow, nextCol, D[row][col] + 1, v);
			}
		}

	}
}
void make_circuit(int a1, int b1, int a2, int b2) {
	if (a1 == a2) {
		//같은 row
		if (b1 > b2) {
			//만약 시작점이 도착점 보다 크다면, 왼쪽으로 회로를 그리자.
			while (b1 >= b2) {
				map[a1][b1] = 1;
				b1--;
			}
		
		}
		else {
			//만약 시작점이 도착점 보다 작다면, 오른쪽으로
			while (b1 <= b2) {
				map[a1][b1] = 1;
				b1++;
			}
		}
	}
	else {
		//다른 row
		if (a1 > a2) {
			//시작점이 도착점보다 아래면, 
			while (a1 >= a2) {
				map[a1][b1] = 1;
				a1--;
			}
		}
		else {
			while (a1 <= a2) {
				map[a1][b1] = 1;
				a1++;
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cin >> start_row >> start_col >> end_row >> end_col;
	cin >> K >> M;
	minValue = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			D[i][j] = INF;
		}
	}
	D[start_row][start_col] = 0;
	for (int i = 0; i < M; i++) {
		int n; cin >> n;
		int a1, b1, a2, b2;
		for (int j = 0; j < n-1; j++) {
			if (j == 0) {
				cin >> a1 >> b1 >> a2 >> b2;
				make_circuit(a1, b1, a2, b2);
				a1 = a2;
				b1 = b2;
			}
			else {
				cin >> a2 >> b2;
				make_circuit(a1, b1, a2, b2);
				a1 = a2;
				b1 = b2;
			}
		}
	}
	vector<Node> v;
	DFS(start_row, start_col, 1,v);
	bool tmp_map[MAX][MAX] = {false,};
	int aa = ans1.size();
	for (int i = 0; i < aa; i++) {
		tmp_map[ans1[i].row][ans1[i].col] = 1;
	}
	tmp_map[end_row][end_col] = 1;
	queue<Node> q;
	q.push({ start_row, start_col });
	int direction;
	for (int j = 0; j < 4; j++) {
		int nextRow = start_row + dRow[j];
		int nextCol = start_col + dCol[j];

		if (range(nextRow, nextCol)) continue;
		if (tmp_map[nextRow][nextCol]) {
			direction = j;
			break;
		}
	}
	while (1) {
		if (start_row == end_row && start_col == end_col) break;

		for (int j = 0; j < 4; j++) {
			int nextRow = start_row + dRow[j];
			int nextCol = start_col + dCol[j];

			if (range(nextRow, nextCol)) continue;
			if (D[nextRow][nextCol] < D[start_row][start_col]) continue;
			if (tmp_map[nextRow][nextCol]) {
				if (direction != j) {
					direction = j;
					q.push({ start_row, start_col });
				}
				start_row = nextRow;
				start_col = nextCol;
				break;
			}
		}

	}
	q.push({ end_row, end_col });
	cout << minValue << "\n";
	cout << q.size() << " ";
	while (!q.empty()) {
		Node u = q.front(); q.pop();
		cout << u.row << " " << u.col << " ";
	}
	cout << "\n";
}