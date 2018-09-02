#include<iostream>
#include <string.h>
#include <queue>
#define MAX 101
#define INF 987654321
using namespace std;
struct Node {
	int row, col, minValue, maxValue;
};
struct compare {
	inline bool operator() (const Node &n1, const Node &n2) {
		if (n1.maxValue > n2.maxValue) return false;
		else if (n1.maxValue == n2.maxValue) {
			if (n1.minValue > n2.maxValue) return true;
			else return false;
		}
		else return true;
	}
};
int N;
int map[MAX][MAX];
bool visit[MAX][MAX][200];
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, -1, 0, 1};
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c> N - 1) return true;
	return false;
}
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline bool parametric(int t) {
	int minValue = min(map[0][0],map[N-1][N-1]);
	int maxValue = max(map[0][0],map[N-1][N-1]);
	memset(visit, false, sizeof(visit));
	visit[0][0][maxValue-minValue] = 1;
	priority_queue<Node, vector<Node>, compare> q;
	q.push({ 0,0,minValue, maxValue });
	while (!q.empty()) {
		Node u = q.top(); q.pop();
		if (u.row == N - 1 && u.col == N - 1) {
			//print();
			return true;
		}

		for (int j = 0; j < 4; j++) {
			int nextRow = u.row + dRow[j];
			int nextCol = u.col + dCol[j];

			if (range(nextRow, nextCol)) continue;
			
			int tminValue = min(u.minValue, map[nextRow][nextCol]);
			int tmaxValue = max(u.maxValue, map[nextRow][nextCol]);
			if (visit[nextRow][nextCol][tmaxValue- tminValue]) continue;
			if (tmaxValue - tminValue <= t) {
				visit[nextRow][nextCol][tmaxValue-tminValue] = 1;
				q.push({ nextRow, nextCol, tminValue, tmaxValue });
			}
		}
	}
	return false;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int s = 0, e = 200, m;
	int ans = INF;
	while (s <= e) {
		m = (s + e) / 2;
		if (parametric(m)) {
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	cout << e + 1 << "\n";
}