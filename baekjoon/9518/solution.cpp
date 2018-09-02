#include <iostream>
#include <string.h>
#include <vector>
#define MAX 51
using namespace std;
int R, S;
char map[MAX][MAX];
const int dRow[] = {-1, 0, 1, 0, 1, 1, -1, -1 };
const int dCol[] = {0, -1, 0, 1, 1, -1, 1, -1 };
inline bool range(int r, int c) {
	if (r < 0 || c < 0 || r > R - 1 || c > S - 1) return true;
	return false;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
inline int handshake() {
	//memset(visit, false, sizeof(visit));
	int ret = 0;
	for (register int i = 0; i < R; i++) {
		for (register int j = 0; j < S; j++) {
			if (map[i][j] == 'o') {
				for (register int k = 0; k < 8; k++) {
					int nextRow = i + dRow[k];
					int nextCol = j + dCol[k];

					if (range(nextRow, nextCol)) continue;
					//if (visit[nextRow][nextCol][k]) continue;
					if (map[nextRow][nextCol] == 'o') {
						ret++;
						//visit[nextRow][nextCol][]
					}
					
				}
			}
		}
	}
	return ret/2;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> S;
	for (int i = 0; i < R; i++) cin >> map[i];
	int maxValue = 0;

	bool flag = false;
	for (register int i = 0; i < R; i++) {
		for (register int j = 0; j < S; j++) {
			if (map[i][j] == '.') {
				flag = true;
				//ºóÄ­ÀÌ ÇÏ³ª¶óµµ ÀÖÀ¸¸é
				map[i][j] = 'o';//backtracking
				//print();
				int temp = handshake();
				maxValue = max(maxValue, temp);
				map[i][j] = '.';
			}
			
		}
	}
	if (flag) {
		cout << maxValue << "\n";
	}
	else {
		cout << handshake() << "\n";
	}
	
}