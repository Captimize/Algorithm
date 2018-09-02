#include <iostream>
#define MAX 16
#define ll unsigned long long
using namespace std;
ll map[MAX][MAX];
int N, M ,K;
int end_row, end_col;
int start_row, start_col;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	start_row = 1;
	start_col = 1;
	int pos = 0;
	if (K == pos) {
		end_row = 1;
		end_col = 1;
	}
	else {
		for (register int i = 1; i <= N; i++) {
			for (register int j = 1; j <= M; j++) {
				pos++;
				if (pos == K) {
					end_row = i;
					end_col = j;
				}
			}
		}
	}
	
	
	map[start_row][start_col] = 1;
	for (register int i = start_row; i <= end_row; i++) {
		for (register int j = start_col; j <= end_col; j++) {
			map[i][j] += (map[i - 1][j]  + map[i][j-1]);
		}
	}

	start_row = end_row;
	start_col = end_col;
	end_row = N;
	end_col = M;
	for (register int i = start_row; i <= end_row; i++) {
		for (register int j = start_col; j <= end_col; j++) {
			if (i == start_row && j == start_col) continue;
			map[i][j] += (map[i - 1][j] + map[i][j - 1]);
		}
	}
	cout << map[N][M] << "\n";
}