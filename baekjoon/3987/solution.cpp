#include <iostream>
#include <string.h>
#define MAX 501
using namespace std;
int N, M , s, e;
char map[MAX][MAX];

//U, R, D, L
const int dRow[] = {-1, 0, 1, 0};
const int dCol[] = {0, 1, 0, -1};

inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > N - 1 || c > M - 1) return true;
	return false;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (register int i = 0; i < N; i++) {
		cin >> map[i];
	}
	cin >> s >> e;
	s--, e--;
	int maxValue = 0;
	int maxDiection = -1;
	for (int j = 0; j < 4; j++) {
		int row = s, col = e;
		int res = 0;
		int direction = j;
		bool cycle[MAX][MAX][4] = { false, };
		while (1) {
			res++;
			int nextRow = row + dRow[direction];
			int nextCol = col + dCol[direction];

			if (range(nextRow, nextCol)) break;
			if (map[nextRow][nextCol] == 'C') break;
			if (cycle[nextRow][nextCol][direction]) {
				cout << "URDL"[j] << "\n";
				cout << "Voyager" << "\n";
				return 0;
			}
			if (map[nextRow][nextCol] == '/') {
				if (direction == 0) {
					direction = 1;
				}
				else if (direction == 1) {
					direction = 0;
				}
				else if (direction == 2) {
					direction = 3;
				}
				else if (direction == 3) {
					direction = 2;
				}
			}
			if (map[nextRow][nextCol] == '\\') {
				if (direction == 0) {
					direction = 3;
				}
				else if (direction == 1) {
					direction = 2;
				}
				else if (direction == 2) {
					direction = 1;
				}
				else if (direction == 3) {
					direction = 0;
				}
			}
			cycle[nextRow][nextCol][direction] = 1;
			row = nextRow; col = nextCol;
		}
		if (maxValue < res) {
			maxValue = res;
			maxDiection = j;
		}
	}
	cout << "URDL"[maxDiection] << "\n";
	cout << maxValue << "\n";
}