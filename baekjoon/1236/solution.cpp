#include <iostream>
#define INF 987654321
#define MAX 51
using namespace std;
int N, M;
char map[MAX][MAX];
bool xx[MAX];
bool yy[MAX];
inline int min(int a, int b) {
	return a > b ? b : a;
}
inline int max(int a, int b) {
	return a > b ? a : b;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> map[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//이미 경비원이 있는 곳 체크
			if (map[i][j] == 'X') {
				xx[i] = 1;
				yy[j] = 1;
			}
		}
	}
	//print();
	int row_check = 0;
	int col_check = 0;
	for (int i = 0; i < N; i++) {
		if (!xx[i]) {
			col_check++;
		}
	}
	for (int j = 0; j < M; j++) {
		if (!yy[j]) {
			row_check++;
		}
	}
	cout << max(row_check, col_check) << "\n";
}