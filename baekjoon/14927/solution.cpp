#include <iostream>
#include <string.h>
#define INF 987654321
#define MAX 18
using namespace std;
int N;
bool map[MAX][MAX];
const int dRow[] = {0,-1,0,1,0};
const int dCol[] = {0,0,-1,0,1};
bool match[MAX];
bool flag;
int minValue;
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline bool check(bool mmap[][MAX]) {
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			if (mmap[i][j]) return false;
		}
	}
	return true;
}
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c > N - 1) return true;
	return false;
}
inline void go(bool mmap[][MAX], int res) {

	for (register int i = 1; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			if (mmap[i - 1][j] == 1) {
				//위에께 켜저잇으면 눌러야함
				res++;
				for (register int k = 0; k < 5; k++) {
					int nextRow = i + dRow[k];
					int nextCol = j + dCol[k];

					if (range(nextRow, nextCol)) continue;
					if (mmap[nextRow][nextCol] == 0) mmap[nextRow][nextCol] = 1;
					else mmap[nextRow][nextCol] = 0;
				}
				if (res >= minValue) return;
			}
		}
	}
	if (check(mmap)) {
		minValue = min(minValue, res);
		return;
	}
}
void Dfs(int idx) {
	if (idx == N) {
		bool tmp[MAX][MAX];
		memcpy(tmp, map, sizeof(tmp));
		int res = 0;
		for (register int i = 0; i < N; i++) {
			//cout << match[i] << " ";
			if (match[i] == 1) {
				res++;
				for (register int k = 0; k < 5; k++) {
					int nextRow = 0 + dRow[k];
					int nextCol = i + dCol[k];

					if (range(nextRow, nextCol))continue;
					if (tmp[nextRow][nextCol] == 1) tmp[nextRow][nextCol] = 0;
					else tmp[nextRow][nextCol] = 1;
				}
			}
		}
		go(tmp, res);
		return;
	} 
	match[idx] = 0;
	Dfs(idx + 1);
	match[idx] = 1;
	Dfs(idx + 1);
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	minValue = INF;
	Dfs(0);
	if (minValue != INF) cout << minValue << "\n";
	else cout << "-1" << "\n";
}